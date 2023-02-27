//
// Created by 홍준근 on 2023/01/11.
//

#include "UserListForm.h"

UserListForm::UserListForm(const UserListFormViewModel& userListViewModel, const ViewModelEventListener &viewModelEventListener)
: View(viewModelEventListener), userListFormViewModel( userListViewModel) {
}

void UserListForm::render() {
    HGrowableList<Account*> list = userListFormViewModel.getuserList();
    for (int i = 0; i < list.getSize(); ++i) {
        std::cout<<*list.get(i);
    }
}