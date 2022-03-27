
#include "libxml/parser.h"
#include "libxml/tree.h"


const char *ns_docx_names[33] = {
    "http://schemas.microsoft.com/office/drawing/2016/ink",
    "http://schemas.microsoft.com/office/drawing/2017/model3d",
    "http://schemas.microsoft.com/office/drawing/2014/chartex",
    "http://schemas.microsoft.com/office/drawing/2015/9/8/chartex",
    "http://schemas.microsoft.com/office/drawing/2015/10/21/chartex",
    "http://schemas.microsoft.com/office/drawing/2016/5/9/chartex",
    "http://schemas.microsoft.com/office/drawing/2016/5/10/chartex",
    "http://schemas.microsoft.com/office/drawing/2016/5/11/chartex",
    "http://schemas.microsoft.com/office/drawing/2016/5/12/chartex",
    "http://schemas.microsoft.com/office/drawing/2016/5/13/chartex",
    "http://schemas.microsoft.com/office/drawing/2016/5/14/chartex",
    "http://schemas.openxmlformats.org/officeDocument/2006/math",
    "http://schemas.openxmlformats.org/markup-compatibility/2006",
    "urn:schemas-microsoft-com:office:office",
    "http://schemas.openxmlformats.org/officeDocument/2006/relationships",
    "urn:schemas-microsoft-com:vml",
    "http://schemas.openxmlformats.org/wordprocessingml/2006/main",
    "urn:schemas-microsoft-com:office:word",
    "http://schemas.microsoft.com/office/word/2010/wordml",
    "http://schemas.microsoft.com/office/word/2012/wordml",
    "http://schemas.microsoft.com/office/word/2018/wordml",
    "http://schemas.microsoft.com/office/word/2018/wordml/cex",
    "http://schemas.microsoft.com/office/word/2016/wordml/cid",
    "http://schemas.microsoft.com/office/word/2020/wordml/sdtdatahash",
    "http://schemas.microsoft.com/office/word/2015/wordml/symex",
    "http://schemas.microsoft.com/office/word/2006/wordml",
    "http://schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing",
    "http://schemas.microsoft.com/office/word/2010/wordprocessingDrawing",
    "http://schemas.microsoft.com/office/word/2010/wordprocessingCanvas",
    "http://schemas.microsoft.com/office/word/2010/wordprocessingGroup",
    "http://schemas.microsoft.com/office/word/2010/wordprocessingInk",
    "http://schemas.microsoft.com/office/word/2010/wordprocessingShape"
};




const char *ns_docx_values[33] = {
    "http://schemas.microsoft.com/office/drawing/2016/ink",
    "http://schemas.microsoft.com/office/drawing/2017/model3d",
    "http://schemas.microsoft.com/office/drawing/2014/chartex",
    "http://schemas.microsoft.com/office/drawing/2015/9/8/chartex",
    "http://schemas.microsoft.com/office/drawing/2015/10/21/chartex",
    "http://schemas.microsoft.com/office/drawing/2016/5/9/chartex",
    "http://schemas.microsoft.com/office/drawing/2016/5/10/chartex",
    "http://schemas.microsoft.com/office/drawing/2016/5/11/chartex",
    "http://schemas.microsoft.com/office/drawing/2016/5/12/chartex",
    "http://schemas.microsoft.com/office/drawing/2016/5/13/chartex",
    "http://schemas.microsoft.com/office/drawing/2016/5/14/chartex",
    "http://schemas.openxmlformats.org/officeDocument/2006/math",
    "http://schemas.openxmlformats.org/markup-compatibility/2006",
    "urn:schemas-microsoft-com:office:office",
    "http://schemas.openxmlformats.org/officeDocument/2006/relationships",
    "urn:schemas-microsoft-com:vml",
    "http://schemas.openxmlformats.org/wordprocessingml/2006/main",
    "urn:schemas-microsoft-com:office:word",
    "http://schemas.microsoft.com/office/word/2010/wordml",
    "http://schemas.microsoft.com/office/word/2012/wordml",
    "http://schemas.microsoft.com/office/word/2018/wordml",
    "http://schemas.microsoft.com/office/word/2018/wordml/cex",
    "http://schemas.microsoft.com/office/word/2016/wordml/cid",
    "http://schemas.microsoft.com/office/word/2020/wordml/sdtdatahash",
    "http://schemas.microsoft.com/office/word/2015/wordml/symex",
    "http://schemas.microsoft.com/office/word/2006/wordml",
    "http://schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing",
    "http://schemas.microsoft.com/office/word/2010/wordprocessingDrawing",
    "http://schemas.microsoft.com/office/word/2010/wordprocessingCanvas",
    "http://schemas.microsoft.com/office/word/2010/wordprocessingGroup",
    "http://schemas.microsoft.com/office/word/2010/wordprocessingInk",
    "http://schemas.microsoft.com/office/word/2010/wordprocessingShape"
};



class docx {
    public:
        /* document pointer */
        xmlDocPtr document;

        docx() {
            document = NULL;
            xmlNodePtr root_node = NULL;

            document = xmlNewDoc(BAD_CAST "1.0");
            root_node = xmlNewNode(NULL, BAD_CAST "document");
            xmlDocSetRootElement(document, root_node);
        };

};