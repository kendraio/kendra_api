<?php

function postprocess_return_json($obj) {
//	return json_encode($obj);
	return $obj;
}
function _kapi_do_api_create() {
	return postprocess_return_json(array('callback' => __FUNCTION__, 'args' => func_get_args()));
}
function _kapi_do_api_retrieve() {
	return postprocess_return_json(array('callback' => __FUNCTION__, 'args' => func_get_args()));
	}
function _kapi_do_api_update() {
	return postprocess_return_json(array('callback' => __FUNCTION__, 'args' => func_get_args()));
	}
function _kapi_do_api_delete() {
	return postprocess_return_json(array('callback' => __FUNCTION__, 'args' => func_get_args()));
	}
function _kapi_do_api_index() {
	return postprocess_return_json(array('callback' => __FUNCTION__, 'args' => func_get_args()));
	}
