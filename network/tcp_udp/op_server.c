// ./hello_server
// ./hello_client 127.0.0.1 8888

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

void error_handling(char *message);
int calculate(int opnum, int opnds[], char op);

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int serv_sock;
    int clnt_sock;
    int str_len;

    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size;

    if (argc != 2)  //포트번호 안넣으면 종료
    {
        printf("사용법: %s <port>\n", argv[0]);
        exit(1);
    }

    serv_sock = socket(PF_INET, SOCK_STREAM, 0); // TCP 설정
    if (serv_sock == -1)    //에러시 죽기
        error_handling("socker() 만들기 실패");

    memset(&serv_addr, 0, sizeof(serv_addr));  //주소 정보 0으로 초기화
    serv_addr.sin_family = AF_INET;     //서버주소 설정 IPv4
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // localhost 내부 ip.loopback ip는 아무거나
    serv_addr.sin_port = htons(atoi(argv[1])); //포트는 사용자가 입력한 번호

    int option = 1;
    setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)); //바로 다시 실행가능
    if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) //소켓에 주소 묶기
        error_handling("바인드 에러!!!");
    if (listen(serv_sock, 5) == -1) //최대 5명
        error_handling("리슨 에러"); // 대기!!!

    int opnd_cnt = 0;   //숫자 몇개 받을지
    int recv_len = 0, recv_cnt;
    char opinfo[BUF_SIZE];  //숫자랑 연산자 저장버퍼
    int result; //계산 결과 저장

    for (int i = 0; i < 20; ++i) //20명 클라이언트 받을 준비
    {
        clnt_addr_size = sizeof(clnt_addr);
        clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size); //접속 수락
        if (clnt_sock == -1) //실패시
            error_handling("accept() 에러!!");
        else //성공시
            printf("Conneted client %d : %s \n", i + 1, inet_ntoa(clnt_addr.sin_addr));
        printf("??\n"); 
        read(clnt_sock, &opnd_cnt, 1); ////몇개 보낼건지 1바이트데이터 받기
        printf("피연산자 숫자!%d\n", opnd_cnt); //화면에 출력(디버깅용)

        recv_len = 0;
        while ((opnd_cnt * 4 + 1) > recv_len) // 계산하기 (숫자와 연산자 다받을 때가지 계속 읽기)
        {
            recv_cnt = read(clnt_sock, &opinfo[recv_len], BUF_SIZE - 1);
            recv_len += recv_cnt;
        }
        printf("recv_len : %d", recv_len); //받은 데이터 길이
        printf("연산자 : %c", opinfo[recv_len - 1]); //연산자 문자 출력
        result = calculate(opnd_cnt, (int *)opinfo, opinfo[recv_len - 1]);
        write(clnt_sock, (char *)&result, sizeof(result));  //계산결과
        close(clnt_sock); //연결 끊기
    }

    close(serv_sock);  //서버 끊기

    return 0;
}

void error_handling(char *message)  //에러메세지 출력후 프로그램 종료
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

int calculate(int opnum, int opnds[], char op) //+,-,*계산하는 함수
{
    int result = opnds[0], i;
    switch (op)
    {
    case '+':
        for (i = 1; i < opnum; ++i)
            result += opnds[i];
        break;
    case '*':
        for (i = 1; i < opnum; ++i)
            result *= opnds[i];
        break;
    case '-':
        for (i = 1; i < opnum; ++i)
            result -= opnds[i];
        break;
    default:
        result = 0;
    }

    return result;
}