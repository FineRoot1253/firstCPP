#ifndef FIRSTCPP_ITERATECONSOLEOUTPUT _H
#define FIRSTCPP_ITERATECONSOLEOUTPUT _H
#include <iostream>

namespace MySTD{
    class ostream{
    public:
        ostream& operator<<(char * str){
            std::printf("%s", str);
            return *this;
        }
        ostream& operator<<(char str){
            std::printf("%c", str);
            return *this;
        }
        ostream& operator<<(int num){
            std::printf("%d", num);
            return *this;
        }
        ostream& operator<<(double e){
            std::printf("%g", e);
            return *this;
        }
        ostream& operator<<(ostream& (*fp)(ostream &ostream)){
            fp(*this);
            return *this;
        }
    };

    ostream& endl(ostream &ostream){
        ostream<<'\n';
        fflush(stdout);
        return ostream;
    }

    ostream cout;
}
#endif // FIRSTCPP_ITERATECONSOLEOUTPUT _H

