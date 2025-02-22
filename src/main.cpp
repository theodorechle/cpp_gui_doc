#include "../cpp_gui/src/elements/button.hpp"
#include "../cpp_gui/src/elements/container.hpp"
#include "../cpp_gui/src/elements/input.hpp"
#include "../cpp_gui/src/elements/label.hpp"
#include "../cpp_gui/src/elements/list.hpp"
#include "../cpp_gui/src/elements/managers/abstract_manager.hpp"
#include "../cpp_gui/src/elements/managers/ui_manager.hpp"
#include "../cpp_gui/src/elements/ui_element.hpp"
#include "../cpp_gui/src/elements_style/element_style.hpp"
#include "../cpp_gui/src/elements_style/managers/elements_style_manager.hpp"
#include "../cpp_gui/src/style/style_deserializer.hpp"
#include "app_utils/app_state.hpp"
#include "pages/manager/page_manager.hpp"

#define SDL_MAIN_USE_CALLBACKS 1 /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_ttf/SDL_ttf.h>

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {
    int windowLength = 500;
    int windowHeight = 500;
    SDL_Window *sdl_window = nullptr;
    SDL_Renderer *sdl_renderer = nullptr;

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL! %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!TTF_Init()) {
        SDL_Log("Couldn't initialize SDL TTF! %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("GUI Tests", windowLength, windowHeight, SDL_WINDOW_RESIZABLE, &sdl_window, &sdl_renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_SetRenderDrawBlendMode(sdl_renderer, SDL_BLENDMODE_BLEND);

    *appstate = new AppState(new PageManager(sdl_window, sdl_renderer));

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
    AppState *state = static_cast<AppState *>(appstate);
    state->getPageManager()->processEvent(*event);
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
    AppState *state = static_cast<AppState *>(appstate);
    PageManager *manager = state->getPageManager();
    manager->processMouseEvents();
    manager->update();
    manager->render();
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
    AppState *state = static_cast<AppState *>(appstate);
    delete state;
    TTF_Quit();
}
