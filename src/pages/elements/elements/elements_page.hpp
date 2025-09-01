#ifndef ELEMENTS_PAGE_HPP
#define ELEMENTS_PAGE_HPP

#include "../../page.hpp"
#include "../list/list_page.hpp"

#include "../../../../cpp_gui/src/elements/ui/list.hpp"
#include "../../../../cpp_gui/src/elements/ui/button.hpp"
#include "../../../../cpp_gui/src/elements/ui/label.hpp"

class ElementsPage : public Page {
    std::list<Page *> pages;

public:
    ElementsPage(gui::elementStyle::manager::StyleNodesManager *styleManager, TTF_TextEngine *textEngine,
                 std::function<void(Page *)> changePage);

    void createPage() override;
};

#endif // ELEMENTS_PAGE_HPP
