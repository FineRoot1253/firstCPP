//
// Created by 홍준근 on 2023/02/16.
//

#ifndef FIRSTCPP_BANKVIEWMANAGER_H
#define FIRSTCPP_BANKVIEWMANAGER_H

#include "enthusiasm/banking/ui/includes/ViewModel.h"
#include "enthusiasm/banking/ui/includes/View.h"
#include "enthusiasm/banking/common/ViewFactory.h"
#include "enthusiasm/banking/common/ViewManager.h"

using namespace utils::Parser;

class BankViewManager : public ViewManager {
private:
    ViewFactory *viewFactory;
    HGrowableList<ViewID> *loadedViewIDs;
    HGrowableList<ViewID> *callViewIDs;
    ViewEntity<ViewID, Listener *> *viewMap;
    EventProvider eventProvider;

private:
    void loadView(eViewType viewType) {
        const ViewID& viewId = ViewID(viewTypeToConstLong(viewType));
        if (!loadedViewIDs->isExist(viewId)) {
            eventProvider.attach(viewId,viewFactory->createView(viewType, eventProvider));
        }
        callViewIDs->add(viewId);
    };

public:
    explicit BankViewManager(ViewFactory *viewFactory)
            : viewFactory(viewFactory)
            , loadedViewIDs(new HGrowableList<ViewID>())
            , callViewIDs(new HGrowableList<ViewID>())
            , viewMap(new ViewEntity<ViewID, Listener *>())
            , eventProvider(EventProvider(viewMap, this)) {
    }

    ~BankViewManager() override{
        delete viewFactory;
        delete loadedViewIDs;
        delete callViewIDs;
        delete viewMap;
    }

    // for view hook
    void addLoadedViewID(const ViewID &viewId) override{
        if (!loadedViewIDs->isExist(viewId)) {
            loadedViewIDs->add(viewId);
        }
    }

    HGrowableList<ViewID> getCallViewIDs() const override {
        return *callViewIDs;
    }

    void getTo(const ViewID &viewId) override {
        callViewIDs->clear();
        loadView(constLongToViewType(viewId.getValue()));
        auto dto = viewMap->getViewEntity(viewId);
        if (dto.error.isError()) {
            throw SystemCallException(dto.error.getReason());
        }
        addLoadedViewID(viewId);
        dto.data->update();
    }

    bool isViewLoaded(const ViewID &viewId) override {
        return loadedViewIDs->isExist(viewId);
    }

    void initRender(const ViewID &viewId) override{
        callViewIDs->clear();
        loadView(constLongToViewType(viewId.getValue()));
    }

};

#endif //FIRSTCPP_BANKVIEWMANAGER_H
