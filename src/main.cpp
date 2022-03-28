#include <iostream>

#include "docx_obj.hpp"
#include "docx_xml_utils.hpp"



int main (void) {

    docx doc;
    print_xml_document(doc);
    //write_xml(doc.document, "teste.xml");

    return 1;
}