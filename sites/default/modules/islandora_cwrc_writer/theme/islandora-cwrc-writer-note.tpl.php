<?php
/**
 * @file
 * Displays a modal dialog CWRC-Writer used for editing notes.
 */
?>
<div id="cwrc_wrapper">
  <div class="cwrc ui-layout-west">
    <div id="westTabs" class="tabs">
      <ul>
        <li><a href="#entities">Entities</a></li>
        <li><a href="#structure">Markup</a></li>
      </ul>
      <div id="westTabsContent" class="ui-layout-content">
      </div>
    </div>
  </div>
  <div id="cwrc_main" class="ui-layout-center">
    <form method="post" action="">
      <textarea id="editor" name="editor" class="tinymce"></textarea>
    </form>
  </div>
</div>
