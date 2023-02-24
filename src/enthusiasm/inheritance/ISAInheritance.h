#ifndef FIRSTCPP_ISAINHERITANCE _H
#define FIRSTCPP_ISAINHERITANCE _H

#include <iostream>
#include <cstring>

class Computer {
private:
    char *owner;
public:
    Computer(char *owner) {
        this->owner = new char[std::strlen(owner) + 1];
        std::strcpy(this->owner, owner);
    }

    ~Computer() {
        delete[]owner;
    }

    void calculate() {
        std::cout << "요청 내용을 계산합니다." << std::endl;
    }
};

class NoteBookComputer : public Computer {
private:
    int battery;
public:
    NoteBookComputer(char *name, int initBatteryGauge)
            : Computer(name)
            , battery(initBatteryGauge) {}

    void charging(){
        battery+=5;
    }

    void useBattery(){
        battery -=1;
    }

    void movingCal(){
        if(getBattery()<1){
            std::cout<<"충전이 필요합니다."<<std::endl;
            return;
        }
        std::cout<<"이동하면서";
        calculate();
        useBattery();
    }

    int getBattery() const {
        return battery;
    }
};

class TabletNotebook: public NoteBookComputer{
private:
    char *registerPenModel;
public:
    TabletNotebook(char* name, int initBatteryGauge, char* registerPenModel): NoteBookComputer(name, initBatteryGauge){
        this->registerPenModel = new char[std::strlen(registerPenModel) + 1];
        std::strcpy(this->registerPenModel, registerPenModel);
    }
    ~TabletNotebook(){
        delete []registerPenModel;
    }

    void write(char* penInfo){
        if(std::strcmp(registerPenModel, penInfo)){
            std::cout<<"등록된 펜이 아닙니다."<<std::endl;
            return;
        }
        std::cout<<"필기 내용을 처리합니다."<<std::endl;
        useBattery();
    }
};

#endif // FIRSTCPP_ISAINHERITANCE _H

