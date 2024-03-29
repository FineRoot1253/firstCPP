/*  예제 : 두 정수의 덧셈과 뺄셈 결과 구하기
    파일 이름 : exam2-3.c
    수정 일자 : 2023년 4월 8일
    작성자 : 홍준근
 */
// 도입부이며 헤더 파일을 포함시키는 선행처리기이며 사용자가 정의한 파일을 포함시키기 위해
// 큰 따옴표 "~.h"로 감싼 뒤 파일명과 함께 헤더 파일 위치를 지정하였다.
// 그리고 반드시 파일의 확장자는 "~.h"로 끝나는 헤더파일이여야 한다.
// 참고로 exam2-3.h에 stdio.h 파일을 이미 포함하고 있으므로  printf()함수를 문제없이 호출할 수 있다.
#include "exam2-3.h"

void main(){ // main 함수의 시작이며 중괄호 { 으로 시작한다.
    // 정수를 저장하는 변수를 add_result, sub_result 두 개를 선언했다.
    // 선언은 했지만 초기화 및 변수 사용은 하지 않았다.
    int add_result, sub_result;
    // 문자열을 출력하는 printf() 함수이다. 형식 지정자를 통해 10진 정수와 함께 문자열을 출력하고 있으며
    // 현재 출력하려는 10진 정수는 미리 매크로 함수로 지정해둔 ADD의 결과이며 이 함수는 ((x)+(y))으로 치환된다.
    printf("10과 5를 더하면 %d이다.\n",ADD(10, 5));
    // 문자열을 출력하는 printf() 함수이다. 형식 지정자를 통해 10진 정수와 함께 문자열을 출력하고 있으며
    // 현재 출력하려는 10진 정수는 미리 매크로 함수로 지정해둔 SUB의 결과이며 이 함수는 ((x)-(y))으로 치환된다.
    printf("10과 5를 빼면 %d이다.\n",SUB(10, 5));
} // main 함수의 끝이며 중괄호 }으로 닫는다.