#include "tests_page.hpp"

TestsPage::TestsPage(gui::elementStyle::manager::ElementsStyleManager *styleManager, TTF_TextEngine *textEngine,
                     std::function<void(Page *)> changePage)
    : Page(styleManager, textEngine, changePage, "tests", "Tests") {}

void TestsPage::createPage() {}
