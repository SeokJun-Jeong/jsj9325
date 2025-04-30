#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 1024

void error_handling(char *message);

int main(int argc, char *argv[])
{
    int sock;

    struct sockaddr_in serv_addr;   //서버 주소 저장할 구조첸

    if (argc != 3) //ip, port제대로 안넣으면 종료
    {
        printf("사용법: %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0); // TCP 설정
    if (sock == -1) //tcp 못 만들면 에러 출력 후 종료
        error_handling("socker() 열기 실패!!");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]); // localhost 는 입력 받을 수 없는 코드
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) //서버에 연결 시도 (실패시 에러 성공시 connect출력)
        error_handling("connet() 연결 실패!!!"); // listen 상태의 서버에 접속
    else
        puts("Connected............");
    char message[BUF_SIZE];  //보낼 데이터
    int str_len, recv_len, recv_cnt;
    int result, opnd_cnt, i; //숫자 개수, 계산 결과

    fputs("피 연산자 객수를 넣으세요!: ", stdout);
    scanf("%d", &opnd_cnt);
    message[0] = (char)opnd_cnt;  //숫자 몇 개 보낼건지 입력 받고 message에 저장

    for (i = 0; i < opnd_cnt; ++i) //개수 만큼 for문 돌리고 숫자 입력받아 message에 저장 
    {
        printf(" %d 번째 피 연산자 를 넣으세요!: ", i + 1);
        scanf("%d", (int *)&message[i * 4 + 1]);
    }
    fgetc(stdin); // 버퍼에 남은것 버리기
    fputs("연산자를 넣으세요! :", stdout); //연산자 입력 받기
    scanf("%c", &message[opnd_cnt * 4 + 1]);  //숫자들 뒤에 저장
    fputs("메세지는 !!: ", stdout); //message내용(0~9)들 출력 (디버깅용)
    fputc(message[0], stdout);
    fputc(message[1], stdout);
    fputc(message[2], stdout);
    fputc(message[3], stdout);
    fputc(message[4], stdout);
    fputc(message[5], stdout);
    fputc(message[6], stdout);
    fputc(message[7], stdout);
    fputc(message[8], stdout);
    fputc(message[9], stdout);
    fputs("메세지는 !!: ", stdout);

    write(sock, message, opnd_cnt * 4 + 2); //서버에 데이터 전송 (byte)

    read(sock, &result, 4); //서버로 부터 계산결과 받기 (4byte)

    printf("연산의 결과는: %d \n", result); //결과 출력
    close(sock); //소켓다기

    return 0;
}
void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}