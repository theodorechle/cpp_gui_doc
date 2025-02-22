#ifndef APP_STATE_HPP
#define APP_STATE_HPP

#include "../pages/manager/page_manager.hpp"
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

/**
 * Only exists for testing the gui
 */
class AppState {
    PageManager *pageManager;

public:
    AppState(PageManager *pageManager);
    ~AppState();
    PageManager *getPageManager();
};

#endif // APP_STATE_HPP
