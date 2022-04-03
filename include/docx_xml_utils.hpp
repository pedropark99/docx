#pragma once

#include "libxml/tree.h"

#include "docx_obj.hpp"


void print_xml_document (docx::docx docx, bool indent = true) {
    // If xmlIndentTreeOutput elements will be printed with indent;
    if (indent) {
        xmlIndentTreeOutput = 1;
    } else {
        xmlIndentTreeOutput = 0;
    }

    //Print entire document for standart output;
    xmlDocFormatDump(stdout, docx.document, 1);
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




