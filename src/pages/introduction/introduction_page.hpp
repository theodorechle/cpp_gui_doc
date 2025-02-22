#ifndef INTRODUCTION_HPP
#define INTRODUCTION_HPP

#include "../page.hpp"

class Introduction : public Page {
public:
    Introduction(gui::elementStyle::manager::ElementsStyleManager *styleManager, TTF_TextEngine *textEngine, std::function<void(Page *)> changePage);

    void createPage() override;
};

#endif // INTRODUCTION_HPP
