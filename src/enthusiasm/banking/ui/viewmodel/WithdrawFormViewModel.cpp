//
// Created by 홍준근 on 2023/01/18.
//

#include "WithdrawFormViewModel.h"

WithdrawFormViewModel::WithdrawFormViewModel(const ViewID &viewId, const EventProvider &eventProvider, BankService *bankService)
        : ViewModel(viewId, eventProvider)
          , moneyInputDto(eBankingMode::WithDraw)
          , bankService(bankService) {
}

WithdrawFormViewModel::WithdrawFormViewModel(const WithdrawFormViewModel &withdrawFormViewModel)
        : ViewModel(withdrawFormViewModel.getViewId(), withdrawFormViewModel)
          , moneyInputDto(eBankingMode::WithDraw)
          , bankService(withdrawFormViewModel.bankService) {
}

void WithdrawFormViewModel::setMoneyInputDto() {
    std::cin >> moneyInputDto;
    const Error &result = bankService->withdrawMoney(moneyInputDto);
    if (result.isError()) {
        throw AccountSystemException(result.getReason());
    }
    EventProvider::notify();
}

BaseReturnDto<Account*> WithdrawFormViewModel::getMoneyInputResult() const {
    if(moneyInputDto.getAccountID() != -1){
        const BaseReturnDto<Account*> &dto = bankService->findById(moneyInputDto.getAccountID());
        if(dto.error.isError()){
            throw AccountSystemException(dto.error.getReason());
        }
        return dto;
    }
    return BaseReturnDto<Account*>{nullptr, Error{true,constants::err_kr::EX_MSG_INITIALIZE_NOT_YET}};
}

void WithdrawFormViewModel::reset() {
    moneyInputDto = MoneyInputDto(eBankingMode::WithDraw);
}
