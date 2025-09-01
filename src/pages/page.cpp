#include "page.hpp"

Page::Page(gui::elementStyle::manager::StyleNodesManager *styleManager, TTF_TextEngine *textEngine, std::function<void(Page *page)> changePage,
           const std::string &styleFile, const std::string &pageName, const std::string &middlePath)
    : styleManager{styleManager}, textEngine{textEngine}, styleFile{styleFile}, pageName{pageName}, changePage{changePage}, middlePath{middlePath} {}

Page::~Page() { delete rootElement; }

void Page::setFocus() {
    if (focus) return;
    focus = true;
    fileNumber = styleManager->addStyleFile(PAGE_PATH + middlePath + styleFile + "/" + styleFile + "_page.style");
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

gui::element::UiElement *Page::elements() { return rootElement; }

const std::string &Page::name() { return pageName; }
