#include "enthusiasm/polymorphism/VirtualInternal.h"

int main(){
    Fruit * fruit = new Fruit();
    fruit->func1();

    Apple *apple = new Apple();
    apple->func1();
    return 0;
}