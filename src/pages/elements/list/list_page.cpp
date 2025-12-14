#include "list_page.hpp"

ListPage::ListPage(gui::elementStyle::manager::StyleManager *styleManager, TTF_TextEngine *textEngine,
                           std::function<void(Page *)> changePage)
    : Page(styleManager, textEngine, changePage, "list", "List", "elements/") {
    pages = {};
}

void ListPage::createPage() {

}