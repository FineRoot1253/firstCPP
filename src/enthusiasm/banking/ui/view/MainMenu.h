//
// Created by 홍준근 on 2023/01/11.
//

#ifndef FIRSTCPP_MAINMENU_H
#define FIRSTCPP_MAINMENU_H

#include "enthusiasm/banking/ui/includes/View.h"
#include "enthusiasm/banking/ui/viewmodel/MainMenuViewModel.h"

class MainMenu: public View {
private:
    MainMenuViewModel mainMenuViewModel;
protected:
    void render() override;
public:
    virtual ~MainMenu(){};
    MainMenu(const MainMenuViewModel& mainMenuViewModel, const ViewModelEventListener &viewModelEventListener);
};


#endif //FIRSTCPP_MAINMENU_H
