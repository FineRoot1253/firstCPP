#include "enthusiasm/casting/ConstCasting.h"

int main(){
    const char* name = "Lee Sung Ju";
    showString(const_cast<char*>(name));

    const int& num1 = 100;
    const int& num2 = 200;
    showAddResult(const_cast<int&>(num1), const_cast<int&>(num2));
    return 0;
}