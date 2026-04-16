#include "index_page.hpp"
#include "../../../cpp_gui/src/elements/ui/input.hpp"

IndexPage::IndexPage(gui::elementStyle::manager::StyleManager *styleManager, TTF_TextEngine *textEngine, std::function<void(Page *)> changePage)
    : Page(styleManager, textEngine, changePage, "index", "Index") {
    pages = {new Introduction(styleManager, textEngine, changePage), new ElementsPage(styleManager, textEngine, changePage),
             new StylePage(styleManager, textEngine, changePage), new TestsPage(styleManager, textEngine, changePage)};
}

void IndexPage::createPage() {
    gui::element::UiElement *pagesList = new gui::element::List(styleManager, nullptr, "pages-list");
    rootElement = pagesList;

    std::vector<std::string> pagesClasses = std::vector<std::string>{"page"};

    gui::element::UiElement *button;

    for (Page *page : pages) {
        button =
            new gui::element::Button([this, page](const gui::element::event::Event *) { changePageFocused(page); }, styleManager, &pagesClasses, "");
        button->addChild(new gui::element::Label(page->name(), styleManager, nullptr, "", textEngine));
        rootElement->addChild(button);
    }
}