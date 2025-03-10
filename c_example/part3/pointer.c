#include <stdio.h>

int main(void)
{
    int var_a,var_b;
    int *pvar;

    var_a = 100;
    pvar = & var_b; //포인터는 변수와 연결을 해야한다
    *pvar = 200;  //포인터는 반드시 대상을 가리키고 역참조를 해야한다
    printf("var_a : %d, &var_a : %p\n", var_a,&var_a);
    printf("*pvar : %d, pvar : %p\n",*pvar,&var_b);
    printf("var_b : %d, &var_b : %p\n", var_b,&var_b);
    return 0;
}