#include "enthusiasm/casting/DynamicCasting.h"

int main(){
    Car * car1 = new Truck(80, 200);
//    Truck* truck1 = dynamic_cast<Truck*>(car1);


    Car * car2 = new Car(120);
//    Truck* truck2 = dynamic_cast<Truck*>(car2);

    Truck* truck3 = new Truck(70, 150);
    Car * car3 = dynamic_cast<Car*>(truck3);
    truck3->showTruckState();
    std::cout<<std::endl;
    return 0;
}


