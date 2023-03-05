#include "enthusiasm/casting/PowerfullCasting.h"

int main(){
    Car * car1 = new Truck(80, 200);
    Truck* truck1 = (Truck *) car1;
    truck1->showTruckState();
    std::cout<<std::endl;

    Car * car2 = new Car(120);
    Truck* truck2 = (Truck *) car2;
    truck2->showTruckState();
    std::cout<<std::endl;
    return 0;
}


