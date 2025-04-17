#include <iostream>
#include "empty.h"

int main()
{
    Empty e1;         //생성자가 없을시 default 생성자 자동생성
    Empty e2 = e1;  //복사 생성자(가능)

    e1 = e2;        //치환(가능)

    Empty *p1 = &e1;        //e1.operator&() &의 연산 (가능)

    const Empty e3;
    const Empty *p2 = &e3;


    return 0;
}