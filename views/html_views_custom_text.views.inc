<?php
/**
 * @file
 *  Provides views data for the HTML Custom Field Views handler.
 */

 /**
  * Implements hook_views_data_alter().
  */
function html_views_custom_text_views_data_alter(&$data) {
  $data['views']['html_custom_text'] = array(
    'title' => t('HTML custom text'),
    'help' => t('Provide a custom text field that allows whitelisted HTML tags.'),
    'field' => array(
      'handler' => 'HtmlViewCustomTextFieldHander',
    ),
  );
}
