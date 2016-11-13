<?php
// $Id$

/**
 * Interface for DITA output plugins.
 */
interface DITAOutputPlugin {

  /**
   * @constructor
   *
   * @param mixed dtid
   *  This parameter can has two types of values:
   *  - Integer, and a dita task will be loaded from the database
   *  - Ditatask object, which will be used as is
   */
  public function __construct($dtid);

  /**
   * Returns the path for of the document.
   *
   * This function is intended to use with the l() function.
   */
  public function getOutputDocumentPath();
}

/**
 * Intermediate class for output plugins.
 *
 * This class has some useful utility functions, in order to
 * eliminate code duplication in the actual output plugins.
 */
abstract class AbstractDITAOutputPlugin implements DITAOutputPlugin {
  protected $task;

  /**
   * {@inheritdoc}
   */
  public function __construct($dtid) {
    $this->task = is_object($dtid) ? $dtid : ditatask_load($dtid);
  }
}

/**
 * Simplified implementation of the AbstractDITAOutputPlugin class.
 */
abstract class SimpleDITAOutputPlugin extends AbstractDITAOutputPlugin {

  /**
   * Returns the extension of the generated file.
   *
   * @return string
   */
  protected abstract function getOutputDocumentExtension();

  /**
   * {@inheritdoc}
   */
  public function getOutputDocumentPath() {
    $webdir = variable_get('dita_web_dir', '');
    $extension = $this->getOutputDocumentExtension();
    return "{$webdir}/{$this->task->prefix}/{$this->task->prefix}{$this->task->nid}.$extension";
  }
}

/**
 * PDF2 output plugin for DITA.
 */
class DITAPDF2OutputPlugin extends AbstractDITAOutputPlugin {

  /**
   * {@inheritdoc}
   */
  public function getOutputDocumentPath() {
    $webdir = variable_get('dita_web_dir', '');
    $node = node_load($this->task->nid);
    return "{$webdir}/{$this->task->prefix}/{$this->task->prefix}{$node->nid}.pdf";
  }
}

/**
 * XHTML output plugin for DITA.
 */
class DITAXHTMLOutputPlugin extends AbstractDITAOutputPlugin {

  /**
   * {@inheritdoc}
   */
  public function getOutputDocumentPath() {
    $webdir = variable_get('dita_web_dir', '');
    return "{$webdir}/{$this->task->prefix}/index.html";
  }
}

/**
 * HTMLHelp output plugin for DITA.
 */
class DITAHTMLHelpOutputPlugin extends SimpleDITAOutputPlugin {

  /**
   * {@inheritdoc}
   */
  protected function getOutputDocumentExtension() {
    return 'hhc';
  }
}

/**
 * ZIP output plugin for DITA.
 */
class DITAZIPOutputPlugin extends SimpleDITAOutputPlugin {

  /**
   * {@inheritdoc}
   */
  protected function getOutputDocumentExtension() {
    return 'zip';
  }
}

/**
 * TGZ output plugin for DITA.
 */
class DITATGZOutputPlugin extends SimpleDITAOutputPlugin {

  /**
   * {@inheritdoc}
   */
  protected function getOutputDocumentExtension() {
    return 'tgz';
  }
}

/**
 * Returns the version number of an installed DITA OT.
 *
 * @param string $dir The absolute path to the DITA OT installation.
 * @return string
 */
function get_dita_ot_version($dir) {
  $dir = rtrim($dir, '/');

  $relnotes = "{$dir}/relnotes.txt";

  if (file_exists($relnotes) && is_readable($relnotes)) {
    $file = file_get_contents($relnotes);

    $matches = array();

    preg_match('/DITA OT release ([0-9\.]*)/', $file, $matches);

    unset($file);

    if (!empty($matches[1])) {
      return $matches[1];
    }
  }

  return NULL;
}

/**
 * Returns the taxonomy vocabulary name from the id.
 *
 * @param int $vids Vocabulary ids.
 * @param string $zerostring Special value for 0 vid.
 * @return string Vocabulary names concatenated.
 */
function dita_taxonomy_vocabulary_name($vids, $zerostring = NULL, $separator = ', ') {
  $cache = &ctools_static(__FUNCTION__, NULL);

  if ($zerostring === NULL) {
    $zerostring = t('No reltable selected.');
  }

  if (!count($vids)) {
    return $zerostring;
  }

  if ($cache === NULL) {
    $cache = array();
    $res = db_query('SELECT vid, name FROM {vocabulary} ORDER BY vid');
    while ($row = db_fetch_object($res)) {
      $cache[$row->vid] = $row->name;
    }
  }

  $ret = array();
  foreach ($vids as $vid) {
    if (isset($cache[$vid])) {
      $ret[] = $cache[$vid];
    }
  }

  return count($ret) ? implode($separator, $ret) : $zerostring;
}

/**
 * Returns all vocabularies by using the dita_taxonomy_vocabulary_name() function.
 *
 * @param string $zerostring
 * @return array
 */
function dita_taxonomy_all_vocabularies() {
  dita_taxonomy_vocabulary_name(array(-1));
  return ctools_static('dita_taxonomy_vocabulary_name', array());
}

/**
 * Loader function for a dita task.
 *
 * @param int $dtid
 * @return stdClass
 */
function ditatask_load($dtid) {
  $cache = &ctools_static(__FUNCTION__, array());

  if (!isset($cache[$dtid])) {
    $cache[$dtid] = db_fetch_object(db_query(
      'SELECT * FROM {dita_task} WHERE dtid = %d', $dtid
    ));
    $cache[$dtid]->vocabularies = array();
    $res = db_query('SELECT vid FROM {dita_task_vocabulary} WHERE dtid = %d', $dtid);
    while ($row = db_fetch_object($res)) {
      $cache[$dtid]->vocabularies[] = $row->vid;
    }
  }

  return $cache[$dtid];
}

/**
 * Returns multiple ditatask objects based on the nid.
 *
 * @param int $nid Node ID
 */
function ditatask_load_multiple_by_nid($nid) {
  $ret = array();

  $res = db_query('SELECT dtid
    FROM {dita_task}
    WHERE nid = %d AND status = 1',
    $nid);
  while ($row = db_fetch_object($res)) {
    $ret[] = $row->dtid;
  }

  return array_map('ditatask_load', $ret);
}

/**
 * Saves a dita task.
 *
 * @param stdClass $ditatask
 * @return bool
 */
function ditatask_save($ditatask) {
  $cache = &ctools_static('ditatask_load', array());
  $update = !empty($ditatask->dtid) && $ditatask->dtid > 0;
  $ret = drupal_write_record('dita_task', $ditatask, $update ? array('dtid') : array());

  if ($ret) {
    $cache[$ditatask->dtid] = $ditatask;
  }

  return $ret;
}

/**
 * Functor class to convert a ditamap.
 */
abstract class DitamapConverter {

  /**
   * Location of the ditamap file.
   *
   * This must be an absolute path.
   *
   * @var string
   */
  protected $ditamap;

  /**
   * The output format type.
   *
   * See the 'dita-list-output-types commands'.
   *
   * @var string
   */
  public $type = '';

  /**
   * Absolute path of the working directory.
   *
   * @var string
   */
  public $dir = '.';

  /**
   * Absolute path of the output dir.
   *
   * @var string
   */
  public $output_dir = '.';

  /**
   * Absolute path of the document basedir.
   *
   * @var string
   */
  public $basedir = '.';

  /**
   * Shell status code.
   *
   * @var int
   */
  public $shell_status = 0;

  /**
   * @constructor
   */
  final public function __construct($ditamap) {
    $this->ditamap = $ditamap;
  }

  /**
   * Invokes the conversion.
   *
   * @return bool
   */
  public function __invoke() {
    $current_dir = getcwd();

    $this->preInvoke();

    $command = $this->getConvertCommand();

    $retval = 0;
    system($command, $retval);

    $this->shell_status = $retval;

    chdir($current_dir);

    if ($retval != 0) {
      // command failed, error handling takes place here
      return FALSE;
    }

    return TRUE;
  }

  /**
   * Returns the conversion command.
   *
   * @return string
   */
  public abstract function getConvertCommand();

  /**
   * This function is called just before this functor is invoked.
   */
  public function preInvoke() {
    if ($this->dir != '.') {
      chdir($this->dir);
    }
  }

  /**
   * Returns the variable name of the working directory.
   *
   * This name will be a key in the {variable} table.
   */
  public static abstract function getVariableName();

  /**
   * Returns the name of the working directory.
   *
   * This name will be displayed on the admin form.
   */
  public static abstract function getWorkingDirectoryName();

  /**
   * Validator function for the working directory.
   *
   * @param string $path
   * @return boolean
   */
  public static function validateWorkingDirectory($path) {
    return file_exists($path) && is_readable($path);
  }
}

class OTDitamapConverter extends DitamapConverter {

  /**
   * {@inheritdoc}
   */
  public static function validateWorkingDirectory($path) {
    return (bool) get_dita_ot_version($path);
  }

  /**
   * {@inheritdoc}
   */
  public static function getVariableName() {
    return 'dita_ot_dir';
  }

  /**
   * {@inheritdoc}
   */
  public static function getWorkingDirectoryName() {
    return t('DITA OT directory');
  }

  /**
   * {@inheritdoc}
   */
  public function getConvertCommand() {
    // ant parameter mapping
    $ant_parameters = array(
      'args.input' => $this->ditamap,
      'output.dir' => $this->output_dir,
      'transtype' => $this->type,
    );

    // PATH overriding, ported from startcmd.sh
    $path = (string) getenv('PATH');
    $path .= ":{$this->dir}/tools/ant/bin";

    // CLASSPATH overriding, ported from startcmd.sh
    $classpath = (string) getenv('CLASSPATH');
    $cp = array(
      '/lib',
      '/lib/dost.jar',
      '/lib/resolver.jar',
      '/lib/icu4j.jar',
      '/lib/saxon/saxon9.jar',
      '/lib/saxon/saxon9-dom.jar',
      '/lib/saxon/saxon9-dom4j.jar',
      '/lib/saxon/saxon9-jdom.jar',
      '/lib/saxon/saxon9-s9api.jar',
      '/lib/saxon/saxon9-sql.jar',
      '/lib/saxon/saxon9-xom.jar',
      '/lib/saxon/saxon9-xpath.jar',
      '/lib/saxon/saxon9-xqj.jar',
    );
    foreach ($cp as $p) {
      $classpath .= ":{$this->dir}{$p}";
    }

    $command = "PATH='{$path}' CLASSPATH='{$classpath}' ant";

    // some misc options, ported from startcmd.sh
    $command .= ' -Djavax.xml.transform.TransformerFactory=net.sf.saxon.TransformerFactoryImpl';

    // adding ant parameters
    foreach ($ant_parameters as $p => $v) {
      $command .= " -D{$p}='{$v}'";
    }

    return $command;
  }
}

class ArchiveDitamapConverter extends DitamapConverter {

  /**
   * {@inheritdoc}
   */
  public function getConvertCommand() {
    switch ($this->type) {
      case 'tgz':
        $command = 'tar -czf';
        $extension = 'tgz';
        break;

      case 'zip':
      default:
        $command = 'zip -9r';
        $extension = 'zip';
        break;
    }

    $command = "mkdir -p {$this->output_dir} && " . $command;

    $ditamap = basename($this->ditamap, '.ditamap');
    $arhivename = "{$this->output_dir}{$ditamap}.{$extension}";

    $command .= " $arhivename";
    $filelist = array();
    foreach (glob('*') as $filename) {
      $filename = rtrim($filename, '/.');
      if (!empty($filename)) {
        $filelist[] = $filename;
      }
    }

    $command .= ' ' . implode(' ', array_unique($filelist));

    return $command;
  }

  /**
   * {@inheritdoc}
   */
  public function preInvoke() {
    $this->dir = $this->basedir;
    parent::preInvoke();
  }

  /**
   * {@inheritdoc}
   */
  public static function validateWorkingDirectory($path) {
    return TRUE;
  }

  /**
   * {@inheritdoc}
   */
  public static function getVariableName() {
    return NULL;
  }

  /**
   * {@inheritdoc}
   */
  public static function getWorkingDirectoryName() {
    return NULL;
  }
}
