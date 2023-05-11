#ifndef FIRSTCPP_TABLE2 _H
#define FIRSTCPP_TABLE2 _H
#include "Slot2.h"
#include "enthusiasm/linked_list/DLinkedList.h"
#define MAX_TABLE_SIZE 100

using namespace Collection;

namespace Enthusiasm{
    namespace HashTable{
        template <class T>
        class Table2{
        private:
            DLinkedList<Slot<T>> table[MAX_TABLE_SIZE];
            int (*hashFunction)(const int& key);

        public:
            Table2();
            explicit Table2(int (*hashFunction)(const int& key));
            Table2(const Table2& ref);
            Table2(Table2&& ref) noexcept;
            Table2& operator=(const Table2& ref);
            Table2& operator=(Table2&& ref) noexcept;
            ~Table2() = default;

        public:
            void insert(const long& key, T* value);
            T* remove(const long& key);
            T* search(const long& key);
        };

        template <class T>
        Table2<T>::Table2()
        : hashFunction(nullptr){
        }

        template <class T>
        Table2<T>::Table2(int (*hashFunction)(const int &))
        : hashFunction(hashFunction) {
        }

        template <class T>
        Table2<T>::Table2(const Enthusiasm::HashTable::Table2<T> &ref)
        : hashFunction(ref.hashFunction){
            for (int i = 0; i < MAX_TABLE_SIZE; ++i) {
                table[i] = ref.table[i];
            }
        }

        template <class T>
        Table2<T>::Table2(Enthusiasm::HashTable::Table2<T> &&ref) noexcept
        : hashFunction(ref.hashFunction){
            for (int i = 0; i < MAX_TABLE_SIZE; ++i) {
                table[i] = ref.table[i];
            }
        }


        template <class T>
        Table2<T> &Table2<T>::operator=(const Enthusiasm::HashTable::Table2<T> &ref) {
            hashFunction = ref.hashFunction;
            for (int i = 0; i < MAX_TABLE_SIZE; ++i) {
                table[i] = ref.table[i];
            }
            return *this;
        }

        template <class T>
        Table2<T> &Table2<T>::operator=(Enthusiasm::HashTable::Table2<T> &&ref) noexcept {
            hashFunction = ref.hashFunction;
            for (int i = 0; i < MAX_TABLE_SIZE; ++i) {
                table[i] = ref.table[i];
            }
            return *this;
        }

        template <class T>
        void Table2<T>::insert(const long &key, T* value) {
            if(search(key) != nullptr){
                return ;
            }else{
                table[hashFunction(key)].insert(Slot<T>(key, value));
            }
        }

        template <class T>
        T *Table2<T>::remove(const long &key) {
            if(!table[hashFunction(key)].first().isError()) {
                for (table[hashFunction(key)].first();!table[hashFunction(key)].isDone();table[hashFunction(key)].next()) {
                    if (table[hashFunction(key)].current().getData().getKey() == key) {
                        return table[hashFunction(key)].remove().getData().getValue();
                    }
                }
            }


            return nullptr;
        }

        template <class T>
        T *Table2<T>::search(const long &key) {
            if(!table[hashFunction(key)].first().isError()) {
                for (table[hashFunction(key)].first(); !table[hashFunction(key)].isDone(); table[hashFunction(key)].next()) {
                    const Result<Slot<T>> &result = table[hashFunction(key)].current();
                    if (result.getData().getKey() == key) {
                        return result.getData().getValue();
                    }
                }
            }
            return nullptr;
        }
    }
}
#endif // FIRSTCPP_TABLE2 _H

