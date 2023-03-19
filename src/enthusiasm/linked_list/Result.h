//
// Created by 홍준근 on 2023/03/18.
//

#ifndef FIRSTCPP_RESULT_H
#define FIRSTCPP_RESULT_H
namespace Collection{
    template <class T>
    class Result{
    private:
        T data;
        bool errorState;
    public:
        Result(const T& data, bool errorState):data(data), errorState(errorState){
        }

        bool isError();
        T getData() const;
    };

    template <class T>
    bool Result<T>::isError(){
        return errorState;
    }
    template <class T>
    T Result<T>::getData() const{
        return data;
    }
}
#endif //FIRSTCPP_RESULT_H
