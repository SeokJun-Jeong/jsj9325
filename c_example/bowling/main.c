#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_menu(void)
{
    system("clear");
    printf("==볼링 점수판 ===\n");
    printf("1. 게임플레이\n");
    printf("2.기록보기\n");
    printf("3. 종료\n");
    printf("선택: ");
}

void initMYSQL(MYSQL *conn)
{
    printf("--- 도서 추가 ---\n");
    Book newbook;
    char query[255];
    // 정보 입력 scanf
    printf("도서 ID: ");
    scanf("%d%*c", &newbook.bookid);
    printf("도서 명: ");
    scanf("%s%*c", newbook.bookname);
    printf("출판사: ");
    scanf("%s%*c", newbook.publisher);
    printf("가격: ");
    scanf("%d%*c", &newbook.price);
    // query 문 작성 strcpy... "insert ....."
    sprintf(query, "insert into Book values (%d, '%s', '%s', %d)", newbook.bookid, newbook.bookname, newbook.publisher, newbook.price);
    // query 요청 mysql_query();
    if (mysql_query(conn, query))
    {
        printf("데이터 입력 실패: %s\n", mysql_error(conn));
    }
    else
    {
        printf("입력 성공\n");
    }

    return;
}


