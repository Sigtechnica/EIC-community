<?php

/**
 * @file
 * Display a node in "Activity stream" view mode.
 *
 * @see node.tpl.php
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
      print $description;
    ?>
  </div>
  <div class="row">
    <?php print $download_link; ?>
  </div>
  <div class="row">
    <?php print t('Filetype: @filetype | Filesize: @filesize', array('@filetype' => $type, '@filesize' => $file_size)); ?>
  </div>

</div>
