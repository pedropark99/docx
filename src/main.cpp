#include <iostream>
#include <stdio.h>

#include "docx_obj.hpp"
#include "docx_xml_utils.hpp"

#define LOG(X) std::cout << X << std::endl;
#define ISNULL(X) if (X == NULL) { LOG("Is NULL!"); }


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

    docx::docx doc;
    doc.add_body();
    xmlNodePtr root = xmlDocGetRootElement(doc.document);

    LOG(root->name);

    // xmlNodePtr child = root->xmlChildrenNode;
    // bool result;
    // result = child == NULL;
    // LOG(result);

    return 1;
}