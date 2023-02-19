//
// Created by 홍준근 on 2023/01/18.
//

#include "MainMenuViewModel.h"

using namespace utils::Parser;

MainMenuViewModel::MainMenuViewModel(const ViewID &viewId, const EventProvider &eventProvider,
                                     BankService *bankService)
        : ViewModel(viewId, eventProvider)
          , choice(-1)
          , bankService(bankService) {
}

MainMenuViewModel::MainMenuViewModel(const MainMenuViewModel &mainMenuViewModel)
        : choice(-1)
          , ViewModel(mainMenuViewModel.getViewId(),mainMenuViewModel)
          , bankService(mainMenuViewModel.bankService) {
}

int MainMenuViewModel::setChoice() {
    std::cout << "선택: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            EventProvider::getTo(ViewID(viewTypeToConstLong(eViewType::MakeAccountForm)));
            break;
        case 2:
            EventProvider::getTo(ViewID(viewTypeToConstLong(eViewType::DepositForm)));
            break;
        case 3:
            EventProvider::getTo(ViewID(viewTypeToConstLong(eViewType::WithdrawForm)));
            break;
        case 4:
            EventProvider::getTo(ViewID(viewTypeToConstLong(eViewType::UserListForm)));
            break;
        case 5:
            throw SystemCallException(constants::ex_kr::EX_MSG_SYS_STOP);
        default:
            throw SystemCallException(constants::ex_kr::EX_MSG_SYS_ILLEGAL_INPUT);
    }
}
