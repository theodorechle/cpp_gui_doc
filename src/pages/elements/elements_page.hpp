#ifndef ELEMENTS_PAGE_HPP
#define ELEMENTS_PAGE_HPP

#include "../page.hpp"

class ElementsPage : public Page {

public:
    ElementsPage(gui::elementStyle::manager::ElementsStyleManager *styleManager, TTF_TextEngine *textEngine,
                 std::function<void(Page *)> changePage);

    void createPage() override;
};

#endif // ELEMENTS_PAGE_HPP
