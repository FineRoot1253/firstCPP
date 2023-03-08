//
// Created by 홍준근 on 2023/01/12.
//

#ifndef FIRSTCPP_ERROR_H
#define FIRSTCPP_ERROR_H

#include <cstring>
#include "enthusiasm/banking/common/constants.h"

class Error{
private:
    bool hasError;
    char *content;
public:
    Error():hasError(false){
        this->content = new char[std::strlen(constants::err_kr::ERR_MSG_NO_ERROR)+1];
        std::strcpy(this->content, constants::err_kr::ERR_MSG_NO_ERROR);
    };
    Error(const bool &isError, const char* content):hasError(isError){
        if(content!= nullptr){
            this->content = new char[std::strlen(content)+1];
            std::strcpy(this->content, content);
        }
    };
    Error(const Error& error):hasError(error.hasError){
        if(error.content!= nullptr){
            this->content = new char[std::strlen(error.content)+1];
            std::strcpy(this->content, error.content);
        }
    };

    ~Error(){
        delete []content;
    };

     Error& operator=(const Error& ref) {
        delete []content;
         this->content = new char[std::strlen(ref.content)+1];
         std::strcpy(this->content, ref.content);
         this->hasError = ref.hasError;
         return *this;
    };

    char* getReason()const{
        return content;
    };

    bool isError() const{
        return hasError;
    };
};
#endif //FIRSTCPP_ERROR_H
