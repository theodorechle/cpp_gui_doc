#include "page_manager.hpp"

PageManager::PageManager(SDL_Window *window, SDL_Renderer *renderer)
    : uiManager{new gui::element::manager::UiManager(window, renderer)},
      styleManager{new gui::elementStyle::manager::StyleManager(style::config::config())} {
    uiManager->styleManager(styleManager);
    textEngine = TTF_CreateRendererTextEngine(renderer);

    if (textEngine == nullptr) {
        SDL_Log("Can't create a renderer text engine %s", SDL_GetError());
    }

    createPageStructure();

    askChangingPage(new IndexPage(styleManager, textEngine, std::bind(&PageManager::askChangingPage, this, std::placeholders::_1)));
}

PageManager::~PageManager() {
    currentPageElement->removeChilds();
    delete uiManager;
    delete styleManager;
    TTF_DestroyRendererTextEngine(textEngine);
}

void PageManager::processEvent(const SDL_Event *event) const { uiManager->processEvent(event); }

void PageManager::render() const { uiManager->render(); }

void PageManager::createPageStructure() {
    styleManager->addDefaultFontPath("src/pages/fonts");
    styleManager->addStyleFile("src/pages/page-structure.style");

    rootElement = new gui::element::List(styleManager, nullptr, "root-page");
    uiManager->setSubRootElement(rootElement);

    gui::element::UiElement *headerList = new gui::element::List(styleManager, nullptr, "header-list");
    rootElement->addChild(headerList);

    std::vector<std::string> pagesClasses = std::vector<std::string>{"back-button"};
    gui::element::UiElement *button = new gui::element::Button(
        [this]() { askChangingPage(new IndexPage(styleManager, textEngine, std::bind(&PageManager::askChangingPage, this, std::placeholders::_1))); },
        styleManager, &pagesClasses, "");
    headerList->addChild(button);
    button->addChild(new gui::element::Label("Back to index", styleManager, nullptr, "", textEngine));

    pageNameLabel = new gui::element::Label("", styleManager, nullptr, "page-name", textEngine);
    headerList->addChild(pageNameLabel);

    currentPageElement = new gui::element::Container(styleManager, nullptr, "page-content");
    rootElement->addChild(currentPageElement);
}

void PageManager::askChangingPage(Page *newPage) {
#ifdef DEBUG
    SDL_Log("ask changing page\n");
#endif
    askedNewPage = newPage;
}

void PageManager::changePage(Page *newPage) {
    currentPageElement->removeChilds();
    if (currentPage != nullptr) currentPage->unsetFocus();
    // FIXME: when changing page, it said "Can't create a texture for an ui_render_node" and after it is able to draw it
    // it seems like it tries to draw it before size is computed, and recompute and displays it after

    currentPage = newPage;
    if (currentPage != nullptr) {
        currentPage->setFocus();
        gui::element::UiElement *newPageElement = currentPage->elements();
        currentPageElement->addChild(newPageElement);

        pageNameLabel->text(currentPage->name());
    }
}

void PageManager::update() {
    if (askedNewPage != nullptr) {
        changePage(askedNewPage);
        askedNewPage = nullptr;
    }
}
