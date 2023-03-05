#include "enthusiasm/casting/StaticCasting.h"

int main(){
    Car * car1 = new Truck(80, 200);
    Truck* truck1 = static_cast<Truck*>(car1);
    truck1->showTruckState();
    std::cout<<std::endl;

    Car * car2 = new Car(120);
    Truck* truck2 = static_cast<Truck*>(car2);
    truck2->showTruckState();
    std::cout<<std::endl;
    return 0;
}