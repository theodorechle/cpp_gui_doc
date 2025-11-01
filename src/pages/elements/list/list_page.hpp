#ifndef LIST_PAGE_HPP
#define LIST_PAGE_HPP

#include "../../page.hpp"

#include "../../../../cpp_gui/src/elements/ui/list.hpp"
#include "../../../../cpp_gui/src/elements/ui/button.hpp"
#include "../../../../cpp_gui/src/elements/ui/label.hpp"

class ListPage : public Page {
    std::list<Page *> pages;

public:
    ListPage(style::elementStyle::manager::StyleNodesManager *styleManager, TTF_TextEngine *textEngine,
                 std::function<void(Page *)> changePage);

    void createPage() override;
};

#endif // LIST_PAGE_HPP
