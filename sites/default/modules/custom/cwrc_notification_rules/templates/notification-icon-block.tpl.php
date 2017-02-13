<?php

/**
 * @file
 * Displays a notification icon list element.
 */
?>
<li class="navbar-right nav-notifications">
  <a href="<?php print url('messages'); ?>">
    <span class="badge notification-count<?php if ($unread_count <= 0) {echo " notification-count-none";
   } ?>"><?php print $unread_count; ?></span>
    <span class="notification-icon"><?php print $unread_message; ?></span>
  </a>
</li>
