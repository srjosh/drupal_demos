<?php
/**
 * @file
 * demo_views_filter_features.features.inc
 */

/**
 * Implements hook_views_api().
 */
function demo_views_filter_features_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function demo_views_filter_features_node_info() {
  $items = array(
    'page' => array(
      'name' => t('page'),
      'base' => 'node_content',
      'description' => t('Content page for demos'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
