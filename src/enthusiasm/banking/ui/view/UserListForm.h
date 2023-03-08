//
// Created by 홍준근 on 2023/01/11.
//

#ifndef FIRSTCPP_USERLISTFORM_H
#define FIRSTCPP_USERLISTFORM_H

#include "enthusiasm/banking/ui/includes/View.h"
#include "enthusiasm/banking/ui/viewmodel/UserListFormViewModel.h"

class UserListForm: public View{
private:
    UserListFormViewModel userListFormViewModel;
protected:
    void render() override;
public:
    ~UserListForm() override= default;
    UserListForm(const UserListFormViewModel& userListViewModel, const ViewModelEventListener &viewModelEventListener);
};


#endif //FIRSTCPP_USERLISTFORM_H
