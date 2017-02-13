<li class="navbar-right nav-help">
  <a class="dropdown-toggle" href="#" role="button"><span class="nav-help-icon">&nbsp;</span></a>
  <ul class="help-dropdown dropdown-menu">
    <?php if ($content != "&nbsp;" && !empty(trim($content))): ?>
    <li><?php print $content ?></li>
    <?php endif; ?>
    <li><?php print l(t('Report a Bug'), 'node/13');?></li>
  </ul>
</li>