#include "page.hpp"

Page::Page(gui::elementStyle::manager::ElementsStyleManager *styleManager, TTF_TextEngine *textEngine, std::function<void(Page *page)> changePage,
           const std::string &styleFile, const std::string &pageName)
    : styleManager{styleManager}, textEngine{textEngine}, styleFile{styleFile}, pageName{pageName}, changePage{changePage} {}

Page::~Page() { delete rootElement; }

void Page::setFocus() {
    if (focus) return;
    focus = true;
    fileNumber = styleManager->addStyleFile(PAGE_PATH + styleFile + "/" + styleFile + "_page.style");
    createPage();
}

void Page::unsetFocus() {
    if (!focus) return;
    focus = false;
    delete rootElement;
    rootElement = nullptr;
    styleManager->removeStyle(fileNumber);
}

void Page::changePageFocused(Page *newPage) { changePage(newPage); }

gui::element::UIElement *Page::elements() { return rootElement; }

const std::string &Page::name() { return pageName; }
