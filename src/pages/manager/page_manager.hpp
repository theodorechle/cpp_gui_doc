#ifndef PAGE_MANAGER_HPP
#define PAGE_MANAGER_HPP

#include "../../../cpp_gui/src/elements/ui/button.hpp"
#include "../../../cpp_gui/src/elements/ui/container.hpp"
#include "../../../cpp_gui/src/elements/ui/label.hpp"
#include "../../../cpp_gui/src/elements/ui/list.hpp"
#include "../../../cpp_gui/src/elements/ui/ui_manager.hpp"
#include "../../../cpp_gui/src/elements/ui/ui_element.hpp"
#include "../../../cpp_gui/src/style_nodes/style_nodes_manager.hpp"

#include "../index/index_page.hpp"
#include "../page.hpp"

#include <SDL3/SDL.h>
#include <functional>
#include <map>

class PageManager {
    TTF_TextEngine *textEngine = nullptr;

    gui::element::manager::UIManager *uiManager = nullptr;
    gui::element::UiElement *rootElement = nullptr;
    gui::element::UiElement *currentPageElement = nullptr;
    gui::elementStyle::manager::StyleNodesManager *styleManager = nullptr;
    Page *currentPage = nullptr;
    Page *askedNewPage = nullptr;

    gui::element::Label *pageNameLabel = nullptr;

    Page *findPage(const std::string &pageName);

    void createPageStructure();

    void askChangingPage(Page *newPage);
    void changePage(Page *newPage);

public:
    PageManager(SDL_Window *window, SDL_Renderer *renderer);
    ~PageManager();

    void processEvent(const SDL_Event &event) const;
    void processMouseEvents() const;
    void render() const;

    void update();
};

#endif // PAGE_MANAGER_HPP
