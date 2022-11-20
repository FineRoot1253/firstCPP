//
// Created by 홍준근 on 2022/11/20.
//
#include "header1.h"
#include "header2.h"
#include "nonamespace_header3.h"

//using header1::foo; // 특정 함수만 사용시
using namespace header1; // 전체 사용시
// TODO: using은 함수 충돌 문제로 C++ 라이브러리에 사용하는 것은 권장되지 않음

int func() {
    foo();
    bar();
    header2::bar();
    OnlyInThisFile();
    only_in_this_file = 3;
}