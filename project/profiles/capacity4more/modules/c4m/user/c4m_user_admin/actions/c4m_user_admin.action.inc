<?php

/**
 * @file
 * Callback & forms related to the user admin.
 */

/**
 * Custom actions defined by c4m_user_admin module.
 *
 * @return array
 *   Information about the action.
 */
function _c4m_user_admin_action_info() {
  return array(
    'c4m_user_admin_activate_action' => array(
      'type' => 'user',
      'label' => t('Activate user'),
      'configurable' => FALSE,
      'triggers' => array('any'),
    ),
    'c4m_user_admin_resend_activation_email_action' => array(
      'type' => 'user',
      'label' => t('Resend activation email'),
      'configurable' => FALSE,
      'triggers' => array('any'),
    ),
  );
}

/**
 * Performs the 'activate user' action.
 *
 * @param object $user
 *   The user object.
 */
function c4m_user_admin_activate_action($user) {
  $wrapper = entity_metadata_wrapper('user', $user);

  $wrapper->status->set(C4M_USER_STATUS_ACTIVE);
  $wrapper->c4m_is_spammer->set(FALSE);
  $wrapper->c4m_is_deleted->set(FALSE);
  $wrapper->c4m_is_deleted_anonymous->set(FALSE);
  $wrapper->c4m_is_deleted_by_uid->set(NULL);

  $wrapper->save();
}

/**
 * Performs the 'resend activation email' action.
 *
 * @param object $account
 *   The user object.
 */
function c4m_user_admin_resend_activation_email_action($account) {
  $account_wrapper = entity_metadata_wrapper('user', $account);
  if (!$account_wrapper->status->value() && !$account_wrapper->c4m_is_spammer->value() && !$account_wrapper->c4m_is_deleted->value()) {
    $params['account'] = $account;
    drupal_mail('user_registrationpassword', 'register', $account->mail, user_preferred_language($account), $params);

    drupal_set_message(t('Activation mail was sent.'));
  }
  else {
    drupal_set_message(t('Account of @first_name @last_name is either active or deleted or marked as spammer.', array(
      '@first_name' => $account_wrapper->c4m_first_name->value(),
      '@last_name' => $account_wrapper->c4m_last_name->value(),
    )));
  }
}
