#include "introduction_page.hpp"
#include "../../../cpp_gui/src/elements/ui/button.hpp"
#include "../../../cpp_gui/src/elements/ui/label.hpp"
#include "../../../cpp_gui/src/elements/ui/list.hpp"
#include <vector>

Introduction::Introduction(gui::elementStyle::manager::StyleNodesManager *styleManager, TTF_TextEngine *textEngine,
                           std::function<void(Page *)> changePage)
    : Page(styleManager, textEngine, changePage, "introduction", "Introduction (What is cpp gui?)") {}

void Introduction::createPage() {
    gui::element::UiElement *pagesList = new gui::element::List(styleManager, nullptr, "pages-list");
    rootElement = pagesList;
    // very strange behavior

    pagesList->addChild(new gui::element::Label(
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed metus nulla, porttitor id eleifend a, vehicula at odio. Duis et dui a sem "
        "suscipit tristique sed id neque. Proin sit amet tellus sed mi tempor mattis at ut arcu. Nunc aliquam dictum venenatis. Phasellus aliquam "
        "dictum dui fringilla egestas. Mauris eu pharetra arcu. Praesent massa est, tincidunt quis elementum non, dignissim eget lectus. Curabitur "
        "varius dolor eget nulla fermentum dapibus",
        styleManager, nullptr, "", textEngine));
    pagesList->addChild(new gui::element::Label(
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed metus nulla, porttitor id eleifend a, vehicula at odio. Duis et dui a sem "
        "suscipit tristique sed id neque. Proin sit amet tellus sed mi tempor mattis at ut arcu. Nunc aliquam dictum venenatis. Phasellus aliquam "
        "dictum dui fringilla egestas. Mauris eu pharetra arcu. Praesent massa est, tincidunt quis elementum non, dignissim eget lectus. Curabitur "
        "varius dolor eget nulla fermentum dapibus."
        "Nullam eu felis id justo posuere porttitor in non arcu. Integer gravida aliquam justo, at laoreet augue scelerisque quis. Mauris eget leo "
        "velit. Vestibulum purus libero, imperdiet sed ornare in, ultricies id turpis. Vivamus vel commodo lorem. In porttitor mauris posuere "
        "posuere varius. Phasellus l", // exceeding 2473 chars causes text not to be displayed
        styleManager, nullptr, "", textEngine));
}
