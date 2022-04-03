#pragma once

#include <iostream>

#include "libxml/parser.h"
#include "libxml/tree.h"



namespace docx {


    class p {
    public:
        xmlNodePtr paragraph_node;
        xmlNodePtr run_node;
        xmlNodePtr text_node;

        // Default constructor for paragraph node:
        p (char const * text = NULL) {
            paragraph_node = xmlNewNode(NULL, BAD_CAST "w:p");
            run_node = xmlNewNode(NULL, BAD_CAST "w:r");
            text_node = xmlNewNode(NULL, BAD_CAST "w:t");

            paragraph_node->children = run_node;
            run_node->children = text_node;

            /* 
            If text was provided for context of the paragraph,
            then add it to the <t> node.
            */
            if (text != NULL) {
               text_node->content = BAD_CAST text;
            };
        };



    };




    class docx {
        public:
        /* document pointer */
        xmlDocPtr document;

        docx() {
            const char * default_docx = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\n<w:document xmlns:wpc=\"http://schemas.microsoft.com/office/word/2010/wordprocessingCanvas\" xmlns:cx=\"http://schemas.microsoft.com/office/drawing/2014/chartex\" xmlns:cx1=\"http://schemas.microsoft.com/office/drawing/2015/9/8/chartex\" xmlns:cx2=\"http://schemas.microsoft.com/office/drawing/2015/10/21/chartex\" xmlns:cx3=\"http://schemas.microsoft.com/office/drawing/2016/5/9/chartex\" xmlns:cx4=\"http://schemas.microsoft.com/office/drawing/2016/5/10/chartex\" xmlns:cx5=\"http://schemas.microsoft.com/office/drawing/2016/5/11/chartex\" xmlns:cx6=\"http://schemas.microsoft.com/office/drawing/2016/5/12/chartex\" xmlns:cx7=\"http://schemas.microsoft.com/office/drawing/2016/5/13/chartex\" xmlns:cx8=\"http://schemas.microsoft.com/office/drawing/2016/5/14/chartex\" xmlns:mc=\"http://schemas.openxmlformats.org/markup-compatibility/2006\" xmlns:aink=\"http://schemas.microsoft.com/office/drawing/2016/ink\" xmlns:am3d=\"http://schemas.microsoft.com/office/drawing/2017/model3d\" xmlns:o=\"urn:schemas-microsoft-com:office:office\" xmlns:r=\"http://schemas.openxmlformats.org/officeDocument/2006/relationships\" xmlns:m=\"http://schemas.openxmlformats.org/officeDocument/2006/math\" xmlns:v=\"urn:schemas-microsoft-com:vml\" xmlns:wp14=\"http://schemas.microsoft.com/office/word/2010/wordprocessingDrawing\" xmlns:wp=\"http://schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing\" xmlns:w10=\"urn:schemas-microsoft-com:office:word\" xmlns:w=\"http://schemas.openxmlformats.org/wordprocessingml/2006/main\" xmlns:w14=\"http://schemas.microsoft.com/office/word/2010/wordml\" xmlns:w15=\"http://schemas.microsoft.com/office/word/2012/wordml\" xmlns:w16cex=\"http://schemas.microsoft.com/office/word/2018/wordml/cex\" xmlns:w16cid=\"http://schemas.microsoft.com/office/word/2016/wordml/cid\" xmlns:w16=\"http://schemas.microsoft.com/office/word/2018/wordml\" xmlns:w16sdtdh=\"http://schemas.microsoft.com/office/word/2020/wordml/sdtdatahash\" xmlns:w16se=\"http://schemas.microsoft.com/office/word/2015/wordml/symex\" xmlns:wpg=\"http://schemas.microsoft.com/office/word/2010/wordprocessingGroup\" xmlns:wpi=\"http://schemas.microsoft.com/office/word/2010/wordprocessingInk\" xmlns:wne=\"http://schemas.microsoft.com/office/word/2006/wordml\" xmlns:wps=\"http://schemas.microsoft.com/office/word/2010/wordprocessingShape\" mc:Ignorable=\"w14 w15 w16se w16cid w16 w16cex w16sdtdh wp14\"></w:document>";
            document = xmlReadDoc(BAD_CAST default_docx, NULL, "UTF-8", 1);
        };


        // =======================================
        // PUBLIC METHODS OF docx CLASS:
        // =======================================
        // Methods for print debugging:
        //
        void print_xml_tree_document(){
            int deep_index = 1;
            xmlNodePtr current_child_node = document->children;
            xmlNodePtr current_sibling_node;

            while (current_child_node != NULL) {
                printf("%*c%s%c\n", deep_index, '<', current_child_node->name, '>');

                if (current_child_node->next != NULL) {
                    current_sibling_node = current_child_node->next;

                    while (current_sibling_node != NULL) {
                        printf("%*c%s%c\n", deep_index, '<', current_sibling_node->name, '>');
                        current_sibling_node = current_sibling_node->next;
                    }
                }

                current_child_node = current_child_node->children;
                deep_index = deep_index + 2;
            }
        }



        void print_xml_document(){
            int deep_index = 1;
            xmlNodePtr current_child_node = document->children;

            while (current_child_node != NULL) {
                printf("%*c%s%c\n", deep_index, '<', current_child_node->name, '>');

                printf("%*c%s\n", deep_index, ' ', (char *)xmlNodeGetContent(current_child_node));

                current_child_node = current_child_node->children;
                deep_index = deep_index + 2;
            }
        }


        // ===============================================================
        // Methods for adding content:
        //

        int add_body () {
            xmlNodePtr root = xmlDocGetRootElement(document);
            xmlNodePtr child_node = root->children;

            bool children_is_null;
            children_is_null = child_node == NULL;
            if (children_is_null) {
                xmlNewChild(root, NULL, BAD_CAST "body", NULL);
                return 1;
            };

            bool body_already_present;
            body_already_present = xmlStrEqual(child_node->name, BAD_CAST "body");
            if (body_already_present) {
                std::cout << "Body already present;" << std::endl;
                return 2;
            };

            // If child node is not NULL, and, its name is not "body", so root
            // element already have a child node that is not "body". So we should
            // add a new child node called "body";
            xmlNewChild(root, NULL, BAD_CAST "body", NULL);
            return 3;
        }

        void add_paragraph (char const * text) {
            //Add body node if necessary
            add_body();
            xmlNodePtr body = xmlDocGetRootElement(document)->children;
            
            if (text != NULL) {
                // Paragraph object
                p par(text);
                // Add it as a child of "body" node
                body->children = par.paragraph_node;
                return;
            }

            // Paragraph object
            p par;
            // Add it as a child of "body" node
            body->children = par.paragraph_node;
            return;
        }
    };





    class rPr {
    public:
        xmlNodePtr node;

        rPr () {
            node = xmlNewNode(NULL, BAD_CAST "rPr");
        }

        // xmlNewProp() to create new attributes in a node
        // Is probably a good ideia to transform this style of functions below in a template

        // Indentation of paragraph
        void indentation (char *value, char *unit) {
            xmlNodePtr indentation_node = xmlNewNode(NULL, BAD_CAST "ind");
            xmlNewProp(indentation_node, BAD_CAST "val", BAD_CAST value);
        }

        // Alignment (or justification) of the paragraph
        void alignment (char *value) {
            xmlNodePtr alignment_node = xmlNewNode(NULL, BAD_CAST "jc");
            xmlNewProp(alignment_node, BAD_CAST "val", BAD_CAST value);
        }

        // Spacing between lines and between other paragraphs
        void spacing (char const *before = "0", char const *after = "0", char const *line = "0") {
            xmlNodePtr spacing_node = xmlNewNode(NULL, BAD_CAST "spacing");

            xmlNewProp(spacing_node, BAD_CAST "before", BAD_CAST before);
            xmlNewProp(spacing_node, BAD_CAST "after", BAD_CAST after);
            xmlNewProp(spacing_node, BAD_CAST "line", BAD_CAST line);
        }
        
    };





    class sectPr {

    };



};