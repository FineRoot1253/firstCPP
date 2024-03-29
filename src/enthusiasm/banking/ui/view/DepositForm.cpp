//
// Created by 홍준근 on 2023/01/11.
//

#include "DepositForm.h"

using namespace utils::Parser;

DepositForm::DepositForm(const DepositFormViewModel& depositFormViewModel,
                         const ViewModelEventListener &viewModelEventListener)
        : depositFormViewModel(depositFormViewModel), View(viewModelEventListener) {}

void DepositForm::render() {
    const BaseReturnDto<Account*> result = depositFormViewModel.getMoneyInputResult();
    if (!result.error.isError()) {
        buildResultForm();
    } else {
        buildRequestForm();
    }
}

void DepositForm::buildRequestForm() {
    std::cout << "[입   금]" << std::endl;
    depositFormViewModel.setMoneyInputDto();
}

void DepositForm::buildResultForm() {
    std::cout<<*depositFormViewModel.getMoneyInputResult().data;
}

void DepositForm::dispose() {
    depositFormViewModel.reset();
    depositFormViewModel.getTo(ViewID(viewTypeToConstLong(eViewType::MainMenu)));
}
