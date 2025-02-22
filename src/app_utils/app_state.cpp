#include "app_state.hpp"

AppState::AppState(PageManager *pageManager) : pageManager{pageManager} {}

AppState::~AppState() { delete pageManager; }

PageManager *AppState::getPageManager() { return pageManager; }
