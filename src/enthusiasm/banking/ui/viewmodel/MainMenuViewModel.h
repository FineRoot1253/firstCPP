//
// Created by 홍준근 on 2023/01/18.
//

#ifndef FIRSTCPP_MAINMENUVIEWMODEL_H
#define FIRSTCPP_MAINMENUVIEWMODEL_H

#include "enthusiasm/banking/ui/includes/ViewModel.h"
#include "enthusiasm/banking/infra/EventProvider.h"
#include "enthusiasm/banking/command/service/BankService.h"
#include "enthusiasm/banking/common/HGrowableList.h"
#include "enthusiasm/banking/infra/includes/Listener.h"

class MainMenuViewModel: public ViewModel{
private:
    BankService* bankService;
    int choice;
public:
    MainMenuViewModel(const ViewID& viewId, const EventProvider &eventProvider, BankService* bankService);
    MainMenuViewModel(const MainMenuViewModel &mainMenuViewModel);
    int setChoice();
};

#endif //FIRSTCPP_MAINMENUVIEWMODEL_H
