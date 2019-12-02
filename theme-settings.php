<?php

/**
 * @param $form
 * @param \Drupal\Core\Form\FormStateInterface $formState
 * @param null $form_id
 */
function bootstrap_italia_form_system_theme_settings_alter(&$form, \Drupal\Core\Form\FormStateInterface &$formState, $form_id = NULL) {
  if (isset($form_id)) {
    return;
  }

  $form['ente_appartenenza'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Ente di appartenenza'),
    '#default_value'  => theme_get_setting('ente_appartenenza'),
    '#description'    => t('Inserisci l\'ente di appartenenza'),
  );
}