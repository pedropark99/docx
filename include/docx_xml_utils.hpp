#pragma once

#include "libxml/tree.h"

#include "docx_obj.hpp"


void print_tree (xmlNode *node) {

    for (xmlNode *current_node = node; current_node; current_node = current_node->next) {
        if (current_node->type == XML_ELEMENT_NODE) {
            printf("%s\n", current_node->name);
        }

        print_tree(current_node->children);
    }
}

void print_xml_document (docx::docx docx) {
    print_tree(xmlDocGetRootElement(docx.document));
}


// Example of use:
// write_xml(doc.document, "teste.xml");
void write_xml (xmlDoc* document, const char *filename, bool indent = true) {

    if (indent) {
        xmlIndentTreeOutput = 1;
    } else {
        xmlIndentTreeOutput = 0;
    }

    xmlSaveFormatFile(filename, document, 1);
    xmlFreeDoc(document);

}




