//
// Created by 홍준근 on 2023/01/11.
//

#include "enthusiasm/banking/ui/view/WithdrawForm.h"

using namespace utils::Parser;

WithdrawForm::WithdrawForm(const WithdrawFormViewModel& withdrawFormViewModel,
                           const ViewModelEventListener &viewModelEventListener)
                           : withdrawFormViewModel(withdrawFormViewModel)
                           , View(viewModelEventListener){}

void WithdrawForm::render() {
    const Account result = withdrawFormViewModel.getMoneyInputResult();
    if(!result.isEmpty()){
        buildResultForm();
    }else{
        buildRequestForm();
    }
}

void WithdrawForm::buildRequestForm() {
    std::cout<<"[출   금]"<<std::endl;
    withdrawFormViewModel.setMoneyInputDto();
}

void WithdrawForm::buildResultForm() {
    std::cout<<withdrawFormViewModel.getMoneyInputResult();
}

void WithdrawForm::dispose() {
    View::dispose();
    withdrawFormViewModel.reset();
    withdrawFormViewModel.getTo(ViewID(viewTypeToConstLong(eViewType::MainMenu)));
}
