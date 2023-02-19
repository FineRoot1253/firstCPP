//
// Created by 홍준근 on 2023/01/25.
//

#ifndef FIRSTCPP_VIEWMANAGER_H
#define FIRSTCPP_VIEWMANAGER_H

#include "enthusiasm/banking/common/HGrowableList.h"
#include "enthusiasm/banking/ui/includes/ViewID.h"

using namespace utils::Parser;

class ViewManager {
public:
    virtual ~ViewManager() {};
    virtual HGrowableList<ViewID> getCallViewIDs() const = 0;

    virtual void getTo(const ViewID &viewId) = 0;

    virtual bool isViewLoaded(const ViewID &viewId) = 0;

    virtual void addLoadedViewID(const ViewID& viewId) = 0;

    virtual void initRender(const ViewID& viewId) = 0;
};

#endif //FIRSTCPP_VIEWMANAGER_H
