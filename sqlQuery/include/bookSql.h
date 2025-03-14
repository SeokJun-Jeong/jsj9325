#include <stdio.h>
#include <string.h>
#include <mysql.h>

//sudo apt install libmysql++*
//dpkg -L libmysqlcilent-dev | grep mysql.h
//외부라이브러리이므로 명시
// cc -o bookSql bookSql.c -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient
typedef struct 
{
    int bookid;
    char bookname[40];
    char publisher[40];
    int price;
} Book;

enum menu
{
    SELECT, 
    INSERT, 
    DROP, 
    ALTER, 
    QUERY
};