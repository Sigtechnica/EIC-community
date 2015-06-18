<?php
/**
 * @file
 * Custom Display Suite function fields.
 */

/**
 * DS function field.
 *
 * Renders a link to the group the current group node belongs to.
 *
 * @param array $field
 *   Field settings and information about the entity it’s being rendered on.
 *
 * @return mixed
 *   A string with a HTML link to the node's group or NULL if not a group node.
 */
function theme_c4m_field_og_group(array $field) {
  if (empty($field['entity'])) {
    return;
  }

  // Don't show this field in a group context.
  $context = og_context();
  if ($context) {
    return;
  }

  // Only show this field for group node types.
  $entity = $field['entity'];
  if (!og_is_group_content_type('node', $entity->type)) {
    return;
  }

  // Get group node.
  $groups = og_get_entity_groups('node', $entity);

  // Only show this field for group nodes.
  if (!isset($groups['node'])) {
    return;
  }

  $group_nid = array_pop($groups['node']);
  $group = node_load($group_nid);

  $uri_info = entity_uri('node', $group);

  c4m_og_purl_alter_uri_info_purl_dashboard($uri_info);

  // Return a link to the group dashboard.
  return l($group->title, $uri_info['path'], $uri_info['options']);
}