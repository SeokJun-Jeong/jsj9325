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

void fetch_books(MYSQL *conn);
void add_books(MYSQL *conn);
void delete_books(MYSQL *conn);
void update_books(MYSQL *conn);
void query_books(MYSQL *conn);
void print_menu(void);
void waitEnter(void);

int main(void)
{
    MYSQL *conn;
    char *host = "localhost";
    char *user = "myuser";
    char *pass = "0000";
    char *db = "mydb";
    int port = 3306;
    int choice;
    
    
    //연결
    conn = mysql_init(NULL); //DB 연결 요청 준비
    if(mysql_real_connect(conn,host,user,pass,db,port,NULL,0))
    {
        printf("MYSQL 연결 성공\n");
    }
    else
    {
        printf("MYSQL 연결 실패\n");
        return 1;
    }
    while (true)
    {
    //   printf("1,2번 고르세요");
      print_menu();
      scanf("%d%*c",&choice);
      switch (choice)
      {
        case SELECT:
          fetch_books(conn);
      
            break;

        case INSERT:
          add_books(conn);
      
            break;

        case DROP:
        delete_books(conn);
  
           break;

        case ALTER:
             update_books(conn);
  
           break;

        case QUERY:
         query_books(conn);
  
           break;

      }
  
    }
    mysql_close(conn);

    return 0;
    }

void print_menu(void)
{
    system("clear");
    printf("==도서 관리 시스템 ===\n");
    printf("0.도서 조회\n");
    printf("1.도서 추가\n");
    printf("2.도서 삭제\n");
    printf("3.도서 변경\n");
    printf("4. 쿼리문 입력\n");
}

void add_books(MYSQL *conn)
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
    int temp;
    getchar();
    scanf("%d%*c", &temp);
}

void delete_books(MYSQL *conn)
{
    // index 번호 받기scanf
    // 지우는 쿼리
    int bookid;
    printf("삭제할 도서명 : ");
    scanf("%d%*c", &bookid);
    char query[255];
    sprintf(query,"delete from Book where bookid = %d",bookid);

    if (mysql_query(conn, query))
    {
        printf("쿼리 실패 : %s", mysql_error(conn));

    }
    else
    {
        my_ulonglong affected_row = mysql_affected_rows(conn);
        printf("삭제 성공 : %lu개",affected_row);
    }
    int temp;
    getchar();
    scanf("%d%*c", &temp);
}

void update_books(MYSQL *conn)
{
    // 모든 번호 받기scanf
    // 변경하는 쿼리
    printf("--- 도서 변경 ---\n");
    Book upbook;
    char query[255];
    printf("변경도서 ID:");
    scanf("%d%*c", &upbook.bookid);
    printf("변경도서명:");
    scanf("%s%*c", upbook.bookname);
    printf("변경출판사:");
    scanf("%s%*c", upbook.publisher);
    printf("변경도서가격:");
    scanf("%d%*c", &upbook.price);
    
    sprintf(query,"update Book set bookname = '%s', publisher = '%s', price = %d where bookid = %d",upbook.bookname,upbook.publisher, upbook.price,upbook.bookid);
    if (mysql_query(conn,query))
    {
        printf("데이터 변경 실패: %s\n",mysql_error(conn));
    }
    else
    {
        printf("변경성공 \n");
    }
    int temp;
    getchar();
    scanf("%d%*c",&temp);
}



void query_books(MYSQL *conn)
{
    // 쿼리 스트링을 받아서
    // 쿼리 요청
    // 결과 프린트
    MYSQL_RES *res;
    MYSQL_ROW row;
    char query[255];
    printf("실행할 쿼리를 넣어 주세요. ");
    fgets(query,sizeof(query),stdin);
    query[strcspn(query, "\n")] = 0;
    printf("쿼리 : %s\n",query);
    if (mysql_query(conn,query))
    {
        printf("쿼리 실패 %s\n", mysql_error(conn));
        return ;
    }
    
    res = mysql_store_result(conn);
    if (res)
    {
        while (row = mysql_fetch_row(res))
        {
            for (int i = 0; i < mysql_num_fields(res); ++i)
            {
                printf("%s\t", row[i]);
            }
            printf("\n");
        }
        
    }
    else
    {
        printf("요청한 데이터가 없습니다.\n");
    }
    waitEnter();
    int temp;
    getchar();
    scanf("%d%*c", &temp);
}

void fetch_books(MYSQL *conn)
{

    MYSQL_RES *res;
    MYSQL_ROW row;
    char query[255];
    strcpy(query, "select * from Book");

  //쿼리 요청
  if(mysql_query(conn,query))
  {
      printf("쿼리 실패\n");
      return ;
  }
  res = mysql_store_result(conn);
  if (!res)
    {
    printf("연결 실패\n");
    return;
   }

    
//     fetch_books(conn);
     //add_books(conn);
//   }
  Book *pBook;
  pBook = (Book *)malloc(sizeof(Book));
  int i= 0;
  //데이터 베이스의 정보를 구조체에 저장
  while(row = mysql_fetch_row(res))
  {
      // printf("%s\t\t",row[0]);
      // printf("%s\t\t",row[1]);
      // printf("%s\t\t",row[2]);
      // printf("%d\t\t\n",atoi(row[3]));
      (pBook+i)->bookid = atoi(row[0]);
      strcpy((pBook+i)->bookname, row[1]);
      strcpy((pBook+i)->publisher, row[2]);
      (pBook+i)->price = atoi(row[3]);
      ++i;
      pBook = realloc(pBook, sizeof(Book)*(i+1));
  };
  
  for (int j = 0; j < i; ++j)
  {
      printf("%d \t%s \t%s \t%d \n",
        (pBook+j)->bookid, 
        (pBook+j)->bookname,
        (pBook+j)->publisher,
        (pBook+j)->price);
  }
  free(pBook);
  // TODO :여기 엔터만 쳐도 넘어가게변경
  int temp;
  getchar();
  scanf("%d%*c", &temp);
}

void waitEnter(void)
{
    printf("엔터를 쳐 주세요\n");
    char temp;
    while (temp !='\n')
    scanf("%c%*c",&temp);
}