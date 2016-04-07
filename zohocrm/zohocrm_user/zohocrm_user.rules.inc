<?php

/**
 * @file
 * Provides basic rules module support.
 */

/**
 * Implements hook_rules_action_info().
 */
function zohocrm_user_rules_action_info() {
  $info = array();

  $defaults = array (
    'parameter' => array (
      'user' => array(
        'type' => 'user',
        'label' => t('ZUser'),
      ),
      'mapping' => array(
        'type' => 'list<text>',
        'label' => t('Mapping'),
        'options list' => 'zohocrm_mappings_select_options',
      ),
    ),
    // 'module' => 'zohocrm',
    'group' => 'Zoho',
  );


  $info['user_action_send_user_data'] = $defaults + array (
    'label' => t('Zuser: Send user account data to Zoho'),
    'base' => 'zohocrm_rules_action_send_user_data',
  );

  $info['user_action_delete_zoho_record'] = $defaults + array (
    'label' => t('Zuser: Delete Zoho CRM record'),
    'base' => 'zohocrm_user_rules_action_delete_zoho_record',
  );

  return $info;
}

function zohocrm_rules_action_send_user_data($user, $mapping) {
  $settings = array('mapping' => $mapping);
  zohocrm_send_data($user, $settings);
}

function zohocrm_user_rules_action_delete_zoho_record($user, $mapping) {
  $settings = array('mapping' => $mapping);
  zohocrm_action_delete_zoho_record($user, $settings);
}

function zohocrm_user_rules_action_delete_zoho_record_form($settings, &$form) {
  zohocrm_rules_action_form($settings, $form);
}
