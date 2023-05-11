#ifndef FIRSTCPP_TABLE _H
#define FIRSTCPP_TABLE _H
#include "Slot.h"

#define MAX_TABLE_SIZE 100

namespace Enthusiasm{
    namespace HashTable{
        template <class T>
        class Table{
        private:
            Slot<T> table[MAX_TABLE_SIZE];
            int (*hashFunction)(const int& key);
            
        public:
            Table();
            explicit Table(int (*hashFunction)(const int& key));
            Table(const Table& ref);
            Table(Table&& ref) noexcept;
            Table& operator=(const Table& ref);
            Table& operator=(Table&& ref) noexcept;
            ~Table() = default;
            
        public:
            void insert(const long& key, T* value);
            T* remove(const long& key);
            T* search(const long& key) const;
        };

        template <class T>
        Table<T>::Table()
        : hashFunction(nullptr){
        }

        template <class T>
        Table<T>::Table(int (*hashFunction)(const int &))
        : hashFunction(hashFunction) {
        }

        template <class T>
        Table<T>::Table(const Enthusiasm::HashTable::Table<T> &ref)
        : hashFunction(ref.hashFunction){
            for (int i = 0; i < MAX_TABLE_SIZE; ++i) {
                table[i] = ref.table[i];
            }
        }

        template <class T>
        Table<T>::Table(Enthusiasm::HashTable::Table<T> &&ref) noexcept
        : hashFunction(ref.hashFunction){
            for (int i = 0; i < MAX_TABLE_SIZE; ++i) {
                table[i] = ref.table[i];
                ref.table[i] = Slot<T>();
            }
        }


        template <class T>
        Table<T> &Table<T>::operator=(const Enthusiasm::HashTable::Table<T> &ref) {
            hashFunction = ref.hashFunction;
            for (int i = 0; i < MAX_TABLE_SIZE; ++i) {
                table[i] = ref.table[i];
            }
            return *this;
        }

        template <class T>
        Table<T> &Table<T>::operator=(Enthusiasm::HashTable::Table<T> &&ref) noexcept {
            hashFunction = ref.hashFunction;
            for (int i = 0; i < MAX_TABLE_SIZE; ++i) {
                table[i] = ref.table[i];
                ref.table[i] = Slot<T>();
            }
            return *this;
        }

        template <class T>
        void Table<T>::insert(const long &key, T* value) {
            table[hashFunction(key)] = Slot<T>(key, value, SlotStatus::INUSE);
        }

        template <class T>
        T *Table<T>::remove(const long &key) {
            Slot<T> &result = table[hashFunction(key)];
            table[hashFunction(key)] = Slot<T>(hashFunction(key), new T(), SlotStatus::DELETED);
            return result.getValue();
        }

        template <class T>
        T *Table<T>::search(const long &key) const {
            if(table[hashFunction(key)].getStatus() != SlotStatus::INUSE){
                return nullptr;
            }
            return table[hashFunction(key)].getValue();
        }
    }
}

#endif // FIRSTCPP_TABLE _H

