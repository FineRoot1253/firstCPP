//
// Created by 홍준근 on 2023/01/18.
//

#ifndef FIRSTCPP_VIEWMODEL_H
#define FIRSTCPP_VIEWMODEL_H

#include "enthusiasm/banking/infra/EventProvider.h"
#include "enthusiasm/banking/ui/includes/ViewID.h"
#include "enthusiasm/banking/common/equatable.h"

class ViewModel : public EventProvider, public Equatable<ViewID> {
private:
    ViewID viewId;
public:
    ViewModel(const ViewID &viewId, const EventProvider &eventProvider)
            : viewId(viewId), EventProvider(eventProvider){
    }

    ViewID getViewId() const {
        return viewId;
    };

    bool isEqual(const ViewID& other) const override{
        return this->viewId.isEqual(other);
    }

    bool isNotEqual(const ViewID& other) const override{
        return this->viewId.isNotEqual(other);
    }
};

#endif //FIRSTCPP_VIEWMODEL_H
