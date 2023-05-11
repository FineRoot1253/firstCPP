#ifndef FIRSTCPP_SLOT _H
#define FIRSTCPP_SLOT _H

#include "Person.h"

namespace Enthusiasm{
    namespace HashTable{
        enum class SlotStatus{
            EMPTY,
            DELETED,
            INUSE
        };

        template <class T>
        class Slot{
        private:
            long key;
            T *value;
            SlotStatus status;
        public:
            Slot();
            Slot(const long& key, T* value, const SlotStatus& status);
            Slot(const Slot& ref);
            Slot(Slot&& ref) noexcept;
            Slot& operator=(const Slot& ref);
            Slot& operator=(Slot&& ref) noexcept;
            ~Slot();

        public:
            T* getValue() const;
            long getKey() const;
            SlotStatus getStatus() const;
        };

        template <class T>
        Slot<T>::Slot()
        : key(0L)
        , value(nullptr)
        , status(SlotStatus::EMPTY){}

        template <class T>
        Slot<T>::Slot(const long &key, T *value, const SlotStatus &status)
        : key(key)
        , value(value)
        , status(status){
        }

        template <class T>
        Slot<T>::Slot(const Enthusiasm::HashTable::Slot<T> &ref)
        : key(ref.key)
        , value(ref.value)
        , status(ref.status){
        }

        template <class T>
        Slot<T>::Slot(Enthusiasm::HashTable::Slot<T> &&ref) noexcept
        : key(ref.key)
        , value(ref.value)
        , status(ref.status){
        }

        template <class T>
        Slot<T> &Slot<T>::operator=(const Enthusiasm::HashTable::Slot<T> &ref) {
            key = ref.key;
            value = ref.value;
            status = ref.status;
            return *this;
        }

        template <class T>
        Slot<T> &Slot<T>::operator=(Enthusiasm::HashTable::Slot<T> &&ref) noexcept {
            key = ref.key;
            value = ref.value;
            status = ref.status;
            return *this;
        }

        template <class T>
        Slot<T>::~Slot() {
        }

        template<class T>
        T *Slot<T>::getValue() const {
            return value;
        }

        template<class T>
        long Slot<T>::getKey() const {
            return key;
        }

        template<class T>
        SlotStatus Slot<T>::getStatus() const {
            return status;
        }
    }
}
#endif // FIRSTCPP_SLOT _H

