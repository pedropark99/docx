#include <iostream>

#include "docx_obj.hpp"
#include "docx_xml_utils.hpp"

#define LOG(X) std::cout << X << std::endl;

/*
TO GET THE CONTENT OF A NODE
xmlNodeGetContent();

TO GET THE NAME OF THE NODE
Node_object->name;

TO COMPARE IF TWO XML STRINGS ARE EQUAL
xmlStrEqual(); //e.g. xmlStrEqual(node->name, BAD_CAST "body")

TO NAVIGATE TO THE NEXT SIBLING NODE
node->next;

TO NAVIGATE TO THE NEXT CHILDREN NODE
node->child;
*/

int main (void) {

    docx doc;
    //print_xml_document(doc);
    //write_xml(doc.document, "teste.xml");

    LOG(find_body_node(doc.document));

    return 1;
}