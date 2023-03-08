//
// Created by 홍준근 on 2023/01/18.
//

#ifndef FIRSTCPP_MAKEACCOUNTFORMVIEWMODEL_H
#define FIRSTCPP_MAKEACCOUNTFORMVIEWMODEL_H

#include "enthusiasm/banking/ui/includes/ViewModel.h"
#include "enthusiasm/banking/command/domain/dto/AccountInputDto.h"
#include "enthusiasm/banking/command/service/BankService.h"
#include "enthusiasm/banking/common/HGrowableList.h"
#include "enthusiasm/banking/infra/includes/Listener.h"
#include "enthusiasm/banking/common/utils.h"

class MakeAccountFormViewModel: public ViewModel {
private:
    BankService* bankService;
    AccountInputDto accountInputDto;
public:
    MakeAccountFormViewModel(const ViewID& viewId, const EventProvider &eventProvider, BankService* bankService);
    MakeAccountFormViewModel(const MakeAccountFormViewModel &makeAccountFormViewModel);

    void setAccount();
    void reset();

    bool isLoaded() const;
};


#endif //FIRSTCPP_MAKEACCOUNTFORMVIEWMODEL_H
