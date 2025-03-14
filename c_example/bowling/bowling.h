#include <stdio.h>
#include <time.h>
#include <mysql.h>
#include <string.h>

typedef struct 
{
    int point;
    int frame;
    int openframe;
    char strike[40];
    char spair[40];
    char guter[40];
}bowling;

enum board
{
    round,
    point

};

void print_menu(void);
void month_summary(void);
