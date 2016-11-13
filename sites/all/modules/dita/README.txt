Overview
========
DITA Integration for Drupal 6 is an experimental module, wich let's you create, manage and convert Dita topics and maps from inside a drupal site. Note that the project is in pre-alpha state and it will need some work before it's fit for production environments.

If you have issues installing or using the module, feel free to send me a mail: tamas@pronovix.com or denes@pronovix.com

The project was sponsored by ProNovix.

---

The Drupal 7 version has been made by Erno Kaikkonen at Exove Ltd. Questions and 
comments about the 7 version should be sent to firebird@drupal.org. Note that 
the simple_dita_forms and feeds_dita_fetcher_parser modules have not been ported
yet.

The module was ported for Drupal 7 with somewhat different needs than the 
original Drupal 6 version. Therefore the functionality is also somewhat 
different. The Drupal 7 version of the module is created for importing DITA
documents into a Drupal system, so that documentation created in DITA format can
be used on the web through a Drupal site. The DITA topic files become nodes like
before, but imported DITA maps are turned into Taxonomy terms, so that the 
document hierarchy can be easily be turned into a Taxonomy menu.

Most of the Drupal 6 version's functionality is still there, although at this
point un-ported and un-tested.

- firebird@drupal.org


DITA Integration for Drupal 6: Install
======================================

1. Download the module and it's dependencies. Install the dependencies using their respective documentation.
2. Download and install drush (It's very well documented on the internet)
3. Download and install DITA Open Toolkit.
    -You can download DITA Open Toolkit from sourceforge: http://sourceforge.net/projects/dita-ot/
   - To get more information about the install process you can use the offical user guide: http://dita-ot.sourceforge.net/doc/ot-userguide/xhtml/index.html but on a linux systems you probably only have to extract it to somewhere in your home directory. Note that the DITA Integration module DOESN'T require you to run startcmd.sh.
4. Enable the DITA Integration module
5. Configure the DITA Integration module on it's settings page: content managament > DITA settings (at admin/content/dita)
    -DITA OT directory: That's the absolute path of DITA Open Toolkit on your system . e.g.: /home/user/DITA-OT1.5.1 Drupal needs permission to access this directory
    -Output directory: That's the absolute path of the output directory, your output files will be created there. It should be in the files/ directory to be able to download your files online. e.g.: /var/www/dita/sites/default/files/ditaout Drupal and DITA OT will need permission to access and write this directory
    -Output dir in the basepath: That's the relative url (from drupal base) of the DITA Integration output directory. e.g.: sites/default/files/ditaout
    -DITA basedir: That's a path to a temp directory for DITA Integration. e.g.: /tmp/ditabase Drupal will need permission to access and write this directory. DITA OT will need permission to read this directory.
6. To make the exporting work automatically, you can add the command: 'drush dita-convert-scheduled --continue > /dev/null' to your crontab. You can also skip this step and instead run the command manually from the command line interface.

DITA Integration for Drupal 7: Install
======================================

1) Before beginning, make sure your private file system path is set. 

Failing to do this will cause a fatal error after installation, and you'll have
to set it anyway after that:

- Go to Admin -> Configuration -> File system
- Set your "Default download method" to "private" if it isn't already.
- Set the "Private file system path" to some directory on your server 
(preferrably outside webroot) where Drupal has write permissions.

2. Download and install drush (It's very well documented on the internet)

3. Download the module and it's dependencies. Install the dependencies using 
their respective documentation. The list of modules needed for DITA and
DITAmap integration is as follows:

dita, ctools, graphmind_service, services, amfserver, entity, i18n_taxonomy, i18n_string, locale, i18n, variable, i18n_translation, taxonomy_menu, ditamap_import

3. Download and install DITA Open Toolkit.
    -You can download DITA Open Toolkit from sourceforge: http://sourceforge.net/projects/dita-ot/
   - To get more information about the install process you can use the offical user guide: http://dita-ot.sourceforge.net/doc/ot-userguide/xhtml/index.html but on a linux systems you probably only have to extract it to somewhere in your home directory. Note that the DITA Integration module DOESN'T require you to run startcmd.sh.

4. Download and install the Zend library.

5. Enable the DITA Integration module

Some issue causes the enabling to fail if you try "drush en ditamap_import".

Installing i18n, i18n_taxonomy, and then ditamap_import works.

6. Configure the DITA Integration module on it's settings page: content managament > DITA settings (at admin/content/dita)
    -DITA OT directory: That's the absolute path of DITA Open Toolkit on your system . e.g.: /home/user/DITA-OT1.5.1 . Drupal needs permission to access this directory
    TODO check the rest:
    -Output directory: That's the absolute path of the output directory, your output files will be created there. It should be in the files/ directory to be able to download your files online. e.g.: /var/www/dita/sites/default/files/ditaout Drupal and DITA OT will need permission to access and write this directory
    -Output dir in the basepath: That's the relative url (from drupal base) of the DITA Integration output directory. e.g.: sites/default/files/ditaout
    -DITA basedir: That's a path to a temp directory for DITA Integration. e.g.: /tmp/ditabase Drupal will need permission to access and write this directory. DITA OT will need permission to read this directory.


DITA Integration: Usage
=======================

For Drupal 7:

You can upload DITA topics (concepts,tasks,references) at the menu point Upload DITA Document. The DITA topic should be valid, and should contain a doctype reference - however the dtd file doesn't have to be a valid dtd file, all documents will be treated as a dita v1.2/cd04 dita topic. The uploaded DITA topics will become DITA document nodes. You can edit them as any other nodes.

The imported DITA XML content is saved in a field of its own in the DITA document nodes, so that the original document content is kept on the Drupal side. The XML is run through a parser that turns the XML into XHTML content. This content is what the site visitors will see.

The following applies to D6 version only, as the graphmind functionality has not been ported to D7:

You can use the module graphmind to make maps for your dita topics. Note that this feature requires you to follow a couple of conventions (that haven't been hard coded yet in the user interface) in order for your dita map to be valid:
  -When you start graphmind with a new map, you have one element. That's the root element. The title of the root element will be the title of your dita map. 
  -You can create children for a mindmap node if you click on the green plus that appears when you hover over a node, or from the context menu that appears when you right click on a node. You can also create mindmap nodes that reference a Drupal item from the context menu, either by adding them 1 by 1 with their unique ID or through a database query using the views list option.
  -The children of the root element for a dita map, the first-level elements should be all mindmap nodes (that don't reference a Drupal item). In the dita map, the titles of the nodes will become the navtitles of the topicheads. If you are not familiar with dita, you can imagine them as the main chapters in a map. 
  -On the second level (the children of the first-level elements), you should put your dita documents, wich you have created on the site before. You can use Graphmind's "add drupal item" or "add views list" feature for this. 
  -When you're finished, don't forget to save your map!
  
You can check your map at Ditamap View tab, clicking on 'no reltable'.

Relation Tables
===============
The following applies to D6 version only:

If you're familiar with Dita, you may have heard of the dita relation tables. Drupal dita automatically generates relation tables for your ditamaps based on the keywords that your topics have been tagged with. Go to Content managament/Taxanomy. Add a vocabulary, and assign it to the 'DITA Document' content type. Now, you can add keywords for your DITA Documents. If you go to your map's Ditamap view, you can see that you can select one or more vocabularies. Each vocabulary will be converted to a relation table, with a row for each term and a column for the different content types (this is still hard coded, later this could be connected dynamically with the topichead structure that you have chosen).

Exporting
=========
The following applies to D6 version only:

When you have finished building your documents and map, go to your map's  "Export DITA Map" tab. There you can schedule the exporting and conversion of your map. DITA Integration will use DITA Open Toolkit for the converting. Available export formats are pdf2,xhtml,htmlhelp,tar.gz,zip. The first three should be obvious. If you select one of the last two options, the DITA Open Toolkit will not run, but instead generate an archive file that you can download to get an export of your dita map, and the topics that were referenced in it.

To see your export results you'll need to run the Open Toolkit after scheduling a conversion. The following console command will do the trick: drush dita-convert-scheduled. The following switches are available:
  --continue: Redo all conversions.
  --max: Maximum number of converts.
  --dry-run: Print the generated commands.
  
  After you running the command, your scheduled jobs will be exported. You can download them from the history tab on the ditamap's export tab.
  
Known issues:
=============
The following applies to D6 version only:

- When you use Graphmind to make a dita map, you have to follow specific rules (wich are mentioned above), to make a valid (convertable by open toolkit) dita map.
- Occasionally you'll see warnings
- The module uses online dtd references, wich makes some actions slow.
  
Submodules
==========

DITA map import
===============
For Drupal 7 only:

This module allows you to upload DITA map files. The imported document structure is turned into a taxonomy hierarchy in a selected vocabulary. The system supports uploading documents structures as multiple files. Just make sure to upload the top level maps first, so that the lower level maps can find their parents when importing.

The main module's DITA topic file importer can automatically add the correct taxonomy term to the imported DITA document node. You'll just have to tell the importer which vocabulary to use.

Feeds Dita Fetcher and Parser plugin
====================================
The following applies to D6 version only:

This feeds plugin provides a directory fetcher and a dita file parser for Feeds. The directory fetcher will only work together with the DITA parser! The directory fetcher scans a given directory (wich you can set when you create a new feed), and collects all the files from it (and any newly added files later). The dita parser accepts these files, and hands them to the processor as separate items.

Simple Dita Forms
=================
The following applies to D6 version only:

This features-based module provides simple forms to create basic Dita topics online. Currently only Concept and Task doctype are fully implemented.
