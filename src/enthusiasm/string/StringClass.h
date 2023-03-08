#ifndef FIRSTCPP_STRINGCLASS_H
#define FIRSTCPP_STRINGCLASS_H
#include <iostream>

class String{
private:
    int length;
    char *value;
public:
    String();
    String(const char* string);
    String(const String& ref);
    ~String();
    String& operator=(const String& ref);
    String& operator+=(const String& ref);
    bool operator==(const String& ref);
    String operator+(const String& ref);

    friend std::ostream& operator<<(std::ostream& output, const String& string);
    friend std::istream& operator>>(std::istream& input, String& string);
};
#endif // FIRSTCPP_STRINGCLASS_H

