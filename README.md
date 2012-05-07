# Kendra API

## Overview

The Kendra API defines a set of resources for Drupal 7 [Services](http://drupal.org/project/services), with corresponding access rules that define their availability via a [ReST](http://en.wikipedia.org/wiki/REST)ful HTTP endpoint. The HTTP-based API supports multiple request/response formats, and can be modified in real time via updates to the method definitions, to adjust to the requirements of the project.

Well-defined methods, parameters, and response patterns are designed, documented and exported using the [Kendra API Builder](https://github.com/kendrainitiative/kendra_api_builder). The API is then initialized with the output from the Kendra API Builder using the [Service Mapping Description](http://www.slideshare.net/kriszyp/jsonbased-service-oriented-architecture-for-the-web-presentation) format, a community proposal for a standardised profile of [JSON Schema](http://json-schema.org/) for describing a web service.

Employing a RESTful communications pattern utilizing HTTP methods for CRUD and index operations, Kendra API supports XML or JSON envelopes. Clients (e.g. widgets or instances of the SARACEN Terminal application) accessing the endpoint may use either the “application/xml” or “application/json” HTTP content-type for requests and responses.

Kendra API aims to implement basic features of the [OpenSocial 2.0 API and Data Specifications](http://docs.opensocial.org/display/OSD/Specs) (Core API Server, Core Data, Social API Server, Social Data). Core data types defined by these specifications include “People”, “Groups”, “MediaItems”, and “Albums” in addition to the complementary support for the “ActivityEntry” data type from the Activity Streams specification which was added in the version 2.0 of the Social Data specification.

Kendra API is free software developed by Kendra Foundation in collaboration with SARACEN and co-funded by the European Union under the Seventh Framework programme. Sample code and the validation tool will be released under the GNU General Public License. Additionally, Kendra will Creative Commons license all of the API documentation, so users will be welcome to reuse and remix as appropriate.

## Conventions

HTTP endpoint = `(http|https) "://" {host-domain} / {project} / {version} / {resource}`

* `{project}` = the Kendra project corresponding to the client and requests being made, *e.g.* `saracen`, `p2p-next`.
* `{version}` = the version of the API to use when validating or processing requests, *e.g.* `0.1`, `1.0`, `1.1beta`. This MUST correspond to a published version of the public API as defined by the API builder.
    * Where version = test/validator then include default test results for numeric/text/date/etc types. 
* `{resource}` = a RESTful path component addressed to the required method, *e.g.* `SaracenUser/add`, `user.add`, etc. This will be defined as we construct the methods in the API builder.
    * The resource name/title will include the project name for specific project function calls. 

## Usage

* *TODO: include an overview of the SMD import/export process*

The API endpoint implements [HTTP access control](https://developer.mozilla.org/en/http_access_control), including the following HTTP header on all responses from the API endpoint:
            
        Access-Control-Allow-Origin: *
        
This will allow RESTful AJAX requests made via Javascript running in a third party host (*e.g.* a website, OpenSocial gadget, Javascript widget) to work correctly. Otherwise the browser would present the user with a security exception or fail silently due to the limits of the browser security model.