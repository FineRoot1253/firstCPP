//
// Created by 홍준근 on 2023/02/05.
//

#ifndef FIRSTCPP_BANKVIEWFACTORY_H
#define FIRSTCPP_BANKVIEWFACTORY_H

#include "enthusiasm/banking/common/ViewFactory.h"
#include "enthusiasm/banking/ui/includes/vm_ext.h"
#include "enthusiasm/banking/ui/includes/view_ext.h"
#include "enthusiasm/banking/common/utils.h"

using namespace utils::Parser;

class BankViewFactory : public ViewFactory {
private:
    BankService *bankService;
public:
    explicit BankViewFactory(BankService *bankService) : bankService(bankService) {}
    ~BankViewFactory() {
    }

    View *createView(const eViewType &viewModelType, const EventProvider& eventProvider) override {

        const ViewID &viewId = ViewID(viewTypeToConstLong(viewModelType));

        switch (viewModelType) {
            case eViewType::MainMenu : {
                return new MainMenu(MainMenuViewModel(viewId, eventProvider, bankService),
                                    ViewModelEventListener(eventProvider, viewId));
            }
            case eViewType::MakeAccountForm : {
                return new MakeAccountForm(MakeAccountFormViewModel(viewId, eventProvider,bankService),
                                           ViewModelEventListener(eventProvider, viewId));
            }
            case eViewType::DepositForm : {
                return new DepositForm(DepositFormViewModel(viewId, eventProvider, bankService),
                                       ViewModelEventListener(eventProvider, viewId));
            }
            case eViewType::WithdrawForm : {
                return new WithdrawForm(WithdrawFormViewModel(viewId, eventProvider, bankService),
                                        ViewModelEventListener(eventProvider, viewId));
            }
            case eViewType::UserListForm : {
                return new UserListForm(UserListFormViewModel(viewId, eventProvider, bankService),
                                        ViewModelEventListener(eventProvider, viewId));
            }
            default:
                throw SystemCallException(constants::ex_kr::EX_MSG_SYS_CAN_NOT_SWITCH_DEFAULT);
        }
    }
};

#endif //FIRSTCPP_BANKVIEWFACTORY_H
