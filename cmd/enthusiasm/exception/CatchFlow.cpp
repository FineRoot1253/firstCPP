#include "enthusiasm/exception/CatchFlow.h"

int main(){
    try{
        exceptionGenerator(3);
        exceptionGenerator(2);
        exceptionGenerator(1);
    }catch (ExceptionAAA &ex){
        std::cout<<"catch (ExceptionAAA &ex)"<<std::endl;
        ex.showYourSelf();
    }catch (ExceptionBBB &ex){
        std::cout<<"catch (ExceptionBBB &ex)"<<std::endl;
        ex.showYourSelf();
    }catch (ExceptionCCC& ex){
        std::cout<<"catch (ExceptionCCC& ex)"<<std::endl;
        ex.showYourSelf();
    }
    return 0;
}


