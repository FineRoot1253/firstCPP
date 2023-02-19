//
// Created by 홍준근 on 2023/02/02.
//

#ifndef FIRSTCPP_VIEWENTITYSET_H
#define FIRSTCPP_VIEWENTITYSET_H
#include "enthusiasm/banking/common/equatable.h"

template<class K, class T>
class ViewEntitySet : public Equatable<ViewEntitySet<K, T>> {
private:
    K key;
    T value;
public:
    ViewEntitySet(const K &key, const T &value) : key(key), value(value) {};

    ViewEntitySet(const ViewEntitySet &simpleViewEntity) : key(simpleViewEntity.key), value(simpleViewEntity.value) {};

    ViewEntitySet& operator=(const ViewEntitySet &simpleViewEntity){
        key = simpleViewEntity.key;
        value = simpleViewEntity.value;
        return *this;
    };

    bool isEqual(const ViewEntitySet<K, T> &other) const override {
        return key.isEqual(other.key);
    }

    bool isNotEqual(const ViewEntitySet<K, T> &other) const override {
        return !(key.isEqual(other.key));
    }

    T getValue() const;

    K getKey() const;

};


template<class K, class T>
T ViewEntitySet<K, T>::getValue() const {
    return value;
}

template<class K, class T>
K ViewEntitySet<K, T>::getKey() const{
    return key;
}
#endif //FIRSTCPP_VIEWENTITYSET_H
