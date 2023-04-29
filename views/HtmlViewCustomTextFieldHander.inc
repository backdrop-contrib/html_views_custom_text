<?php
/**
 * @file
 *  Defines the HTML Custom Text Views Field handler.
 */

/**
 * Provides a Custom Text views handler that allows whitelisted HTML tags.
 */
class HtmlViewCustomTextFieldHander extends views_handler_field_custom {

  /** 
   * {@inheritdoc}
   */
  public function option_definition() {
    $options = parent::option_definition();

    $options['allowed_html'] = array(
      'default' => '<a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd>',
    );
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    if (user_access('administer html custom text field')) {
      $form['allowed_html'] = array(
        '#type' => 'textarea',
        '#title' => t('Allowed HTML tags'),
        '#description' => t('Enter tags surrounded by < >. Separate tags with spaces.'),
        '#default_value' => $this->options['allowed_html'],
        '#maxlength' => 1024,
        '#description' => t('A list of HTML tags that can be used in the custom text.'),
      );  
    }
    else {
      $form['allowed_html_fieldset'] = array(
        '#type' => 'fieldset',
        '#title' => t('Whitelisted HTML tags'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
        'allowed_html_help' => array(
          '#type' => 'help',
          '#markup' =>  t('User with appropriate admin privileges can edit this list.'),
        ),
        'allowed_html_info' => array(
          '#markup' => htmlentities($this->options['allowed_html']),
        ),
      );
    }
  }

  /**
   * {@inheritdoc}
   */
  public function render_altered($alter, $tokens) {
    // Filter this right away as our substitutions are already sanitized.
    $tags = preg_split('/\s+|<|>/', $this->options['allowed_html'], -1, PREG_SPLIT_NO_EMPTY);
    $value = filter_xss($alter['text'], $tags);
    $value = strtr($value, $tokens);
    return $value;
  }
}
