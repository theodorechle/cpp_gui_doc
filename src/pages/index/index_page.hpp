#ifndef INDEX_PAGE_HPP
#define INDEX_PAGE_HPP

#include "../page.hpp"

class IndexPage : public Page {
    std::list<Page *> pages;

public:
    IndexPage(gui::elementStyle::manager::ElementsStyleManager *styleManager, TTF_TextEngine *textEngine, std::function<void(Page *)> changePage);

    void createPage() override;
};

#endif // INDEX_PAGE_HPP
