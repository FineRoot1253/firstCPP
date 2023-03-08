//
// Created by 홍준근 on 2022/11/21.
//
#include <iostream>

class Animal{
private:
    int food;
    int weight;

public:
    void setAnimal(int food, int weight){
        this->food = food;
        this->weight = weight;
    }

    void increaseFood(int volume){
        this->food += volume;
        this->weight += (volume/3);
    }

    void viewStat(){
        std::cout<< "이 동물의 food: "<< this->food << std::endl;
        std::cout<< "이 동물의 weight: "<< this->weight << std::endl;
    }
};

int main(){
    Animal animal;
    animal.setAnimal(100, 50);
    animal.increaseFood(30);

    animal.viewStat();
    return 0;
}
