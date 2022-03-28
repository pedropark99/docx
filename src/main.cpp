#include <iostream>
#include <cstdio>

#include "docx_obj.hpp"
#include "docx_xml_utils.hpp"



int main (void) {

    docx doc;
    print_tree(xmlDocGetRootElement(doc.document));

    //FILE *new_file;
    //new_file = fopen("examples/teste.xml", "w");

    write_xml(doc.document, "teste.xml");

    return 1;
}