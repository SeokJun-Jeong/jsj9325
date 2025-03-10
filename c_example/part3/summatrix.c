#include<stdio.h>

int summatrix(int (*pM)[4], int n, int m);

int main(void)
{
    int matrix[3][4]=
    {{1,2,3,4},
     {11,12,13,14},
     {21,22,23,24}};
    int sum = summatrix(matrix,
    (sizeof(matrix)/sizeof(int))/(sizeof(matrix[0])/sizeof(int)),
    sizeof(matrix[0])/sizeof(int)); // (48/4)(16/4)=3    (16/4)=4

    printf("sum of Matrix : %d\n",sum);
    return 0;
}
int summatrix(int (*pM)[4], int n, int m)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            sum += pM[i][j];
        }
        
    }
    return sum;
}