#ifndef PAGE_MANAGER_HPP
#define PAGE_MANAGER_HPP

#include "../../../cpp_gui/src/elements/ui/button.hpp"
#include "../../../cpp_gui/src/elements/ui/container.hpp"
#include "../../../cpp_gui/src/elements/ui/label.hpp"
#include "../../../cpp_gui/src/elements/ui/list.hpp"
#include "../../../cpp_gui/src/elements/ui/ui_element.hpp"
#include "../../../cpp_gui/src/elements/ui/ui_manager.hpp"
#include "../../../cpp_gui/cpp_style/src/style_nodes/style_nodes_manager.hpp"

#include "../index/index_page.hpp"
#include "../page.hpp"

#include <SDL3/SDL_events.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <functional>
#include <map>

class PageManager {
    TTF_TextEngine *textEngine = nullptr;

    gui::element::manager::UIManager *uiManager = nullptr;
    gui::element::UiElement *rootElement = nullptr;
    gui::element::UiElement *currentPageElement = nullptr;
    style::elementStyle::manager::StyleNodesManager *styleManager = nullptr;
    Page *currentPage = nullptr;
    Page *askedNewPage = nullptr;

    gui::element::Label *pageNameLabel = nullptr;

    void createPageStructure();

    void askChangingPage(Page *newPage);
    void changePage(Page *newPage);

public:
    PageManager(SDL_Window *window, SDL_Renderer *renderer);
    ~PageManager();

    void processEvent(const SDL_Event &event) const;
    void render() const;

    void update();
};

#endif // PAGE_MANAGER_HPP
