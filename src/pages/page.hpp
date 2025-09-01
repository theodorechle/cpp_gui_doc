#ifndef PAGE_HPP
#define PAGE_HPP

#include "../../cpp_gui/src/elements/ui/ui_element.hpp"
#include "../../cpp_gui/src/style_nodes/style_nodes_manager.hpp"

#include <functional>

class Page {
protected:
    gui::element::UiElement *rootElement = nullptr;
    gui::elementStyle::manager::StyleNodesManager *styleManager = nullptr;
    TTF_TextEngine *textEngine;

private:
    const std::string PAGE_PATH = "src/pages/";

    std::string styleFile;
    std::string pageName;
    int fileNumber = -1;
    bool focus = false;
    std::function<void(Page *page)> changePage;
    std::string middlePath;

public:
    /**
     * styleFile must be relative to the 'pages' folder
     */
    Page(gui::elementStyle::manager::StyleNodesManager *styleManager, TTF_TextEngine *textEngine, std::function<void(Page *page)> changePage,
         const std::string &styleFile = "", const std::string &pageName = "", const std::string &middlePath = "");

    virtual ~Page();

    /**
     * Create all elements in the page
     */
    virtual void createPage() = 0;

    void setFocus();
    void unsetFocus();

    void changePageFocused(Page *newPage);

    gui::element::UiElement *elements();

    const std::string &name();
};

#endif // PAGE_HPP
