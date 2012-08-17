<?php
/**
 * @file
 * demo_views_filter_features.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function demo_views_filter_features_taxonomy_default_vocabularies() {
  return array(
    'classification' => array(
      'name' => 'Classification',
      'machine_name' => 'classification',
      'description' => 'classifications for demos',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => 'Tags for demos',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
