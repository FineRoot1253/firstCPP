//
// Created by 홍준근 on 2022/11/20.
//

#include <iostream>

typedef struct Animal{
    char name[30];
    int age;

    int health;
    int food;
    int clean;
} Animal;

void createAnimal(Animal *animal){
    std::cout<<"동물의 이름은? ";
    std::cin>> animal->name;

    std::cout<<"동물의 나이는? ";
    std::cin>> animal->age;

    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;
}

void play(Animal *animal){
    animal->health += 10;
    animal->food -= 20;
    animal->clean -= 30;
}

void afterOneDay(Animal *animal){
    animal->health -= 10;
    animal->food -= 30;
    animal->clean -= 20;
}

void showStat(Animal *animal){
    std::cout << animal->name <<"의 상태" << std::endl;
    std::cout <<"체력: " << animal->health  << std::endl;
    std::cout <<"배부름: " << animal->food  << std::endl;
    std::cout <<"청결: " << animal->clean  << std::endl;
}

int main(){
    Animal* list[10];

    int animalNum = 0;

    while(true){
        std::cout <<"1. 동물 추가하기"<< std::endl;
        std::cout <<"2. 놀기" << std::endl;
        std::cout <<"3. 상태보기 " << std::endl;

        int input;
        int selectInput;
        std::cin>> input;

        switch(input){
            case 1:
                list[animalNum] = new Animal ;
                createAnimal(list[animalNum]);
                animalNum++;
                break;
            case 2:
                std::cout<< "누구랑 놀꺼야?: ";
                std::cin >> selectInput;
                if(selectInput < animalNum) {
                    play(list[selectInput]);
                }
                break;
            case 3:
                std::cout<< "누구껄 볼래?: ";
                std::cin >> selectInput;
                if(selectInput < animalNum) {
                    showStat(list[selectInput]);
                }
                break;
        }

        for(int i = 0; i != animalNum; i++){
            afterOneDay(list[i]);
        }
    }
    for(int i = 0; i != animalNum; i++){
        delete list[i];
    }
}