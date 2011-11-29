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

	$kendra_api_services_endpoint_name = variable_get('KENDRA_SOCIAL_SERVICES_ENDPOINT_NAME', 'api');
	$kendra_api_services_endpoint_prefix = variable_get('KENDRA_SOCIAL_SERVICES_ENDPOINT_PREFIX', 'api/0.1');

	$endpoint = new stdClass;
	$endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
	$endpoint->api_version = 3;
	$endpoint->name = $kendra_api_services_endpoint_name;
	$endpoint->server = 'rest_server';
	$endpoint->path = $kendra_api_services_endpoint_prefix;
	$endpoint->authentication = array(
    'services' => 'services',
	);
	$endpoint->server_settings = array(
    'rest_server' => array(
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
	),
	);

	$endpoint->resources = kendra_api_services_services_get_mappings();

	$endpoint->debug = 1;
	$export[$kendra_api_services_endpoint_name] = $endpoint;

	return $export;
}
