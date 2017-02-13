<li class="navbar-right nav-user-menu">
  <a class="dropdown-toggle" href="#" role="button"><span class="user-menu"><?php print t("User Menu"); ?></span></a>
  <?php $content['#theme_wrappers'] = NULL; ?>
  <ul class="dropdown-menu">
    <?php print drupal_render($content); ?>
  </ul>
</li>
