#ifndef FIRSTCPP_SLOT2 _H
#define FIRSTCPP_SLOT2 _H
namespace Enthusiasm{
    namespace HashTable{
        template <class T>
        class Slot{
        private:
            long key;
            T *value;
        public:
            Slot();
            Slot(const long& key, T* value);
            Slot(const Slot& ref);
            Slot(Slot&& ref) noexcept;
            Slot& operator=(const Slot& ref);
            Slot& operator=(Slot&& ref) noexcept;
            ~Slot();

        public:
            T* getValue() const;
            long getKey() const;
        };

        template <class T>
        Slot<T>::Slot()
                : key(0L)
                  , value(nullptr){}

        template <class T>
        Slot<T>::Slot(const long &key, T *value)
                : key(key)
                  , value(value){
        }

        template <class T>
        Slot<T>::Slot(const Enthusiasm::HashTable::Slot<T> &ref)
                : key(ref.key)
                  , value(ref.value){
        }

        template <class T>
        Slot<T>::Slot(Enthusiasm::HashTable::Slot<T> &&ref) noexcept
                : key(ref.key)
                  , value(ref.value){
        }

        template <class T>
        Slot<T> &Slot<T>::operator=(const Enthusiasm::HashTable::Slot<T> &ref) {
            key = ref.key;
            value = ref.value;
            return *this;
        }

        template <class T>
        Slot<T> &Slot<T>::operator=(Enthusiasm::HashTable::Slot<T> &&ref) noexcept {
            key = ref.key;
            value = ref.value;
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
    }
}
#endif // FIRSTCPP_SLOT2 _H

