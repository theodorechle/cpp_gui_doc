#ifndef TESTS_PAGE_HPP
#define TESTS_PAGE_HPP

#include "../page.hpp"

class TestsPage : public Page {

public:
    TestsPage(gui::elementStyle::manager::ElementsStyleManager *styleManager, TTF_TextEngine *textEngine, std::function<void(Page *)> changePage);

    void createPage() override;
};
#endif // TESTS_PAGE_HPP
