//
// Created by 홍준근 on 2023/01/18.
//

#include "DepositFormViewModel.h"

using namespace utils::Parser;

DepositFormViewModel::DepositFormViewModel(const ViewID &viewId, const EventProvider &eventProvider,
                                           BankService *bankService)
        : ViewModel(viewId, eventProvider)
          , moneyInputDto(eBankingMode::Deposit)
          , bankService(bankService) {
}

DepositFormViewModel::DepositFormViewModel(const DepositFormViewModel &depositFormViewModel)
        : ViewModel(depositFormViewModel.getViewId(), depositFormViewModel)
          , moneyInputDto(-1L, 0, eBankingMode::Deposit)
          , bankService(depositFormViewModel.bankService) {
}

void DepositFormViewModel::setMoneyInputDto() {
    std::cin >> moneyInputDto;
    Error result = bankService->depositMoney(moneyInputDto);
    if (result.isError()) {
        throw AccountSystemException(result.getReason());
    }
    EventProvider::notify();
}

BaseReturnDto<Account*> DepositFormViewModel::getMoneyInputResult() const {
    if(moneyInputDto.getAccountID() != -1){
        const BaseReturnDto<Account*> &dto =bankService->findById(moneyInputDto.getAccountID());
        if(dto.error.isError()){
            throw AccountSystemException(dto.error.getReason());
        }
        return bankService->findById(moneyInputDto.getAccountID());
    }

    return BaseReturnDto<Account*>{nullptr, Error{true,constants::err_kr::EX_MSG_INITIALIZE_NOT_YET}};
}

void DepositFormViewModel::reset() {
    moneyInputDto = MoneyInputDto();
}
