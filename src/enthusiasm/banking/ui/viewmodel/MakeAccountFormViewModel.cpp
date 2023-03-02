//
// Created by 홍준근 on 2023/01/18.
//

#include "MakeAccountFormViewModel.h"

MakeAccountFormViewModel::MakeAccountFormViewModel(const ViewID &viewId, const EventProvider &eventProvider,BankService *bankService)
        : ViewModel(viewId, eventProvider)
        , accountInputDto()
        , bankService(bankService) {
}

MakeAccountFormViewModel::MakeAccountFormViewModel(const MakeAccountFormViewModel &makeAccountFormViewModel)
        : ViewModel(makeAccountFormViewModel.getViewId(), makeAccountFormViewModel)
        , accountInputDto()
        , bankService(makeAccountFormViewModel.bankService) {

}

void MakeAccountFormViewModel::setAccount() {
    std::cin >> accountInputDto;
    const Error &result = bankService->makeAccount(accountInputDto);
    if (result.isError()) {
        throw AccountSystemException(result.getReason());
    }
    EventProvider::notify();
}

void MakeAccountFormViewModel::reset() {
    accountInputDto = AccountInputDto();
}

bool MakeAccountFormViewModel::isLoaded() const {
    if(accountInputDto.getAccountID()!= 0){
        return true;
    }
    return false;
}
