<?php

/**
 * @file
 * Displays an EAP.
 */
?>
<div class="<?php print $classes; ?>">

  <div class="row">

    <?php
// "Information" goes on the left. ?>
    <div class="left">
      <h2><?php print t('Information'); ?></h2>

      <div class="information-left">


      <?php if (!empty($image) || !empty($summary)) { ?>
          <header class="header">
            <?php if (!empty($image)) { ?>
              <div class="object-image">
                <?php print render($image); ?>
              </div>
            <?php } ?>
              <?php if (!empty($summary)) { ?>
                <div class="object-summary">
                  <?php print render($summary); ?>
                </div>
              <?php } ?>
          </header>
      <?php } ?>

      <div class="about-info">
      <?php
// "Record" Information. ?>
      <?php if (count($info_record) > 0) { ?>
        <h3><?php print t('About'); ?></h3>
        <?php foreach ($info_record as $info) { ?>
          <?php print render($info); ?> 
        <?php } ?>
      <?php } ?>
      </div>

      <?php
// "Identity" Information. ?>
      <?php if (count($info_identity) > 0) { ?>
        <h3><?php print t('Identity'); ?></h3>
        <?php foreach ($info_identity as $info) { ?>
          <?php print render($info); ?>
        <?php } ?>
      <?php } ?>
      </div>

      <div class="information-right">
      <?php
// "Description" Information. ?>
      <?php if (count($info_description) > 0) { ?>
        <h3><?php print t('Description'); ?></h3>
        <?php foreach ($info_description as $info) { ?>
          <?php print render($info); ?>
        <?php } ?>
      <?php } ?>
    </div></div>

    <?php
// "Associations" goes on the right. ?>
    <div class="right">
      <?php if (!empty($associations_person) || !empty($associations_place) || !empty($associations_organization)) { ?>
        <h2><?php print t('Associations'); ?></h2>
      <?php } ?>

      <?php if (!empty($associations_person)) { ?>
      <div id="association-people" class="associations-collapsible block">
        <h2 class="collapsiblock <?php if(count($associations_person['#items']) > 5) {
          print " collapsiblockCollapsed";
       }
        ?>">
          <a href="#association-people" role="link">
            <?php print t('People'); ?>
            <span class="badge"><?php print count($associations_person['#items']); ?></span>
          </a>
        </h2>
        <div class="content" <?php

        if (count($associations_person['#items']) > 5) {
          print "style=\"display:none;\"";
        }

        ?>>
          <?php print render($associations_person); ?>
        </div>
      </div>
      <?php } ?>

      <?php if (!empty($associations_place)) { ?>
      <div id="association-places" class="associations-collapsible block">
        <h2 class="collapsiblock <?php if(count($associations_place['#items']) > 5) {
          print " collapsiblockCollapsed";
       }
        ?>">
          <a href="#association-places" role="link">
            <?php print t('Places'); ?>
            <span class="badge"><?php print count($associations_place['#items']); ?></span>
          </a>
        </h2>
        <div class="content" <?php

        if (count($associations_place['#items']) > 5) {
          print "style=\"display:none;\"";
        }

        ?>>
          <?php print render($associations_place); ?>
        </div>
      </div>
      <?php } ?>

      <?php if (!empty($associations_organization)) { ?>
      <div id="association-orgs" class="associations-collapsible block">
        <h2 class="collapsiblock <?php if(count($associations_organization['#items']) > 5) {
          print " collapsiblockCollapsed";
       }
        ?>">
          <a href="#association-orgs" role="link">
            <?php print t('Organizations'); ?>
            <span class="badge"><?php print count($associations_organization['#items']); ?></span>
          </a>
        </h2>
        <div class="content" <?php

        if (count($associations_organization['#items']) > 5) {
          print "style=\"display:none;\"";
        }

        ?>>
          <?php print render($associations_organization); ?>
        </div>
      </div>
      <?php } ?>

    </div>
  </div>
  <?php if (count($materials) > 0) { ?>
    <div class="row">
      <div class="materials tabs">
        <ul class="material-tabs">
          <?php foreach ($materials as $material) { ?>
            <li class="material-tab-row"><a href="#material-<?php print $material['type'] ?>"><?php print $material['label'] ?></a><span class="badge"><?php print count($material['elements']['#items']); ?></span></li>
          <?php } ?>
        </ul>
        <?php foreach ($materials as $material) { ?>
          <div class="material-tab-inner-row" id="material-<?php print $material['type']; ?>">
            <?php print render($material['elements']); ?>
          </div>
        <?php } ?>
      </div>
    </div>
  <?php } ?>
</div>
