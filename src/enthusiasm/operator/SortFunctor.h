#ifndef FIRSTCPP_SORTFUNCTOR _H
#define FIRSTCPP_SORTFUNCTOR _H
#include <iostream>

class SortRule{
public:
    virtual bool operator()(int num1, int num2) const = 0;
};

class AscendingSort : public SortRule{
    bool operator()(int num1, int num2) const override {
        if(num1 > num2){
            return true;
        }
        return false;
    }
};

class DescendingSort : public SortRule{
    bool operator()(int num1, int num2) const override {
        if(num1 < num2){
            return true;
        }
        return false;
    }
};

class DataStorage{
private:
    int* arr;
    int index;
    const int MAX_LEN;
public:
    DataStorage(int length):index(0),MAX_LEN(length){
        arr = new int[MAX_LEN];
    }

    void addData(int num){
        if(MAX_LEN <= index){
            std::cout<<"더 이상 저장이 불가능합니다."<<std::endl;
            return;
        }
        arr[index++] = num;
    }

    void showAllData() const {
        for (int i = 0; i < index; ++i) {
            std::cout<<arr[i]<< ' ';
        }
        std::cout<<std::endl;
    }

    void sortData(const SortRule& functor){
        for (int i = 0; i < (index - 1); ++i) {
            for (int j = 0; j < (index - 1); ++j) {
                if(functor(arr[j], arr[j+1])){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1]=temp;
                    // 이런 로직은 std::swap을 쓰면 한번에 정리된다.
                }
            }
        }
    }
};
#endif // FIRSTCPP_SORTFUNCTOR _H

