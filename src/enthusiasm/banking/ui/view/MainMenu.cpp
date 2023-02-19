//
// Created by 홍준근 on 2023/01/11.
//

#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu(const MainMenuViewModel& mainMenuViewModel, const ViewModelEventListener &viewModelEventListener)
: mainMenuViewModel(mainMenuViewModel), View(viewModelEventListener){
}

void MainMenu::render() {
    std::cout<<"----Menu----"<<std::endl;
    std::cout<<"1. 계좌개설"<<std::endl;
    std::cout<<"2. 입 금"<<std::endl;
    std::cout<<"3. 출 금"<<std::endl;
    std::cout<<"4. 계좌정보 전체 출력"<<std::endl;
    std::cout<<"5. 프로그램 종료"<<std::endl;
    mainMenuViewModel.setChoice();
}
