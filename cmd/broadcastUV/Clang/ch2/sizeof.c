/*  예제 : 자료형의 크기 출력하기
    파일 이름 : sizeof.c
    수정 일자 : 2023년 4월 8일
    작성자 : 홍준근
 */
#include <stdio.h> // 도입부이며 헤더 파일을 포함시키는 선행처리기 표준 디렉터리에 존재하는 파일을 포함시키는 것이기 때문에
// '<','>' 으로 감싼 뒤 파일명을 적었다. 그리고 파일은 반드시 헤더파일인 "~.h" 확장자를 가진 파일이여야한다.
void main(){ // main 함수의 시작이며 중괄호 { 으로 시작한다.
    //문자열을 출력하는 printf 함수이며 형식지정자를 통해 정수형 데이터로 정수 값을 출력하고 있다.
    //이 호출은 char 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 char 타입의 byte 크기이며 1이 출력된다.
    printf("char 자료형 크기 : %d byte\n",sizeof(char));
    //이 호출은 signed char 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 signed char 타입의 byte 크기이며 1이 출력된다.
    printf("signed char 자료형 크기 : %d byte\n",sizeof(signed char));
    //이 호출은 unsigned char 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 unsigned char 타입의 byte 크기이며 1이 출력된다.
    printf("unsigned char 자료형 크기 : %d byte\n",sizeof(unsigned char));
    //이 호출은 short 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 short 타입의 byte 크기이며 2가 출력된다.
    printf("short 자료형 크기 : %d byte\n",sizeof(short));
    //이 호출은 short int 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 short int 타입의 byte 크기이며 2가 출력된다.
    printf("short int 자료형 크기 : %d byte\n",sizeof(short int));
    //이 호출은 signed short 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 signed short 타입의 byte 크기이며 2가 출력된다.
    printf("signed short 자료형 크기 : %d byte\n",sizeof(signed short));
    //이 호출은 signed short int 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 signed short int 타입의 byte 크기이며 2가 출력된다.
    printf("signed short int 자료형 크기 : %d byte\n",sizeof(signed short int));
    //이 호출은 char 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 char 타입의 unsigned short 크기이며 2가 출력된다.
    printf("unsigned short 자료형 크기 : %d byte\n",sizeof(unsigned short));
    //이 호출은 char 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 char 타입의 unsigned short int 크기이며 2가 출력된다.
    printf("unsigned short int 자료형 크기 : %d byte\n",sizeof(unsigned short int));
    //이 호출은 char 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 int 타입의 byte 크기이며 4가 출력된다.
    printf("int 자료형 크기 : %d byte\n",sizeof(int));
    //이 호출은 char 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 signed int 타입의 byte 크기이며 4가 출력된다.
    printf("signed int 자료형 크기 : %d byte\n",sizeof(signed int));
    //이 호출은 char 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 unsigned 타입의 byte 크기이며 4가 출력된다.
    printf("unsigned 자료형 크기 : %d byte\n",sizeof(unsigned));
    //이 호출은 char 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 unsigned int 타입의 byte 크기이며 4가 출력된다.
    printf("unsigned int 자료형 크기 : %d byte\n",sizeof(unsigned int));
    //이 호출은 char 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 long 타입의 byte 크기이며 8이 출력된다.
    printf("long 자료형 크기 : %d byte\n",sizeof(long));
    //이 호출은 char 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 long int 타입의 byte 크기이며 8이 출력된다.
    printf ("long int 자료형 크기 : %d byte\n",sizeof(long int));
    //이 호출은 char 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 signed long 타입의 byte 크기이며 8이 출력된다.
    printf("signed long 자료형 크기 : %d byte\n" ,sizeof(signed long));
    //이 호출은 char 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 signed long int 타입의 byte 크기이며 8이 출력된다.
    printf( "signed long int 자료형 크기 : %d byte\n",sizeof(signed long int));
    //이 호출은 char 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 unsigned long 타입의 byte 크기이며 8이 출력된다.
    printf("unsigned long 자료형 크기 : %d byte\n",sizeof(unsigned long));
    //이 호출은 char 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 unsigned long int 타입의 byte 크기이며 8이 출력된다.
    printf("unsigned long int 자료형 크기 : %d byte\n",sizeof(unsigned long int));
    //이 호출은 char 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 long long 타입의 byte 크기이며 8이 출력된다.
    printf("long long 자료형 크기 : %d byte\n",sizeof(long long));
    //이 호출은 char 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 long long int 타입의 byte 크기이며 8이 출력된다.
    printf("long long int 자료형 크기 : %d byte\n", sizeof(long long int));
    //이 호출은 char 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 signed long long 타입의 byte 크기이며 8이 출력된다.
    printf("signed long long 자료형 크기 : %d byte\n",sizeof(signed long long));
    //이 호출은 char 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 signed long long int 타입의 byte 크기이며 8이 출력된다.
    printf("signed long long int 자료형 크기 : %d byte\n",sizeof(signed long long int));
    //이 호출은 char 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 unsigned long long 타입의 byte 크기이며 8이 출력된다.
    printf("unsigned long long 자료형 크기 : %d byte\n",sizeof(unsigned long long));
    //이 호출은 char 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 unsigned long long int 타입의 byte 크기이며 8이 출력된다.
    printf("unsigned long long int 자료형 크기 : %d byte\n", sizeof(unsigned long long int));
    //이 호출은 char 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 float 타입의 byte 크기이며 4가 출력된다.
    printf("float 자료형 크기 : %d byte\n", sizeof(float));
    //이 호출은 char 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 double 타입의 byte 크기이며 8이 출력된다.
    printf("double 자료형 크기 : %d byte\n",sizeof(double));
    //이 호출은 char 자료형 크기 : (정수 값) byte를 출력하며 정수 값은 long double 타입의 byte 크기이며 16이 출력된다.
    printf("long double 자료형 크기 : %d byte\n", sizeof(long double));
}// main 함수 종료이며 중괄호 } 으로 닫는다.