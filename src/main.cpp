#include <iostream>
#include <stdio.h>

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

    docx::docx doc;
    xmlNodePtr root = xmlDocGetRootElement(doc.document);
    xmlNodePtr child_node = root->children;

    bool children_is_null;
    bool body_already_present;
    children_is_null = child_node == NULL;
    // Looks like "child_node->name" is the source of the bug
    //body_already_present = xmlStrEqual(child_node->name, BAD_CAST "body");
    
    //LOG(child_node->name);
    LOG(children_is_null);

    return 1;
}