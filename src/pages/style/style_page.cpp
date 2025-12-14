#include "style_page.hpp"

StylePage::StylePage(gui::elementStyle::manager::StyleManager *styleManager, TTF_TextEngine *textEngine,
                     std::function<void(Page *)> changePage)
    : Page(styleManager, textEngine, changePage, "style", "Style") {}

void StylePage::createPage() {}
