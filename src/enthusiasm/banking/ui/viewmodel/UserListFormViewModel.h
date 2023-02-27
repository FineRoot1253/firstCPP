//
// Created by 홍준근 on 2023/01/18.
//

#ifndef FIRSTCPP_USERLISTFORMVIEWMODEL_H
#define FIRSTCPP_USERLISTFORMVIEWMODEL_H

#include "enthusiasm/banking/ui/includes/ViewModel.h"
#include "enthusiasm/banking/common/HGrowableList.h"
#include "enthusiasm/banking/command/service/BankService.h"
#include "enthusiasm/banking/common/HGrowableList.h"
#include "enthusiasm/banking/infra/includes/Listener.h"

class UserListFormViewModel : public ViewModel{
private:
    BankService* bankService;
public:
    UserListFormViewModel(const ViewID& viewId, const EventProvider &eventViewModel, BankService* bankService);
    UserListFormViewModel(const UserListFormViewModel& userListFormViewModel);

    const HGrowableList<Account*>& getuserList();
};




#endif //FIRSTCPP_USERLISTFORMVIEWMODEL_H
