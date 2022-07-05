
#include <vector>
#include <string>
#include <map>


namespace xml {

    class XmlNode {
        public:
        std::string node_name;
        std::string node_content;
        std::string node_namespace;
        std::map<std::string, std::string> attributes;

        
    };
}