#pragma once

#include <iostream>

#include "libxml/parser.h"
#include "libxml/tree.h"

// <w:body><w:p w14:paraId=\"42F68DC4\" w14:textId=\"77777777\" w:rsidR=\"000850D5\" w:rsidRDefault=\"000850D5\"/><w:sectPr w:rsidR=\"000850D5\"><w:pgSz w:w=\"11906\" w:h=\"16838\"/><w:pgMar w:top=\"1417\" w:right=\"1701\" w:bottom=\"1417\" w:left=\"1701\" w:header=\"708\" w:footer=\"708\" w:gutter=\"0\"/><w:cols w:space=\"708\"/><w:docGrid w:linePitch=\"360\"/></w:sectPr></w:body>



namespace docx {
    class docx {
        public:
        /* document pointer */
        xmlDocPtr document;

        docx() {
            const char * default_docx = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\n<w:document xmlns:wpc=\"http://schemas.microsoft.com/office/word/2010/wordprocessingCanvas\" xmlns:cx=\"http://schemas.microsoft.com/office/drawing/2014/chartex\" xmlns:cx1=\"http://schemas.microsoft.com/office/drawing/2015/9/8/chartex\" xmlns:cx2=\"http://schemas.microsoft.com/office/drawing/2015/10/21/chartex\" xmlns:cx3=\"http://schemas.microsoft.com/office/drawing/2016/5/9/chartex\" xmlns:cx4=\"http://schemas.microsoft.com/office/drawing/2016/5/10/chartex\" xmlns:cx5=\"http://schemas.microsoft.com/office/drawing/2016/5/11/chartex\" xmlns:cx6=\"http://schemas.microsoft.com/office/drawing/2016/5/12/chartex\" xmlns:cx7=\"http://schemas.microsoft.com/office/drawing/2016/5/13/chartex\" xmlns:cx8=\"http://schemas.microsoft.com/office/drawing/2016/5/14/chartex\" xmlns:mc=\"http://schemas.openxmlformats.org/markup-compatibility/2006\" xmlns:aink=\"http://schemas.microsoft.com/office/drawing/2016/ink\" xmlns:am3d=\"http://schemas.microsoft.com/office/drawing/2017/model3d\" xmlns:o=\"urn:schemas-microsoft-com:office:office\" xmlns:r=\"http://schemas.openxmlformats.org/officeDocument/2006/relationships\" xmlns:m=\"http://schemas.openxmlformats.org/officeDocument/2006/math\" xmlns:v=\"urn:schemas-microsoft-com:vml\" xmlns:wp14=\"http://schemas.microsoft.com/office/word/2010/wordprocessingDrawing\" xmlns:wp=\"http://schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing\" xmlns:w10=\"urn:schemas-microsoft-com:office:word\" xmlns:w=\"http://schemas.openxmlformats.org/wordprocessingml/2006/main\" xmlns:w14=\"http://schemas.microsoft.com/office/word/2010/wordml\" xmlns:w15=\"http://schemas.microsoft.com/office/word/2012/wordml\" xmlns:w16cex=\"http://schemas.microsoft.com/office/word/2018/wordml/cex\" xmlns:w16cid=\"http://schemas.microsoft.com/office/word/2016/wordml/cid\" xmlns:w16=\"http://schemas.microsoft.com/office/word/2018/wordml\" xmlns:w16sdtdh=\"http://schemas.microsoft.com/office/word/2020/wordml/sdtdatahash\" xmlns:w16se=\"http://schemas.microsoft.com/office/word/2015/wordml/symex\" xmlns:wpg=\"http://schemas.microsoft.com/office/word/2010/wordprocessingGroup\" xmlns:wpi=\"http://schemas.microsoft.com/office/word/2010/wordprocessingInk\" xmlns:wne=\"http://schemas.microsoft.com/office/word/2006/wordml\" xmlns:wps=\"http://schemas.microsoft.com/office/word/2010/wordprocessingShape\" mc:Ignorable=\"w14 w15 w16se w16cid w16 w16cex w16sdtdh wp14\"><w:body></w:body></w:document>";
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


        // Methods for adding content:
        void add_paragraph (char * text = NULL) {
            xmlNodePtr body = xmlDocGetRootElement(document)->children;

            xmlNewChild(body, NULL, BAD_CAST "p", NULL);
            xmlNodePtr par = body->children;
            
            if (text != NULL) {
                xmlNewChild(par, NULL, BAD_CAST "r", NULL);
                xmlNewChild(par->children, NULL, BAD_CAST "t", BAD_CAST text);
            };

            // if (properties != NULL) {
            //     xmlNewChild(par, NULL, BAD_CAST "rPr", NULL);
            // }

        }
    };







    class p {
    public:
        xmlNodePtr paragraph_node;
        xmlNodePtr run_node;
    };




    class rPr {
    public:
        xmlNodePtr node;

        rPr () {
            node = xmlNewNode(NULL, BAD_CAST "rPr");
        }

        // xmlNewProp() to create new attributes in a node
        // Indentation of paragraph
        void indentation (int value, char* unit) {
            xmlNewProp(node, BAD_CAST "ind", BAD_CAST (char *)value);
        }

        void alignment (char* value) {
            xmlNewProp(node, BAD_CAST "jc", BAD_CAST value);
        }

        void spacing (int value) {
            xmlNewProp(node, BAD_CAST "spacing", BAD_CAST (char *)value);
        }


        
    };



};