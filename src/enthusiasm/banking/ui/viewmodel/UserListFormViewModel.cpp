//
// Created by 홍준근 on 2023/01/18.
//

#include "UserListFormViewModel.h"

UserListFormViewModel::UserListFormViewModel(const ViewID &viewId, const EventProvider &eventProvider, BankService *bankService)
        : ViewModel(viewId, eventProvider)
          , bankService(bankService) {
}

UserListFormViewModel::UserListFormViewModel(const UserListFormViewModel &userListFormViewModel)
        : ViewModel(userListFormViewModel.getViewId(), userListFormViewModel)
        , bankService(userListFormViewModel.bankService) {
}

const HGrowableList<Account*> &UserListFormViewModel::getuserList() {
    return bankService->findAll();
}
