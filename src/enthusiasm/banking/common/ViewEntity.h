//
// Created by 홍준근 on 2023/02/02.
//

#ifndef FIRSTCPP_VIEWENTITY_H
#define FIRSTCPP_VIEWENTITY_H

#include "enthusiasm/banking/command/domain/dto/BaseReturnDto.h"
#include "enthusiasm/common/Error.h"
#include "enthusiasm/banking/common/ViewEntitySet.h"
#include "enthusiasm/banking/common/HGrowableList.h"
#include "Iterator.h"

template <class K, class V>
class ViewEntity{
private:
    HGrowableList<ViewEntitySet<K, V>> viewEntityList;

public:
    ViewEntity(): viewEntityList(HGrowableList < ViewEntitySet < K, V >> ()){}
    ViewEntity(const ViewEntity<K,V>& viewEntity):viewEntityList(viewEntity.viewEntityList){}

    ViewEntity<K, V>& operator=(const ViewEntity<K, V> &ref){
        viewEntityList = ref.viewEntityList;
        return *this;
    };

    BaseReturnDto<const V> getViewEntity(const K& key) const{
        ViewEntitySet<K, V> element = ViewEntitySet<K, V>(key,V());
        if(viewEntityList.isExist(element)){
            return BaseReturnDto<const V>{viewEntityList.get(viewEntityList.where(element)).getValue(), Error{false, ""}};
        }
        return BaseReturnDto<const V>{element.getValue(), Error{true, constants::err_kr::ERR_MSG_ELEMENT_NOT_FOUND}};
    };

    Error addViewEntity(const K& key, const V& value) {
        ViewEntitySet<K, V> element = ViewEntitySet<K, V>(key,V());
        if(viewEntityList.isExist(element)){
            std::cout<<"여기 오면 안됨"<<std::endl;
            return Error{true, constants::err_kr::ERR_MSG_ELEMENT_DUPLICATED};
        }
        viewEntityList.add( ViewEntitySet<K, V>(key,value));
        return Error{};
    };

    ViewEntity<K, V>& adder(const K& key, const V& value){
        if(addViewEntity(key, value).isError()){
            throw DuplicatedViewEntityException(constants::ex_kr::EX_MSG_VIEW_ENTITY_DUPLICATE);
        }
        return *this;
    }

    Error replaceViewEntity(const K& key, const V& value){
        ViewEntitySet<K, V> element = ViewEntitySet<K, V>(key,V());
        if(viewEntityList.isExist(element)){
            viewEntityList.replace(viewEntityList.where(element),ViewEntitySet<K, V>(key, value));
            return Error{};
        }
        return Error{true, constants::err_kr::ERR_MSG_ELEMENT_NOT_FOUND};
    };

    Error removeViewEntity(const K& key){
        ViewEntitySet<K, V> element = ViewEntitySet<K, V>(key,V());
        if(viewEntityList.isExist(element)){
            viewEntityList.remove(viewEntityList.where(element));
            return Error{};
        }
        return Error{true, constants::err_kr::ERR_MSG_ELEMENT_NOT_FOUND};
    };

    int getSize()const{
        return viewEntityList.getSize();
    }

    Iterator<ViewEntitySet<K, V>, HGrowableList<ViewEntitySet<K, V>>>* createIterator() const{
        return viewEntityList.createIterator();
    }

};
#endif //FIRSTCPP_VIEWENTITY_H
