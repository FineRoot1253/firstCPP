//
// Created by 홍준근 on 2023/01/25.
//

#ifndef FIRSTCPP_UTILS_H
#define FIRSTCPP_UTILS_H

#include <math.h>
#include <ios>
#include "view_type.h"

namespace utils {
    constexpr int getIntDigitCounts(const int &input) {
        if(input == 0){
            return 1;
        }
        return floor(log10(input) + 1);
    }

    namespace Parser {
        class IntegerToCharArray {
        private:
            char *value;
        public:
            explicit IntegerToCharArray(const int &value) {
                const long long &length = getIntDigitCounts(value) + 1;
                this->value = new char[length];
                std::snprintf(this->value, length, "%d", value);
            };

            explicit IntegerToCharArray(const long &value) {
                const long long &length = getIntDigitCounts(value) + 1;
                this->value = new char[length];
                std::snprintf(this->value, length, "%ld", value);
            };

            explicit IntegerToCharArray(const long long &value) {
                const long long &length = getIntDigitCounts(value) + 1;
                this->value = new char[length];
                std::snprintf(this->value, length, "%lld", value);
            };

            IntegerToCharArray(const IntegerToCharArray &value) {
                this->value = new char[std::strlen(value.value) + 1];
                std::strcpy(this->value, value.value);
            };

            ~IntegerToCharArray() {
                delete[]value;
            }

            IntegerToCharArray &operator=(const IntegerToCharArray &ref) {
                delete[]this->value;
                this->value = new char[std::strlen(ref.value) + 1];
                std::strcpy(this->value, ref.value);
                return *this;
            }

            char *getValue() const {
                return value;
            }

            int toInteger()const{
                return std::atoi(this->value);
            }
        };

        class BooleanToCharArray {
        private:
            char *value;
        public:
            explicit BooleanToCharArray(const bool &value) {
                int len;
                if(value){
                    len = 5;
                    this->value = new char[len];
                    std::strcpy(this->value, "true");
                }else{
                    len = 6;
                    this->value = new char[len];
                    std::strcpy(this->value, "false");
                }
            };

            BooleanToCharArray(const BooleanToCharArray &value) {
                this->value = new char[std::strlen(value.value) + 1];
                std::strcpy(this->value, value.value);
            };

            ~BooleanToCharArray() {
                delete[]value;
            }

            BooleanToCharArray &operator=(const BooleanToCharArray &ref) {
                delete[]this->value;
                this->value = new char[std::strlen(ref.value) + 1];
                std::strcpy(this->value, ref.value);
                return *this;
            }

            char *getValue() const {
                return value;
            }

            bool toBoolean() const {
                return std::strcmp(this->value, "true");
            }
        };

        constexpr long viewTypeToConstLong(eViewType viewType){
            return static_cast<const long>(viewType);
        };

        constexpr eViewType constLongToViewType(const long& value){
            return static_cast<eViewType>(value);
        };
    }

}
#endif //FIRSTCPP_UTILS_H
