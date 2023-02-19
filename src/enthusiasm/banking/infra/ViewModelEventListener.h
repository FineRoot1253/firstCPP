//
// Created by 홍준근 on 2023/01/18.
//

#ifndef FIRSTCPP_VIEWMODEL_EVENTLISTENER_H
#define FIRSTCPP_VIEWMODEL_EVENTLISTENER_H

#include "enthusiasm/banking/infra/includes/Listener.h"
#include "enthusiasm/banking/infra/EventProvider.h"
#include "enthusiasm/banking/ui/includes/ViewID.h"

class ViewModelEventListener : public Listener {
private:
    EventProvider eventProvider;
    ViewID viewId;
public:
    ViewModelEventListener(const EventProvider &eventProvider, const ViewID &viewId);

    ViewModelEventListener(const ViewModelEventListener &viewModelEventListener);

    virtual ~ViewModelEventListener() {
//        delete provider;
    };

    virtual void update(){};

    const ViewID &getViewID() const;
};


#endif //FIRSTCPP_VIEWMODEL_EVENTLISTENER_H
