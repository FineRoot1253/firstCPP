#ifndef FIRSTCPP_CONSOLEOUTPUT _H
#define FIRSTCPP_CONSOLEOUTPUT _H
#include <iostream>

namespace MySTD{
    class ostream{
    public:
        void operator<<(char * str){
            std::printf("%s", str);
        }
        void operator<<(char str){
            std::printf("%c", str);
        }
        void operator<<(int num){
            std::printf("%d", num);
        }
        void operator<<(double e){
            std::printf("%g", e);
        }
        void operator<<(ostream& (*fp)(ostream &ostream)){
            fp(*this);
        }
    };

    ostream& endl(ostream &ostream){
        ostream<<'\n';
        fflush(stdout);
        return ostream;
    }

    ostream cout;
}
#endif // FIRSTCPP_CONSOLEOUTPUT _H

