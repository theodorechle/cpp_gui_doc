#ifndef INDEX_PAGE_HPP
#define INDEX_PAGE_HPP

#include "../elements/elements/elements_page.hpp"
#include "../introduction/introduction_page.hpp"
#include "../page.hpp"
#include "../style/style_page.hpp"
#include "../tests/tests_page.hpp"

#include <vector>

#include "../../../cpp_gui/src/elements/ui/button.hpp"
#include "../../../cpp_gui/src/elements/ui/label.hpp"
#include "../../../cpp_gui/src/elements/ui/list.hpp"

class IndexPage : public Page {
    std::list<Page *> pages;

public:
    IndexPage(style::elementStyle::manager::StyleNodesManager *styleManager, TTF_TextEngine *textEngine, std::function<void(Page *)> changePage);

    void createPage() override;
};

#endif // INDEX_PAGE_HPP
