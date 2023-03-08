//
// Created by 홍준근 on 2023/01/11.
//

#ifndef FIRSTCPP_WITHDRAWFORM_H
#define FIRSTCPP_WITHDRAWFORM_H

#include "enthusiasm/banking/ui/includes/View.h"
#include "enthusiasm/banking/ui/viewmodel/WithdrawFormViewModel.h"
#include "enthusiasm/banking/common/utils.h"

class WithdrawForm : public View{
private:
    WithdrawFormViewModel withdrawFormViewModel;
private:
    void buildRequestForm();
    void buildResultForm();
protected:
    void render() override;
    void dispose() override;
public:
    ~WithdrawForm() override= default;
    WithdrawForm(const WithdrawFormViewModel& withdrawFormViewModel, const ViewModelEventListener& viewModelEventListener);
};


#endif //FIRSTCPP_WITHDRAWFORM_H
