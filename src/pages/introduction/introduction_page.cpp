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

    pagesList->addChild(new gui::element::Label(
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed metus nulla, porttitor id eleifend a, vehicula at odio. Duis et dui a sem "
        "suscipit tristique sed id neque. Proin sit amet tellus sed mi tempor mattis at ut arcu. Nunc aliquam dictum venenatis. Phasellus aliquam "
        "dictum dui fringilla egestas. Mauris eu pharetra arcu. Praesent massa est, tincidunt quis elementum non, dignissim eget lectus. Curabitur "
        "varius dolor eget nulla fermentum dapibus."
        "Nullam eu felis id justo posuere porttitor in non arcu. Integer gravida aliquam justo, at laoreet augue scelerisque quis. Mauris eget leo "
        "velit. Vestibulum purus libero, imperdiet sed ornare in, ultricies id turpis. Vivamus vel commodo lorem. In porttitor mauris posuere "
        "posuere varius. Phasellus laoreet quis eros vel aliquet."
        "Proin eu pulvinar dolor. Proin nec enim vitae risus rutrum molestie et a erat. Quisque tempor elit vel arcu convallis maximus. In ipsum "
        "metus, sodales vitae urna in, aliquam cursus quam. Cras in risus sapien. Nam eleifend lorem diam, non eleifend justo sodales a. Sed "
        "ultrices erat at dui congue imperdiet. Pellentesque odio nunc, mattis vitae libero id, ultricies ornare nibh. Curabitur in venenatis "
        "libero, quis vestibulum odio. Pellentesque in interdum lacus. Vestibulum libero purus, consequat in vehicula vitae, tristique quis libero. "
        "Duis eget faucibus tortor. Maecenas placerat semper mauris sed venenatis. Aenean congue sit amet nunc vel feugiat."
        "Morbi condimentum elit enim, eu volutpat eros viverra non. Quisque luctus mollis aliquam. Fusce posuere vehicula aliquam. Mauris vel "
        "laoreet arcu. Pellentesque dolor risus, scelerisque in pulvinar id, congue rutrum eros. Sed magna tellus, imperdiet ultricies lobortis a, "
        "aliquet vel massa. Mauris est mi, porttitor eget vestibulum eu, semper vel ante. Nullam dui arcu, vulputate eu tincidunt non, pretium eget "
        "felis. Nullam congue lacus non tristique porttitor. Donec gravida facilisis est, quis dictum enim varius vitae. Vivamus ac nunc vel odio "
        "imperdiet maximus."
        "Sed sed dictum neque. Duis fermentum augue vel lectus venenatis dictum. Praesent felis turpis, vestibulum eget augue in, cursus feugiat "
        "erat. Aliquam lorem ex, tempus ut nisi in, condimentum vestibulum nibh. Duis sit amet eleifend magna. Aenean sed dolor est. Pellentesque "
        "dignissim eget eros non feugiat. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Vivamus "
        "venenatis, massa vitae consectetur accumsan, ante erat porta est, sed aliquet nisi diam et eros.",
        styleManager, nullptr, "", textEngine));
}
