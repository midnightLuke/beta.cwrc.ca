<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */
?>

<?php foreach ($rows as $id => $row): ?>
    <li class="leaf <?php print $classes_array[$id]; ?>"><?php print $row; ?></li>
<?php endforeach; ?>
