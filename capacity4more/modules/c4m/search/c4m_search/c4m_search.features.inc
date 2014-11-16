<?php
/**
 * @file
 * c4m_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function c4m_search_default_search_api_index() {
  $items = array();
  $items['c4m_search_nodes'] = entity_import('search_api_index', '{
    "name" : "Search Nodes",
    "machine_name" : "c4m_search_nodes",
    "description" : "Search index for all nodes.",
    "server" : "c4m_solr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : { "minisite" : "minisite" } }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "c4m_organised_by" : true,
              "c4m_cris_contract_number" : true,
              "c4m_cris_decision_number" : true,
              "c4m_implemented_by" : true,
              "c4m_partner" : true,
              "c4m_source_of_funding" : true,
              "body:value" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "c4m_organised_by" : true,
              "c4m_cris_contract_number" : true,
              "c4m_cris_decision_number" : true,
              "c4m_implemented_by" : true,
              "c4m_partner" : true,
              "c4m_source_of_funding" : true,
              "body:value" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 1,
          "weight" : "15",
          "settings" : { "fields" : {
              "title" : true,
              "c4m_organised_by" : true,
              "c4m_cris_contract_number" : true,
              "c4m_cris_decision_number" : true,
              "c4m_implemented_by" : true,
              "c4m_partner" : true,
              "c4m_source_of_funding" : true,
              "body:value" : true
            }
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "c4m_organised_by" : true,
              "c4m_cris_contract_number" : true,
              "c4m_cris_decision_number" : true,
              "c4m_implemented_by" : true,
              "c4m_partner" : true,
              "c4m_source_of_funding" : true,
              "body:value" : true
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "c4m_organised_by" : true,
              "c4m_cris_contract_number" : true,
              "c4m_cris_decision_number" : true,
              "c4m_implemented_by" : true,
              "c4m_partner" : true,
              "c4m_source_of_funding" : true,
              "body:value" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      },
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:value" : { "type" : "text" },
        "c4m_cris_contract_number" : { "type" : "list\\u003Ctext\\u003E" },
        "c4m_cris_decision_number" : { "type" : "list\\u003Ctext\\u003E" },
        "c4m_date" : { "type" : "date" },
        "c4m_discussion_type" : { "type" : "string" },
        "c4m_document_agenda" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "c4m_document_presentation" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "c4m_event_type" : { "type" : "string" },
        "c4m_implemented_by" : { "type" : "list\\u003Ctext\\u003E" },
        "c4m_organised_by" : { "type" : "text" },
        "c4m_partner" : { "type" : "list\\u003Ctext\\u003E" },
        "c4m_related_topic" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "c4m_source_of_funding" : { "type" : "list\\u003Ctext\\u003E" },
        "c4m_vocab_date" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "c4m_vocab_document_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "c4m_vocab_geo" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "c4m_vocab_language" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "changed" : { "type" : "date" },
        "comment_count" : { "type" : "integer" },
        "created" : { "type" : "date" },
        "group_group" : { "type" : "boolean" },
        "is_new" : { "type" : "boolean" },
        "nid" : { "type" : "integer" },
        "promote" : { "type" : "boolean" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "type" : { "type" : "string" }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  $items['c4m_search_users'] = entity_import('search_api_index', '{
    "name" : "Search Users",
    "machine_name" : "c4m_search_users",
    "description" : null,
    "server" : "c4m_solr",
    "item_type" : "user",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "c4m_country" : { "type" : "string" },
        "c4m_first_name" : { "type" : "text" },
        "c4m_is_deleted" : { "type" : "boolean" },
        "c4m_is_spammer" : { "type" : "boolean" },
        "c4m_last_name" : { "type" : "text" },
        "c4m_organisation" : { "type" : "text" },
        "c4m_organisation_type" : { "type" : "text" },
        "c4m_related_topic" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "c4m_related_topic_expertise" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "c4m_vocab_geo" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "mail" : { "type" : "text" },
        "name" : { "type" : "text" },
        "og_membership__1" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "og_membership" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "uid" : { "type" : "integer" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_role_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "roles" : [] }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "name" : true,
              "mail" : true,
              "c4m_related_topic" : true,
              "c4m_related_topic_expertise" : true,
              "c4m_vocab_geo" : true,
              "c4m_country" : true,
              "c4m_first_name" : true,
              "c4m_last_name" : true,
              "c4m_organisation" : true,
              "c4m_organisation_type" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "name" : true,
              "mail" : true,
              "c4m_first_name" : true,
              "c4m_last_name" : true,
              "c4m_organisation" : true,
              "c4m_organisation_type" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 1,
          "weight" : "15",
          "settings" : { "fields" : {
              "name" : true,
              "mail" : true,
              "c4m_first_name" : true,
              "c4m_last_name" : true,
              "c4m_organisation" : true,
              "c4m_organisation_type" : true
            }
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "name" : true,
              "mail" : true,
              "c4m_first_name" : true,
              "c4m_last_name" : true,
              "c4m_organisation" : true,
              "c4m_organisation_type" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "name" : true,
              "mail" : true,
              "c4m_first_name" : true,
              "c4m_last_name" : true,
              "c4m_organisation" : true,
              "c4m_organisation_type" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}