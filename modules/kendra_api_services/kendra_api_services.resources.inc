<?php
/**
 * @file
 * Code for the Kendra API Services feature.
 */

/**
 * define the mappings of resource + parameters to internal callbacks
 *
 * @returns Array of mappings
 */
function kendra_api_services_services_get_mappings() {
	$allow_callback_reassignment = FALSE;
	$res_type = 'endpoints';
	$res_operations = array(
    'create' => array(
		'file' => array('type' => 'inc', 'module' => 'kendra_api_services', 'name' => 'kendra_api_services.callbacks'),
	'access arguments' => array('access content'),
        'callback' => '_kapi_do_api_create',
        'enabled' => 1,
	),
    'retrieve' => array(
		'file' => array('type' => 'inc', 'module' => 'kendra_api_services', 'name' => 'kendra_api_services.callbacks'),
	'access arguments' => array('access content'),
        'callback' => '_kapi_do_api_retrieve',
        'enabled' => 1,
	),
    'update' => array(
		'file' => array('type' => 'inc', 'module' => 'kendra_api_services', 'name' => 'kendra_api_services.callbacks'),
	'access arguments' => array('access content'),
        'callback' => '_kapi_do_api_update',
        'enabled' => 1,
	),
    'delete' => array(
		'file' => array('type' => 'inc', 'module' => 'kendra_api_services', 'name' => 'kendra_api_services.callbacks'),
	'access arguments' => array('access content'),
        'callback' => '_kapi_do_api_delete',
        'enabled' => 1,
	),
	/**
	 * index -- THIS ONE WORKS AS EXPECTED
	 */
    'index' => array(
		'file' => array('type' => 'inc', 'module' => 'kendra_api_services', 'name' => 'kendra_api_services.callbacks'),
		'access arguments' => array('access content'),
	        'callback' => '_kapi_do_api_index',
	        'enabled' => 1,
	        'help' => 'Retrieve a set of endpoint definitions',
	        'args' => array(
	array(
	            'name' => 'id',
	            'optional' => TRUE,
	            'source' => array('param' => 'id'),
	            'type' => 'string',
	            'description' => 'Pass in alphanumeric format',
	            'default value' => '*',
	),
	),
			'access callback' => '_kapi_default_access_callback',
			'access arguments' => array('index'),
			'access arguments append' => TRUE,
	),
	);

	$res_actions = array();
	$res_relationships = array();

	/**
	 * Reassign callback value for non-existant callback functions.
	 * Note: it might be nicer to do this with closures, in PHP >= 5.3
	 */
	if ($allow_callback_reassignment) {
		foreach ($res_operations as $op => $args) {
			if (!function_exists($args['callback'])) {
				$res_operations[$op]['file'] = array('type' => 'module', 'module' => 'kendra_api_services', 'name' => 'kendra_api_services');
				$res_operations[$op]['callback'] = '_kapi_default_callback';
				watchdog('Kendra API', 'redefined @name as @newname', array('@name'=>$args['callback'], '@newname'=>$res_operations[$op]['callback']));
			}
		}
	}

	return array(	$res_type =>
	array_merge($res_operations, array(
        'operations' => $res_operations,
        'actions' => $res_actions,
        'relationships' => $res_relationships,
	)));
}

/**
 * Kendra API Default Access Callback
 */
function _kapi_default_access_callback($op, $args){
	watchdog('Kendra API', 'verifying access for @op, @args', array('@op'=>$op, '@args'=>print_r($args,1)));

	return TRUE;
}