#include "introduction_page.hpp"
#include "../../../cpp_gui/src/elements/button.hpp"
#include "../../../cpp_gui/src/elements/label.hpp"
#include "../../../cpp_gui/src/elements/list.hpp"
#include <vector>

Introduction::Introduction(gui::elementStyle::manager::ElementsStyleManager *styleManager, TTF_TextEngine *textEngine,
                           std::function<void(Page *)> changePage)
    : Page(styleManager, textEngine, changePage, "introduction", "Introduction (What is cpp gui?)") {}

void Introduction::createPage() {
    gui::element::UIElement *pagesList = new gui::element::List(styleManager, nullptr, "pages-list");
    rootElement = pagesList;
}
