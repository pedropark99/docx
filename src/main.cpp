#include <iostream>

#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "rapidxml/rapidxml_print.hpp"

int main (void) {
    rapidxml::file<> xmlFile("../xml_examples/xmlns1.xml"); 
    rapidxml::xml_document<> doc;
    doc.parse<0>(xmlFile.data());

    rapidxml::xml_node<> *node = doc.first_node();

    for(rapidxml::xml_node<> *i = doc.first_node(); i; i->next_sibling()){
        std::cout << i->value() << "\n";
    }

    return 1;
}