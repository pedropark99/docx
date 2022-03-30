
#include "docx_obj.hpp"


/* 
To add new paragraphs, we need to find first the body node
of the document, and them, add the <p> tag.
*/
xmlNodePtr find_body_node (xmlDoc* document) {
    xmlNodePtr current_node = xmlDocGetRootElement(document);
    while (current_node != NULL) {
        if (xmlStrEqual(current_node->name, BAD_CAST "body")) {
            return current_node;
        }

        current_node = current_node->children;
    }

    return NULL;
}



