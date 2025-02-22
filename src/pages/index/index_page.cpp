#include "index_page.hpp"
#include "../../../cpp_gui/src/elements/button.hpp"
#include "../../../cpp_gui/src/elements/label.hpp"
#include "../../../cpp_gui/src/elements/list.hpp"

#include "../elements/elements_page.hpp"
#include "../introduction/introduction_page.hpp"
#include "../style/style_page.hpp"
#include "../tests/tests_page.hpp"

#include <vector>

IndexPage::IndexPage(gui::elementStyle::manager::ElementsStyleManager *styleManager, TTF_TextEngine *textEngine,
                     std::function<void(Page *)> changePage)
    : Page(styleManager, textEngine, changePage, "index", "Index") {
    pages = {new Introduction(styleManager, textEngine, changePage), new ElementsPage(styleManager, textEngine, changePage),
             new StylePage(styleManager, textEngine, changePage), new TestsPage(styleManager, textEngine, changePage)};
}

void IndexPage::createPage() {
    gui::element::UIElement *pagesList = new gui::element::List(styleManager, nullptr, "pages-list");
    rootElement = pagesList;

    std::vector<std::string> pagesClasses = std::vector<std::string>{"page"};

    gui::element::UIElement *button;

    for (Page *page : pages) {
        if (page == this) continue;
        button = new gui::element::Button([this, page]() { changePageFocused(page); }, styleManager, &pagesClasses, "");
        rootElement->addChild(button);
        button->addChild(new gui::element::Label(page->name(), styleManager, {}, "", textEngine));
    }
}