#include "EventProvider.h"

void EventProvider::getTo(const ViewID& viewId){
    viewManager->getTo(viewId);
}

void EventProvider::notify() {
    auto* iterator = listenerEntity->createIterator();
    HGrowableList<ViewID> calledViewIDs = viewManager->getCallViewIDs();
    for(iterator->First();!iterator->IsDone();iterator->Next()){
        if(calledViewIDs.isExist(iterator->Current().getKey())){
            viewManager->addLoadedViewID(iterator->Current().getKey());
            iterator->Current().getValue()->update();
        }
    }
    delete iterator;
}

void EventProvider::attach(const ViewID &key, Listener *listener) {
    listenerEntity->addViewEntity(key, listener);
}

void EventProvider::detach(const ViewID &key) {
    listenerEntity->removeViewEntity(key);
}