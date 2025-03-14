// 볼드, 이탈릭, 쉐도우, 언더라인을 표현하는 변수를 만들어라
// 비트 연산
#include<stdio.h>
//볼드 1 자리비트  0b000001
//이탈릭 2 자리비트 0b000010
//쉐도우 3 자리비트 0b000100
//언더라인 4 자리비트 0b001000
//볼드 이면서 언더라인 0b001001
#define bold 0x01
#define italic 0x02   // = #define italic (0x01 << 1)
#define shadow 0x04  // = #define shadow (0x01 << 2)
#define ul 0x08   // = #define underline (0x01 << 3)

void printattrib(unsigned char attr);

int main(void)
{

    unsigned char attr; //8bit 8개 속성
    attr = attr ^ attr; //모두 0

    attr = attr | bold; //attr 볼드로 설정
   // printf("attr : 0x%02x\n",attr);
    printattrib(attr);

    attr = attr |(italic | shadow); //attr 이탈릭 + 쉐도우 추가
   // printf("attr: 0x%02x\n", attr);
   printattrib(attr);


    attr = attr &(~bold); // attr 볼드 제거
   // printf("attr: 0x%02x\n", attr);
   printattrib(attr);
    

    return 0 ;
}


void printattrib(unsigned char attr)
{
    // printf("attr : 0x%02x\n", attr);
    // printf("bold : %d\n", !(~(attr | ~bold)));
    // printf("italic : %d\n", !(~(attr | ~italic)>>1));
    // printf("shadow : %d\n", !(~(attr | ~shadow)>>2));
    // printf("ul : %d\n", !(~(attr | ~ul)>>3));
    // printf("--------------------\n");

    printf("bold : %d\n", (attr & bold));
    printf("italic : %d\n", (attr & italic));
    printf("shadow : %d\n", (attr & shadow));
    printf("ul : %d\n", (attr & ul));
    printf("--------------------\n");
}