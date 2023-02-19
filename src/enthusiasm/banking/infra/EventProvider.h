//
// Created by 홍준근 on 2023/01/18.
//

#ifndef FIRSTCPP_EVENTPROVIDER_H
#define FIRSTCPP_EVENTPROVIDER_H

#include "enthusiasm/banking/infra/includes/Provider.h"
#include "enthusiasm/banking/infra/includes/Listener.h"
#include "enthusiasm/banking/ui/includes/ViewID.h"
#include "enthusiasm/banking/common/ViewEntity.h"
#include "enthusiasm/banking/common/ViewManager.h"

class EventProvider : public Provider<ViewID> {
private:
    ViewEntity<ViewID, Listener *> *listenerEntity;
    ViewManager *viewManager;

public:
    explicit EventProvider(ViewManager *viewManager)
            : listenerEntity(new ViewEntity<ViewID, Listener*>())
              , viewManager(viewManager) {};

    EventProvider(ViewEntity<ViewID, Listener *> *listenerEntity, ViewManager *viewManager)
    : listenerEntity(listenerEntity)
    , viewManager(viewManager) {};

    void getTo(const ViewID& viewId);

    void notify() override;

    void attach(const ViewID &key, Listener *listener) override;

    void detach(const ViewID &key) override;

};



#endif //FIRSTCPP_EVENTPROVIDER_H
