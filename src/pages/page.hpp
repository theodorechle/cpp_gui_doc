#ifndef PAGE_HPP
#define PAGE_HPP

#include "../../cpp_gui/src/elements/ui_element.hpp"
#include "../../cpp_gui/src/elements_style/managers/elements_style_manager.hpp"

#include <functional>

class Page {
protected:
    gui::element::UIElement *rootElement = nullptr;
    gui::elementStyle::manager::ElementsStyleManager *styleManager = nullptr;
    TTF_TextEngine *textEngine;

private:
    const std::string PAGE_PATH = "src/pages/";

    std::string styleFile;
    std::string pageName;
    int fileNumber = -1;
    bool focus = false;
    std::function<void(Page *page)> changePage;

public:
    /**
     * styleFile must be relative to the 'pages' folder
     */
    Page(gui::elementStyle::manager::ElementsStyleManager *styleManager, TTF_TextEngine *textEngine, std::function<void(Page *page)> changePage,
         const std::string &styleFile = "", const std::string &pageName = "");

    virtual ~Page();

    /**
     * Create all elements in the page
     */
    virtual void createPage() = 0;

    void setFocus();
    void unsetFocus();

    void changePageFocused(Page *newPage);

    gui::element::UIElement *elements();

    const std::string &name();
};

#endif // PAGE_HPP
