//
// Created by 홍준근 on 2023/01/11.
//

#ifndef FIRSTCPP_ACCOUNT_H
#define FIRSTCPP_ACCOUNT_H
const int NAME_LEN = 20;

typedef struct{
    long accId;
    int balance;
    char cusName[NAME_LEN];
} Account;
#endif //FIRSTCPP_ACCOUNT_H
