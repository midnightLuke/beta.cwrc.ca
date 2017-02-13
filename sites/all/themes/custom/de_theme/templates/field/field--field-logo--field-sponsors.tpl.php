<?php

if (isset($element['#object']->field_link) && !empty($element['#object']->field_link[LANGUAGE_NONE][0]['url']))
  print l(render($items[0]), $element['#object']->field_link[LANGUAGE_NONE][0]['url'], array('html' => TRUE));
else print render($items[0]);

?>
