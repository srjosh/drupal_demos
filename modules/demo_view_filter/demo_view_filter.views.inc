<?php
/**
 * @file
 * Views functionality.
 */

/**
 * Implements hook_views_data_alter().
 */
function demo_view_filter_views_data_alter(&$data) {

  // field_data_field_tags is data/tag relation table name
  // field_tags_tid is field name - tag id in data/tag relation table

  $data['field_data_field_tags']['table']['group'] = t('Tags');
  $data['field_data_field_tags']['field_tags_tid'] = array(
    'title' => t('Tags'),
    'help' => t('Dropdown list of applicable tags, as a filter'), 
    'filter' => array(
      'handler' => 'demo_view_filter_tag_filter'    // Class name, below
    ),
  );
}

/**
 * Simple filter to handle dropdown of available tags in node list
 *
 * @ingroup views_filter_handlers
 */
class demo_view_filter_tag_filter extends views_handler_filter_in_operator {
  /**
   * Provide value options for the tag filter based on available tags. - 
   * overrides get_value_options() from views_handler_filter_in_operator class
   */
  function get_value_options() {
    //  return if already set
    if (isset($this->value_options)) {
      return;
    }

    //  limit by nodes associated with this tag term.
    $this->value_options = $tag_options = array();

    if (isset($this->view->args)) {
      $tid = $this->view->args[0];    //  first argument in view - in this case, the classification id
      if (isset($tid)) {
      
      
    /*  This section builds a join query between classification and tags, 
        to get the list of tag ids attached to nodes in the current classification.  */
      
        $query = db_select('field_data_field_tags', 'ft');  
        $query->fields('ft', array('field_tags_tid'));
        $query->join('field_data_field_classification', 'fc', 'fc.revision_id = ft.revision_id');
        $query->condition('fc.field_classification_tid', $tid);
        $query->distinct();

        $result = $query->execute();
        $ids = $result->fetchAll();
        
        //  Loop through list of tag terms, and assign to an options array, which is returned
        //  for the form element being built by views_handler_filter_in_operator.
        foreach ($ids as $key => $val) {
          $term = taxonomy_term_load($val->field_tags_tid);
          if (isset($term)) {
            $tag_options[$term->tid] = $term->name;
          }
        }
      }
    }

    $this->value_options = $tag_options;
  }

}