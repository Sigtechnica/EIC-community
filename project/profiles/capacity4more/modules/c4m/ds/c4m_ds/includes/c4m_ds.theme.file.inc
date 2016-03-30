<?php
/**
 * @file
 * Custom theme function to theme the file field.
 */

/**
 * Copy of theme_file_entity_download_link().
 *
 * Linking to the file download URL, but customized for C4M.
 *
 * @see theme_file_entity_download_link()
 */
function theme_c4m_ds_formatter_link_and_size($variables) {
  $output = '';
  if ('file' != $variables['entity_type']
    || empty($variables['entity']->fid)
  ) {
    return $output;
  }
  else {
    $file = $variables['entity'];
  }

  $uri = file_entity_download_uri($file);

  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $uri['options']['attributes']['type'] = $file->filemime . '; length=' .
    $file->filesize;

  // Provide the default link text.
  if (!isset($variables['text'])) {
    $variables['text'] = t('Download');
  }

  // Perform unsanitized token replacement if $uri['options']['html'] is empty
  // since then l() will escape the link text.
  $variables['text'] = token_replace(
    $variables['text'], array('file' => $file),
    array('clear' => TRUE, 'sanitize' => !empty($uri['options']['html']))
  );

  // Download link.
  $tag['element'] = array(
    '#tag'        => 'span',
    '#attributes' => array(
      'class' => "download-link",
    ),
    '#value'      => l($variables['text'], $uri['path'], $uri['options']),
  );
  $inner = theme_html_tag($tag);

  // Filesize.
  $tag['element'] = array(
    '#tag'        => 'span',
    '#attributes' => array(
      'class' => "file-size",
    ),
    '#value'      => t('Size') . ': ' . format_size($file->filesize),
  );
  $inner .= '<br/>' . theme_html_tag($tag);

  $tag['element'] = array(
    '#tag'        => 'div',
    '#attributes' => array(
      'class' => "download-link-icon",
    ),
    '#value'      => $inner,
  );
  $output .= theme_html_tag($tag);

  return $output;
}

/**
 * DS function field.
 *
 * Render preview of document
 *
 * @param array $field
 *   The field definition.
 *
 * @return string
 *   The rendered version.
 */
function theme_c4m_ds_document_preview(array $field) {
  $output = '';

  if (isset($field['entity'])) {
    $entity = $field['entity'];

    $tag['element'] = array(
      '#tag'   => 'i',
      '#value' => 'To be replaced by document preview.',
    );
    $output .= theme_html_tag($tag);
  }
  return $output;
}