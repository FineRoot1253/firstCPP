//
// Created by 홍준근 on 2023/01/18.
//

#ifndef FIRSTCPP_VIEWFACTORY_H
#define FIRSTCPP_VIEWFACTORY_H

#include "enthusiasm/banking/ui/includes/View.h"
#include "enthusiasm/banking/common/view_type.h"
#include "enthusiasm/banking/infra/EventProvider.h"

class ViewFactory{
public:
    virtual ~ViewFactory() {};

    virtual View* createView(const eViewType& viewModelType, const EventProvider& eventProvider)=0;
};



#endif //FIRSTCPP_VIEWFACTORY_H
