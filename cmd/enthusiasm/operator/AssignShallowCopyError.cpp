#include "enthusiasm/operator/AssignShallowCopyError.h"

int main(){
    Person man1("Char eun woo", 27);
    Person man2("Hong Jun Geun", 27);
    man2 = man1;
    man1.showPersonInfo();
    man2.showPersonInfo();
    return 0;
}