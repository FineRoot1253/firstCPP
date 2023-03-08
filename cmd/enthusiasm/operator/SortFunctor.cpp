#include "enthusiasm/operator/SortFunctor.h"

int main(){
    DataStorage storage(5);
    storage.addData(40);
    storage.addData(50);
    storage.addData(30);
    storage.addData(10);
    storage.addData(20);

    storage.sortData(AscendingSort());
    storage.showAllData();

    storage.sortData(DescendingSort());
    storage.showAllData();
    return 0;
}


