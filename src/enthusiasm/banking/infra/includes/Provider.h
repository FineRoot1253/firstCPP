//
// Created by 홍준근 on 2023/01/18.
//

#ifndef FIRSTCPP_EVENTLISTENER_H
#define FIRSTCPP_EVENTLISTENER_H

#include "enthusiasm/banking/infra/includes/Listener.h"

template <class K>
class Provider {
public:
    virtual void notify() = 0;

    virtual void attach(const K& key,Listener *listener) = 0;

    virtual void detach(const K& key) = 0;
};


#endif //FIRSTCPP_EVENTLISTENER_H
