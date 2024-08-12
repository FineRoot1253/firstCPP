//
// Created by 홍준근 on 2024. 8. 7..
//

#include <cstring>
#include <print>
#include "SelectManager.h"

SelectManager::SelectManager() {
    FD_ZERO(&reads);
    FD_SET(0, &reads);
}

SelectManager::SelectManager(const SelectManager &ref) {
    if (this != &ref) {
        result = ref.result;
        str_len = ref.str_len;
        std::memcpy(buf, ref.buf, sizeof(buf));
        std::memcpy(&reads, &ref.reads, sizeof(reads));
        std::memcpy(&temps, &ref.temps, sizeof(temps));
        std::memcpy(&timeout, &ref.timeout, sizeof(timeout));
    }
}

SelectManager::SelectManager(SelectManager &&ref) noexcept
        : result(ref.result), str_len(ref.str_len), reads(ref.reads), temps(ref.temps), timeout(ref.timeout) {
    std::memcpy(buf, ref.buf, sizeof(buf));
    std::memset(ref.buf, 0, 30);
}

SelectManager &SelectManager::operator=(const SelectManager &ref) {
    if (this != &ref) {
        result = ref.result;
        str_len = ref.str_len;
        std::memcpy(buf, ref.buf, sizeof(buf));
        std::memcpy(&reads, &ref.reads, sizeof(reads));
        std::memcpy(&temps, &ref.temps, sizeof(temps));
        std::memcpy(&timeout, &ref.timeout, sizeof(timeout));
    }
    return *this;
}

SelectManager &SelectManager::operator=(SelectManager &&ref) noexcept {
    if(this != &ref) {
        result = ref.result;
        str_len = ref.str_len;
        std::memcpy(buf, ref.buf, sizeof(buf));
        std::memcpy(&reads, &ref.reads, sizeof(reads));
        std::memcpy(&temps, &ref.temps, sizeof(temps));
        std::memcpy(&timeout, &ref.timeout, sizeof(timeout));
        std::memset(ref.buf, 0, 30);
    }

    return *this;
}

SelectManager::~SelectManager() {
}

void SelectManager::select() {
    while(true){
        temps = reads;
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;
        switch (::select(1, &temps, nullptr, nullptr, &timeout)) {
            case -1:
                puts("select() error!");
                break;
            case 0:
                puts("Time-out!");
            case 1:
                if(FD_ISSET(0, &temps)){
                    str_len = (int) read(0, buf, 30);
                    buf[str_len] = 0;
                    printf("message from console: %s", buf);
                }
        }
    }
}