<?php

/**
 * @file
 * The default object view.
 *
 * This is a template for objects that do not have a module to registered to
 * build their display.
 *
 * islandora_object is a fedora tuque Object
 *    $object->label             - The label for this object.
 *    $object->id                - The identifier of the object.
 *    $object->state             - The state of this object.
 *    $object->createdDate       - The date the object was ingested.
 *    $object->lastModifiedDate  - The date teh object was last mofified.
 *
 * to get the contents of a datastream
 *    $object['dsid']->content
 *
 * to test if a datastream exists isset($object['dsid'])
 *
 * to iterate over datastreams:
 * foreach ($object as $ds) {
 *   $ds->label, etc
 * }
 *
 * each $ds in the above loop has the following properties:
 *    $ds->label             - The label for this datastream.
 *    $ds->id                - The identifier of the datastream.
 *    $ds->controlGroup      - The control group of the datastream. This
 *        property is read-only. This will return one of: "X", "M", "R", or "E".
 *    $ds->versionable       -  This defines if the datastream will be versioned
 *        or not. This is boolean.
 *    $ds->state             -  The state of the datastream. This will be one
 *        of: "A", "I", "D".
 *    $ds->mimetype          - The mimetype of the datastrem.
 *    $ds->format            - The format of the datastream
 *    $ds->size              - The size of the datastream
 *    $ds->checksum          - The checksum of the datastream
 *    $ds->checksumType      - The type of checksum for the datastream.
 *    $ds->createdDate->format("Y-m-d") - The created date with an option to use
 *                                        a format of your choice
 *    $ds->content           - The content of the datastream
 *    $ds->url               - The URL. This is only valid for R and E
 *                             datastreams.
 *
 * $dublin_core is a DublinCore object
 * which is an array of elements, such as dc.title
 * and each element has an array of values.
 * dc.title can have none, one or many titles
 * this is the case for all dc elements.
 *
 *
 *
 * we can get a list of datastreams by doing
 * foreach ($object as $ds) {
 * do something here
 * }
 */
?>
<div class="islandora-object islandora">
  <?php if (isset($variables['islandora_thumbnail_url'])): ?>
    <dl class="islandora-object-tn">
      <dt>
        <img src="<?php print $variables['islandora_thumbnail_url']; ?>"/>
      </dt>
    </dl>
  <?php endif; ?>
  <div class="islandora-default-metadata">
    <?php print $description; ?>
    <?php print $metadata; ?>
  </div>
</div>
