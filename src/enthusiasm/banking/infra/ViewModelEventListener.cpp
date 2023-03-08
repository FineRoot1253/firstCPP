//
// Created by 홍준근 on 2023/01/18.
//

#include "ViewModelEventListener.h"

ViewModelEventListener::ViewModelEventListener(const EventProvider &eventProvider, const ViewID &viewId)
        : eventProvider(eventProvider)
          , viewId(viewId) {
}

const ViewID &ViewModelEventListener::getViewID() const {
    return viewId;
}

ViewModelEventListener::ViewModelEventListener(const ViewModelEventListener &viewModelEventListener)
        : eventProvider(viewModelEventListener.eventProvider)
          , viewId(viewModelEventListener.viewId) {
}
