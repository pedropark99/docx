

#include "libxml/tree.h"



static void print_tree (xmlNode *node) {

    for (xmlNode *current_node = node; current_node; current_node = current_node->next) {
        if (current_node->type == XML_ELEMENT_NODE) {
            printf("%s\n", current_node->name);
        }

        print_tree(current_node->children);
    }
}

static void print_xml_document (docx docx) {
    print_tree(xmlDocGetRootElement(docx.document));
}



void write_xml (xmlDoc* document, const char *filename, bool indent = true) {

    if (indent) {
        xmlIndentTreeOutput = 1;
    } else {
        xmlIndentTreeOutput = 0;
    }

    xmlSaveFormatFile(filename, document, 1);
    xmlFreeDoc(document);

}



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
