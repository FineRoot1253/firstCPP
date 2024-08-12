//
// Created by 홍준근 on 2024. 8. 8..
//

#ifndef FIRSTCPP_EXCEPTIONHANDLER_H
#define FIRSTCPP_EXCEPTIONHANDLER_H

#include "Error.h"
#include <iostream>

namespace Exception  {
    namespace Handle{
        void handleError(const Error error){
            if(error.isError()){
                std::cout<<error.getReason()<<std::endl;
                exit(1);
            }
        }
    }
}

#endif //FIRSTCPP_EXCEPTIONHANDLER_H
