//
// Created by 홍준근 on 2023/01/18.
//

#ifndef FIRSTCPP_DEPOSITFORMVIEWMODEL_H
#define FIRSTCPP_DEPOSITFORMVIEWMODEL_H

#include "enthusiasm/banking/ui/includes/ViewModel.h"
#include "enthusiasm/banking/command/domain/dto/MoneyInputDto.h"
#include "enthusiasm/banking/command/service/BankService.h"
#include "enthusiasm/banking/common/HGrowableList.h"
#include "enthusiasm/banking/infra/includes/Listener.h"
#include "enthusiasm/banking/infra/EventProvider.h"
#include "enthusiasm/banking/common/utils.h"

class DepositFormViewModel: public ViewModel{
private:
    BankService* bankService;
    MoneyInputDto moneyInputDto;
public:
    DepositFormViewModel(const ViewID& viewId, const EventProvider &eventProvider, BankService* bankService);
    DepositFormViewModel(const DepositFormViewModel& depositFormViewModel);

    void setMoneyInputDto();
    void reset();
    BaseReturnDto<Account*> getMoneyInputResult() const;


};


#endif //FIRSTCPP_DEPOSITFORMVIEWMODEL_H
