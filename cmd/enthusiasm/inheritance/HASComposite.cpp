#include "enthusiasm/inheritance/HASComposite.h"

int main(){
    PoliceOffice policeOffice1(5, 3);
    policeOffice1.shot();
    policeOffice1.putHandCuff();

    PoliceOffice policeOffice2(0, 3);
    policeOffice2.shot();
    policeOffice2.putHandCuff();
    return 0;
}