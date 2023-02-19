//
// Created by 홍준근 on 2023/01/11.
//

#ifndef FIRSTCPP_DEPOSITFORM_H
#define FIRSTCPP_DEPOSITFORM_H

#include "enthusiasm/banking/ui/includes/View.h"
#include "enthusiasm/banking/ui/viewmodel/DepositFormViewModel.h"
#include "enthusiasm/banking/common/utils.h"

class DepositForm : public View{
private:
    DepositFormViewModel depositFormViewModel;
    void buildRequestForm();
    void buildResultForm();
protected:
    void render() override;
    void dispose() override;
public:
    ~DepositForm() override= default;
    DepositForm(const DepositFormViewModel& depositFormViewModel, const ViewModelEventListener& viewModelEventListener);

};


#endif //FIRSTCPP_DEPOSITFORM_H
