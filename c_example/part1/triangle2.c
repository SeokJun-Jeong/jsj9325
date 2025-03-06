#include <stdio.h>

int main(void)

{
    double length;
    double height;
    double area ;

    printf("enter triangle's length : ");
    scanf("%lf", &length);
    printf("enter triangle's height : ");
    scanf("%lf", &height);
    area= length * height /2 ; 
    printf("triangle's areea is : %f\n", area );
    return 0 ;
}