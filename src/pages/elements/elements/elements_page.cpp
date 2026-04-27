#include "elements_page.hpp"

ElementsPage::ElementsPage(gui::elementStyle::manager::StyleManager *styleManager, TTF_TextEngine *textEngine, std::function<void(Page *)> changePage)
    : Page(styleManager, textEngine, changePage, "elements", "Elements", "elements/") {
    pages = {
        new ListPage(styleManager, textEngine, changePage), new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage), new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage), new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage), new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage), new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage), new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage), new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage), new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage), new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage), new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage), new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage), new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage), new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage), new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage), new ListPage(styleManager, textEngine, changePage),
        new ListPage(styleManager, textEngine, changePage), new ListPage(styleManager, textEngine, changePage),
    };
}

void ElementsPage::createPage() {
    gui::element::UiElement *elements = new gui::element::List(styleManager, {}, "elements");
    rootElement = elements;

    gui::element::UiElement *button;

    for (Page *page : pages) {
        button = new gui::element::Button([this, page](const gui::element::event::Event *) { changePageFocused(page); }, styleManager,
                                          {"element-button"}, "");
        button->addChild(new gui::element::Label(page->name(), styleManager, {}, "", textEngine));
        rootElement->addChild(button);
    }
    rootElement->addChild(new gui::element::Label("end", styleManager, {}, "", textEngine));
}