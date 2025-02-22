#include "page_manager.hpp"

PageManager::PageManager(SDL_Window *window, SDL_Renderer *renderer)
    : uiManager{new gui::element::manager::UIManager(window, renderer)}, styleManager{new gui::elementStyle::manager::ElementsStyleManager()} {

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

void PageManager::processEvent(const SDL_Event &event) const { uiManager->processEvent(event); }

void PageManager::processMouseEvents() const { uiManager->processMouseEvents(); }

void PageManager::render() const { uiManager->render(); }

void PageManager::createPageStructure() {
    styleManager->setFontsPath("src/pages/fonts");
    styleManager->addStyleFile("src/pages/page-structure-style.style");

    rootElement = new gui::element::List(styleManager, nullptr, "root-page");
    uiManager->setElementsTree(rootElement);

    gui::element::UIElement *headerList = new gui::element::Container(styleManager, nullptr, "header-list");
    rootElement->addChild(headerList);

    std::vector<std::string> pagesClasses = std::vector<std::string>{"back-button"};
    gui::element::UIElement *button = new gui::element::Button(
        [this]() { askChangingPage(new IndexPage(styleManager, textEngine, std::bind(&PageManager::askChangingPage, this, std::placeholders::_1))); },
        styleManager, &pagesClasses, "");
    headerList->addChild(button);
    button->addChild(new gui::element::Label("Back to index", styleManager, {}, "", textEngine));

    pageNameLabel = new gui::element::Label("", styleManager, nullptr, "page-name", textEngine);
    headerList->addChild(pageNameLabel);

    currentPageElement = new gui::element::Container(styleManager, nullptr, "page-content");
    rootElement->addChild(currentPageElement);
}

void PageManager::askChangingPage(Page *newPage) { askedNewPage = newPage; }

void PageManager::changePage(Page *newPage) {
    currentPageElement->removeChilds();
    if (currentPage != nullptr) currentPage->unsetFocus();

    currentPage = newPage;
    if (currentPage != nullptr) {
        currentPage->setFocus();
        gui::element::UIElement *newPage = currentPage->elements();
        currentPageElement->addChild(newPage);

        pageNameLabel->setText(currentPage->name());
    }
    uiManager->resetEvents();
}

void PageManager::update() {
    if (askedNewPage != nullptr) {
        changePage(askedNewPage);
        askedNewPage = nullptr;
    }
}
