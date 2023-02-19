//
// Created by 홍준근 on 2023/01/11.
//

#ifndef FIRSTCPP_MAKEACCOUNTFORM_H
#define FIRSTCPP_MAKEACCOUNTFORM_H

#include "enthusiasm/banking/ui/includes/View.h"
#include "enthusiasm/banking/ui/viewmodel/MakeAccountFormViewModel.h"

class MakeAccountForm : public View{
private:
    MakeAccountFormViewModel makeAccountFormViewModel;

    void buildInputView();
    void buildResultView();
protected:
    void render() override;
    void dispose() override;
public:
    ~MakeAccountForm() override= default;
    MakeAccountForm(const MakeAccountFormViewModel& makeAccountFormViewModel, const ViewModelEventListener &viewModelEventListener);
};


#endif //FIRSTCPP_MAKEACCOUNTFORM_H
