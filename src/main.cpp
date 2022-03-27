#include <iostream>

#include "docx_obj.hpp"
#include "docx_xml_utils.hpp"



int main (void) {

    docx doc;
    print_tree(xmlDocGetRootElement(doc.document));
    return 1;
}