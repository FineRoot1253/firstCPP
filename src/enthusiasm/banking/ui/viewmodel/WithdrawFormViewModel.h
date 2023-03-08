//
// Created by 홍준근 on 2023/01/18.
//

#ifndef FIRSTCPP_WITHDRAWFORMVIEWMODEL_H
#define FIRSTCPP_WITHDRAWFORMVIEWMODEL_H

#include "enthusiasm/banking/ui/includes/ViewModel.h"
#include "enthusiasm/banking/command/domain/dto/MoneyInputDto.h"
#include "enthusiasm/banking/command/service/BankService.h"
#include "enthusiasm/banking/common/HGrowableList.h"
#include "enthusiasm/banking/infra/includes/Listener.h"
#include "enthusiasm/banking/command/domain/entity/NormalAccount.h"

class WithdrawFormViewModel: public ViewModel {
private:
    BankService* bankService;
    MoneyInputDto moneyInputDto;
public:
    WithdrawFormViewModel(const ViewID& viewId, const EventProvider &eventProvider, BankService* bankService);
    WithdrawFormViewModel(const WithdrawFormViewModel &withdrawFormViewModel);

    void setMoneyInputDto();
    void reset();

    BaseReturnDto<Account*> getMoneyInputResult()const;
};


#endif //FIRSTCPP_WITHDRAWFORMVIEWMODEL_H
