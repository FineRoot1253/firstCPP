//
// Created by 홍준근 on 2023/01/11.
//

#include "MakeAccountForm.h"

MakeAccountForm::MakeAccountForm(const MakeAccountFormViewModel& makeAccountFormViewModel,
                                 const ViewModelEventListener &viewModelEventListener)
                                 : makeAccountFormViewModel( makeAccountFormViewModel)
                                 , View(viewModelEventListener){
}

void MakeAccountForm::render() {
    if(makeAccountFormViewModel.isLoaded()){
        buildResultView();
    }else{
        buildInputView();
    }
}

void MakeAccountForm::buildInputView() {
    std::cout<<"[계좌개설]"<<std::endl;
    makeAccountFormViewModel.setAccount();
}

void MakeAccountForm::buildResultView() {
    std::cout<<"개설 완료"<<std::endl;
}

void MakeAccountForm::dispose() {
    View::dispose();
    makeAccountFormViewModel.reset();
    makeAccountFormViewModel.getTo(ViewID(viewTypeToConstLong(eViewType::MainMenu)));
}