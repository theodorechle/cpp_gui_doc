#ifndef STYLE_PAGE_HPP
#define STYLE_PAGE_HPP

#include "../page.hpp"

class StylePage : public Page {

public:
    StylePage(style::elementStyle::manager::StyleNodesManager *styleManager, TTF_TextEngine *textEngine, std::function<void(Page *)> changePage);

    void createPage() override;
};

#endif // STYLE_PAGE_HPP
