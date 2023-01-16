//
// Created by 홍준근 on 2023/01/11.
//

#ifndef FIRSTCPP_BANKCONTROLLER_H
#define FIRSTCPP_BANKCONTROLLER_H

#include <iostream>
#include <cstring>
#include "enthusiasm/banking/command/service/BankService.h"

class BankController {
private:
    BankService *bankService;
public:
    void showMenu();
    void makeAccount();
    void depositMoney();
    void withdrawMoney();
    void showAllAccInfo();
};

#endif //FIRSTCPP_BANKCONTROLLER_H
