

#include "libxml/tree.h"




static void print_tree (xmlNode * a_node) {
    xmlNode *current_node = NULL;

    for (current_node = a_node; current_node; current_node = current_node->next) {
        if (current_node->type == XML_ELEMENT_NODE) {
            printf("%s\n", current_node->name);
        }

        print_tree(current_node->children);
    }
}