# Kendra API

A generalised API for Kendra Initiative.

* SCM: https://github.com/kendrainitiative/kendra_api

Kendra will provide an HTTP endpoint for making requests via the Kendra API.

## `api.kendra.org / {project} / {version} / {resource}`

* Host domain: **api.kendra.org**
* `{version}` = the version of the API to use when validating or processing requests, *e.g.* `0.1`, `1.0`, `1.1beta`. This MUST correspond to a published version of the public API as defined by the API builder.
    * Where version = test/validator then include default test results for numeric/text/date/etc types. 
* `{project}` = the Kendra project corresponding to the client and requests being made, *e.g.* `saracen`, `p2p-next`.
* `{resource}` = a RESTful path component addressed to the required method, *e.g.* `SaracenUser/add`, `user.add`, etc. This will be defined as we construct the methods in the API builder.
    * The resource name/title will include the project name for specific project function calls. 

## `sandbox.api.kendra.org / {project} / {version} / {resource}`

In addition to the live production API endpoint, a test endpoint will be available for verifying proper usage of the protocol specification. Within this sandbox, requests will not affect data stored in the live production database, so developers can test their code without concern for major disruptions.

* Host domain: **sandbox.api.kendra.org**
* All other path components should be identical to the live endpoint.

# Usage

* The API endpoint SHOULD implement [HTTP access control](https://developer.mozilla.org/en/http_access_control). The API Host SHOULD include the following HTTP header on all responses from the API endpoint:
            
            Access-Control-Allow-Origin: *
        
    This will allow RESTful AJAX requests made via Javascript running in a third party host (*e.g.* a website, OpenSocial gadget, Javascript widget) to work correctly. Otherwise the browser would present the user with a security exception or fail silently due to the limits of the browser security model.