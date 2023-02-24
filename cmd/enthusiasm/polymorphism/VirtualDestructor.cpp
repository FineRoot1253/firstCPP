#include "enthusiasm/polymorphism/VirtualDestructor.h"

int main(){
    First* first = new Second("simple", "complex");
    delete first;
    return 0;
}