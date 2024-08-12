//
// Created by 홍준근 on 2024. 8. 7..
//

#ifndef FIRSTCPP_SELECTMANAGER_H
#define FIRSTCPP_SELECTMANAGER_H

#include <cstdio>
#include <sys/select.h>

class SelectManager {
private:
    fd_set reads, temps;
    int result, str_len;
    char buf[30];
    timeval timeout;


public:
    SelectManager();
    SelectManager(const SelectManager& ref);
    SelectManager(SelectManager&& ref) noexcept;
    SelectManager& operator=(const SelectManager& ref);
    SelectManager& operator=(SelectManager&& ref) noexcept;
    ~SelectManager();

public:
    [[noreturn]] void select();
};


#endif //FIRSTCPP_SELECTMANAGER_H
