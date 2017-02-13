<?php
  // This will stop it from wrapping the items in a <ul> of their own
  $content['#theme_wrappers'] = NULL;
  foreach ($content as $key => $value) {
    if (is_array($content[$key]) && array_key_exists('#attributes', $content[$key])) {
      $content[$key]['#attributes']['class'] = array('navbar-left', 'main-menu-link');
    }
  }
?>
<?php print drupal_render($content); ?>
