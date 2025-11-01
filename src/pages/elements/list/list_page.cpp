#include "list_page.hpp"

ListPage::ListPage(style::elementStyle::manager::StyleNodesManager *styleManager, TTF_TextEngine *textEngine,
                           std::function<void(Page *)> changePage)
    : Page(styleManager, textEngine, changePage, "list", "List", "elements/") {
    pages = {};
}

void ListPage::createPage() {

}