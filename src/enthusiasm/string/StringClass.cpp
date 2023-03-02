//
// Created by 홍준근 on 2023/03/02.
//
#include "StringClass.h"

String::String() {
    length = 0;
    value = nullptr;
}

String::String(const char *string) {
    length = std::strlen(string);
    value = new char[length];
    std::strcpy(value, string);
}

String::String(const String &ref) {
    length = ref.length;
    value = new char[length];
    std::strcpy(value, ref.value);
}

String::~String() {
    if(value != nullptr){
        delete[] value;
    }
}

String& String::operator=(const String &ref) {
    if(value != nullptr){
        delete[] value;
    }
    length = ref.length;
    value = new char[length];
    std::strcpy(value, ref.value);
    return *this;
}

String& String::operator+=(const String &ref) {
    length +=(ref.length -1);
    char* temp = new char[length];
    std::strcpy(temp, value);
    std::strcat(temp, ref.value);
    if(value != nullptr){
        delete[] value;
    }
    value = temp;
    return *this;
}

bool String::operator==(const String &ref) {
    return !std::strcmp(value, ref.value);
}

String String::operator+(const String &ref) {
    char* temp = new char[length + ref.length -1];
    std::strcpy(temp, value);
    std::strcat(temp, ref.value);
    delete[] temp;
    return String(temp);
}

std::ostream &operator<<(std::ostream &output, const String &string) {
    output<<string.value;
    return output;
}

std::istream &operator>>(std::istream &input, String &string) {
    char str[100];
    input>>str;
    string = String(str);
    return input;
}
