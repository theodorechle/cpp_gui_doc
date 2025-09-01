#include "elements_page.hpp"

ElementsPage::ElementsPage(gui::elementStyle::manager::StyleNodesManager *styleManager, TTF_TextEngine *textEngine,
                           std::function<void(Page *)> changePage)
    : Page(styleManager, textEngine, changePage, "elements", "Elements", "elements/") {
    pages = {
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage),
    };
}

void ElementsPage::createPage() {
    gui::element::UiElement *elements = new gui::element::List(styleManager, nullptr, "elements");
    rootElement = elements;

    std::vector<std::string> elementButtonClasses = std::vector<std::string>{"element-button"};

    gui::element::UiElement *button;

    for (Page *page : pages) {
        button = new gui::element::Button([this, page]() { changePageFocused(page); }, styleManager, &elementButtonClasses, "");
        button->addChild(new gui::element::Label(page->name(), styleManager, nullptr, "", textEngine));
        rootElement->addChild(button);
    }
    rootElement->addChild(new gui::element::Label("end", styleManager, nullptr, "", textEngine));
}