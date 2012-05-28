<?php
/**
 * @file
 * kendra_api_services.services.inc
 */

/**
 * Implementation of hook_default_services_endpoint().
 */
function kendra_api_services_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'api';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'api/0.1';
  $endpoint->authentication = array(
    'services' => 'services',
  );
  $endpoint->server_settings = array(
    'formatters' => array(
      'bencode' => TRUE,
      'json' => TRUE,
      'php' => TRUE,
      'rss' => TRUE,
      'xml' => TRUE,
      'yaml' => TRUE,
      'jsonp' => TRUE,
    ),
    'parsers' => array(
      'application/json' => TRUE,
      'application/vnd.php.serialized' => TRUE,
      'application/x-www-form-urlencoded' => TRUE,
      'application/x-yaml' => TRUE,
      'multipart/form-data' => TRUE,
    ),
  );
  $endpoint->resources = array(
    'endpoints' => array(
      'index' => array(
        'file' => array(
          'type' => 'inc',
          'module' => 'kendra_api_services',
          'name' => 'kendra_api_services.callbacks',
        ),
        'callback' => '_kapi_do_api_index',
        'enabled' => 1,
        'help' => 'Retrieve a set of endpoint definitions',
        'args' => array(
          0 => array(
            'name' => 'id',
            'optional' => TRUE,
            'source' => array(
              'param' => 'id',
            ),
            'type' => 'string',
            'description' => 'Pass in alphanumeric format',
            'default value' => '*',
          ),
        ),
        'access callback' => '_kapi_default_access_callback',
        'access arguments' => array(
          0 => 'access content',
        ),
        'access arguments append' => TRUE,
      ),
      'create' => array(
        'file' => array(
          'type' => 'inc',
          'module' => 'kendra_api_services',
          'name' => 'kendra_api_services.callbacks',
        ),
        'callback' => '_kapi_do_api_create',
        'enabled' => 1,
        'help' => 'Create an endpoint definition',
        'args' => array(),
        'access callback' => '_kapi_default_access_callback',
        'access arguments' => array(
          0 => 'access content',
        ),
        'access arguments append' => TRUE,
      ),
      'retrieve' => array(
        'file' => array(
          'type' => 'inc',
          'module' => 'kendra_api_services',
          'name' => 'kendra_api_services.callbacks',
        ),
        'callback' => '_kapi_do_api_retrieve',
        'enabled' => 1,
        'help' => 'Retrieve an endpoint definition',
        'args' => array(),
        'access callback' => '_kapi_default_access_callback',
        'access arguments' => array(
          0 => 'access content',
        ),
        'access arguments append' => TRUE,
      ),
      'update' => array(
        'file' => array(
          'type' => 'inc',
          'module' => 'kendra_api_services',
          'name' => 'kendra_api_services.callbacks',
        ),
        'callback' => '_kapi_do_api_update',
        'enabled' => 1,
        'help' => 'Update an endpoint definition',
        'args' => array(),
        'access callback' => '_kapi_default_access_callback',
        'access arguments' => array(
          0 => 'access content',
        ),
        'access arguments append' => TRUE,
      ),
      'delete' => array(
        'file' => array(
          'type' => 'inc',
          'module' => 'kendra_api_services',
          'name' => 'kendra_api_services.callbacks',
        ),
        'callback' => '_kapi_do_api_delete',
        'enabled' => 1,
        'help' => 'delete an endpoint definition',
        'args' => array(),
        'access callback' => '_kapi_default_access_callback',
        'access arguments' => array(
          0 => 'access content',
        ),
        'access arguments append' => TRUE,
      ),
      'operations' => array(
        'index' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'kendra_api_services',
            'name' => 'kendra_api_services.callbacks',
          ),
          'callback' => '_kapi_do_api_index',
          'enabled' => 1,
          'help' => 'Retrieve a set of endpoint definitions',
          'args' => array(
            0 => array(
              'name' => 'id',
              'optional' => TRUE,
              'source' => array(
                'param' => 'id',
              ),
              'type' => 'string',
              'description' => 'Pass in alphanumeric format',
              'default value' => '*',
            ),
          ),
          'access callback' => '_kapi_default_access_callback',
          'access arguments' => array(
            0 => 'access content',
          ),
          'access arguments append' => TRUE,
        ),
        'create' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'kendra_api_services',
            'name' => 'kendra_api_services.callbacks',
          ),
          'callback' => '_kapi_do_api_create',
          'enabled' => 1,
          'help' => 'Create an endpoint definition',
          'args' => array(),
          'access callback' => '_kapi_default_access_callback',
          'access arguments' => array(
            0 => 'access content',
          ),
          'access arguments append' => TRUE,
        ),
        'retrieve' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'kendra_api_services',
            'name' => 'kendra_api_services.callbacks',
          ),
          'callback' => '_kapi_do_api_retrieve',
          'enabled' => 1,
          'help' => 'Retrieve an endpoint definition',
          'args' => array(),
          'access callback' => '_kapi_default_access_callback',
          'access arguments' => array(
            0 => 'access content',
          ),
          'access arguments append' => TRUE,
        ),
        'update' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'kendra_api_services',
            'name' => 'kendra_api_services.callbacks',
          ),
          'callback' => '_kapi_do_api_update',
          'enabled' => 1,
          'help' => 'Update an endpoint definition',
          'args' => array(),
          'access callback' => '_kapi_default_access_callback',
          'access arguments' => array(
            0 => 'access content',
          ),
          'access arguments append' => TRUE,
        ),
        'delete' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'kendra_api_services',
            'name' => 'kendra_api_services.callbacks',
          ),
          'callback' => '_kapi_do_api_delete',
          'enabled' => 1,
          'help' => 'delete an endpoint definition',
          'args' => array(),
          'access callback' => '_kapi_default_access_callback',
          'access arguments' => array(
            0 => 'access content',
          ),
          'access arguments append' => TRUE,
        ),
      ),
      'actions' => array(),
      'relationships' => array(),
    ),
  );
  $endpoint->debug = 1;
  $export['api'] = $endpoint;

  return $export;
}
