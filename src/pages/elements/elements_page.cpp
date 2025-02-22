#include "elements_page.hpp"

ElementsPage::ElementsPage(gui::elementStyle::manager::ElementsStyleManager *styleManager, TTF_TextEngine *textEngine,
                           std::function<void(Page *)> changePage)
    : Page(styleManager, textEngine, changePage, "elements/style.style", "Elements") {}

void ElementsPage::createPage() {}
