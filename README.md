오후 2:04 2025-03-04
c언어의 기본

숫자형-정수형 1, 0, 7, 14..
            (10진수)  ->(2진수)   
         -소수형 1.1,  3.14..
            (부동소수)

2진수

1bit : 0 , 1
2bit 01, 10, 11, 00

nbit당 2에 n제곱 구분

1byte = 8bit 
2에 8제곱 = 256= 256(16에 2제곱)


git에 올리기 문제있음


가상환경 Vmware
	     -wsl2->최적화해서 실행하기 빠름

-ubuntu22.04

-텍스트프로그램
 nano, vi(기본제공프로그램)
Vscode(copilot) :확장성 용이


-git연동 
github(git제공하는 클라우드서비스)

-c언어





숙제
1.VsCode 단축키 + 확장프로그램 확인
2.Readme.md 
md(mark down의 약자)
3.make문법





오전 9:06 2025-03-05 (2일차)

리눅스 명령어(쉘 명령어)
mkdir cd ls touch ...
기본 bash쉘 사용



c언어
텍스트(소스) >전처리>오브젝트파일>바이너리(실행파일)
이 순서를 컴파일이라 한다.(make로 실행가능)

타입type(형) -숫자형 : 정수형(2진수):int, char, long, long long   부동소수형: double, float  <--음수가능
-음수의표현 : unsigned <-음수 사용x 



함수: type(int), 식별자(main()) ; 

type : 정수형, 문자형(charC), void(함수출력x,함수입력x,임의의 인자 전달)★


연산자(계산)
폰 노이만 머신 : 
폰노이만 구조(한번에) 바이트머신
 하버드 구조(개별로)


cpu
-쿨럭이 높으면 출력이 빠름

하드에서 시스템이 출력되면 RAM이 작동하기 시작

변수(variable) :변화가능한 수
-저장 가능한 메모리 공간(RAM)에 확보(식별화)
 RAM-스택: 주로 우리가 한 코딩: 바닥부터 쌓아올림 (함수 형태로 쌓으니 변수의 태가 변하면 치명적)
	-힙: 아무자리에나 malloc, calloc freo의 방식으로 저장(자유롭다보니 메모리 리킹 가능성 有)
 
상수(constant) :변하지 않는 수 ex)0 1 2 3 4 5 6..
이진법으로 설명하고 일일이 만들지 않음




연산자
- 산술연산자: +, -, *, /, %(나머지)

- 대입연산자: =

- 복합대입연산자: +=, -=, *= ...

- 증감연산자: ++, --
 (전위(++a), 후위(a++))

- 관계연산자: >,<,>=,<=,==!= ex (a>b) 결과값 : Y(1)/N(0)

- 논리연산자: &&(and), ||(or),!(not) 결과값: Y/N
1(yes) and(&&) 1(yes) = 1(yes)
1(yes) or(||) 0(no) = 1(yes) <- 둘다 0(no)일때만 값이 0(no)로 나온다
!1(yes) = 0(no), !0(no)=1(yes)

- 형(type casting)변환연산자:  변수에 대해 new type으로 변경. 형변환이 없다면 그대로 유지

- size of 연산자: 결과의 크기(byte)를 표시 

-heap메모리 쓸시: 메모리 크기지정, 변수의 크기

-비트연산자: &(and), ~(not), |(or), <<(이동연단), >>, ^(xor)  
A:    01001110
B:    01101010
A&B:01001010
A|B: 01101110
A~: 10110001
A<<1: 10011100
A<<4: 11100000

전역변수: 프로그램이 끝나도 살아남음
-자동 초기화라 자주사용했었음
-해킹이 쉬워 잘 쓰지않음
지역변수: 프로그램이 끝나면 사라짐
-가비지값이 들어가 있을 수 있기에 초기화 必

대입연산자가 증감연산자보다 우선순위


literal.c
100 : 10진법
0x :16진법
0o: 8진법 옥타
0b: 2진법 바이너리
%f:float
%lldLL\n : longlong 형태



~P.147

숙제
1.프로그래머스 1문제풀기
2. 리눅스 쉘 명령어 정리
3. git을 사용하는 방법



오전 10:21 2025-03-06
if문, for문, while문, switch문, goto문
[흐름제어]
하는 이유: 반복, 체크, 분기


a>조건>b>레이블> c>d

체크
참 a>b>d
거짓 a>c>d

if ~else문
if(조건{int})
if(조건문) > b > else > c >d(값) 
true일경우 a> b> d
false일경우 a>c>d 


반복
a>b>b>c

while(조건문)
a>(조건>b>조건)반복>true일경우 > c>조건
중간에 if문과 break를 사용가능




switch문
switch(변수) > case(값숫자1)break > case (값숫자2)break > case(값숫자3)break ...  
break를 사용하여 case의 순환을 멈출수 있다.


for문(반복문)
for(문장 3개) ㅁ(초기화); ㅁ(조건문); ㅁ(증감문)<-루프 끝에서 한번실행
                                      -----------------
                                         (루프)



삼항연산자(if~else)
조건 > 문장1(true값) >문장2(false값)



convension: 개발자끼리의 룰
의미가 있는 음절 Leaf Year 같이 첫글자를 대문자로 표기(낙타표기법)
코딩작성시 type에 대해(int, float, double,char 등등)
소문자 작성해도 정상작동

단 사용자 정의에 의한것은 낙타표기법 사용



오전 9:02 2025-03-07
복습
실행흐름(thread) - 시간때문에 
하드웨어 : 진동자 -> cpu쿨럭: 대략 33,133MHZ 2.5GHZ 사용

os : 시분할
프로그램 : 시분할

2의보수(2진수 n의보수) :수의체계(연산)
10진수(음수)-> n의보수 10의보수


do while 문
do절에 반복할 내용을 넣고 while을 조건을 건다
한번 시행하고 조건을 걸고 싶을 때 사용


함수(function) 
- 반복적인 코드를 묶어서 실행
ex) printf()

전역변수
(#include)
main함수에 사용가능

main
{
지역변수
(main함수와 main안의 함수)
}


정적지역변수


순서
코드(프로그램코드:상수)
데이터(전역변수,정적 지역변수)
힙
스텍(지역변수,const int)


배열(array): 연속된 같은 type의 자료 
int a1: ㅁ
int a2: ㅁ
int array[5] : ㅁㅁㅁㅁㅁ ={1,2,3,4,5}
==
int array[] :ㅁㅁㅁㅁㅁ ={1,2,3,4,5}


findarray 
summatrix


오전 9:03 2025-03-10
-Data Type(자료,형) - 기본0101...

-연산자 +,-,*,/...

-흐름제어 : else if, which, for, switch


 swap사용시 
temp함수를 넣어 사용

정렬
-선택정렬
a0 a1 a2 a3
3   1   2   0

1번: a0을 기준 min3번비교 swap (a1(기준) - a3(min값)) 
2번 : a1을 기준 min 2번 비교 swap(a1 - a2) 
.
.
.

 
-버블정렬


-q정렬

const 불변


포인터: 주소 값을 저장하는 변수
*(포인터 변수) > 값
 ex) int a = 10;
a= 값
&a = 주소

int *p = 10;
p = 주소
*p = 값(10)

endian
bigendian : 12
littleendian : 78


다중포인터: 이중 포인터는 포인터를 가리킨다
		삼중포인터는 이중포인터를 가리킨다.
		.
		.
		.


-함수(function[주소])포인터: ex) int (*fp)(int, int);
					    (type casting)(___ , ____)
#함수이름 = 포인터타입 (=&함수이름)
nums : 첫원소의주소
sizeof(&nums[0]) : 4byte
sizeof(nums) : 80byte


-void 포인터(포괄형 포인터)
	-캐스팅을 하지 않으면 역참조 불가


배열(상수)과 포인터(변수) 
함수를 포인터에 넣은 것처럼 연산자도 넣을 수 있음
[배열명](상수)>주소값와 높은 확률로 연관되어있다


포인터
1.호출 하는 쪽의 변수를 바꿀때(호출 당하는 함수에서)
2.배열을 넘길때
3.구조체의 자료를 넘길때
4.사용자 정의 연산을 넘길때(함수포인터)
5. 임의의 자료를 넘길때(void *)





오전 8:55 2025-03-11

복습
배열
정렬
포인터 type*[] <- 포인터 변수

분할컴파일
main.c (소스파일) -> main.o -> main(실행파일)
ex) stdio.h(소스파일) > stdio.c(컴파일)
main.c + myRandom.h = main.o my _srand:선언 my_srand() :콜

myRandom.c >myRandom.o  my_srand 


구조체(struct) - 사용자 정의 타입(기본 타입 조합: int, void*, double, char[]..)
-데이터의 형태

객체 지향 프로그래밍 oop - class 사용(데이터, 기능함수)

Mydata; 새로운타입



문자열
코드 - 실행할 코드,상수,함수
데이터 -전역변수, 정적지역변수
힙 - 동적변수
스택 - 지역변수, 매개변수

복습
구조화 - 분할컴파일 해더(전역변수, 구조체, 함수선언,주석), 오브젝트(전역변수, 함수정의..)오브젝트는 해킹으로부터 안전을위해 소스 공개를 안할 때도 있다.

-string.h(해더) :strlen, strcmp, strcat, strcpy

문자열 char* = 상수 >데이터영역에 저장
cha[] = [스택영역] [힙영역]


오전 9:02 2025-03-12
외부 라이브러리 사용연습
sql  -어떤지 검색 -> 어떻게 사용
	설치 > ~.h  ~.o    ~.so(정적링크)<-크고 무겁다   ~.a(동적링크)<-우선적  ex)dll


데이터베이스 - 관계형 데이터베이스(클라우드(AWS, google DB, gcp..), 로컬 -  mysql(IP),sqlite(port))   
		 소켓프로그램(운용) 
tcp통신을 하기위해 IP와 port가 필요
인증으로 ID와 PASS가 필요	



SQL문 연결하는법

sudo apt install 
sudo apt upgrade
sudo apt install mysql-server
mysql --version
dpkg -l | grep mysql
sudo mysql_secure_installation
n y n y y
sudo mysql -u root -p

sudo systemctl status mysql
sudo systemctl enable mysql
sudo mysql -u root -p
use mysql;
select * from users;
alter user root@localhost identified with 'mysql_native password' by '0000';
flush privileges;
create user myuser@'%'identified with mysql_native_password by '0000';
flush privileges;
select host, user from user;

localhost > myuser > 0000 > > ; 


복습
외부라이브러리(Mysqlclient) 
- 검색 API문서 
-컴퓨터에 .h(해더파일)/.o(오브젝트파일)/기타 데이터가 있어야한다
apt install Cdebian{컴퓨터 > .h(해더파일)/.o(오브젝트파일)/기타 데이터}
MYSQLserver + libsqlclient > C programming /C++
Cmake: makefile을 생성하는 도구 + 부가기능:[디버깅][debian 배포][install] 



오전 9:03 2025-03-13

동적 할당 
- 런타임 
- 프로그램 동작 중간 > 자유롭게(힙공간)

정적 할당(메모리에 저장 장소 확보) 
-프로그램 시작 순간
-컴파일 타임 (코드)

c언어함수: realloc: 주로쓰는 함수
	       calloc:	 메모리를 0으로 초기화 후 할당

※반드시 free를 해라


booksql void add delete update query fetch



오전 9:02 2025-03-14
cmake설정- 관리기능(include(~) > sub.directory

동적할당( charadress)

기타문법 (공용체 union), (열거형enum)

booksql






stdin = fgetc = getchar = getc = 문자를 아스키코드로 출력
stdout = fputc = putchar  = putc = 아스키코드를 다시 문자로 출력
 
fflush <- 출력한 되었던 것을 저장하고 밑의 내용을 즉시 출력
ex)sleep함수를 걸고 그 다음함수를 바로 출력하고 싶을 때
우연히 바로 꺼졌을때 fflush함수까지는 저장이 되어 있다.











볼링프로그램 만들기
->입력함수 프레임(frame)    
10프레임까지
각 프레임마다 300점까지 계산
-볼링룰로 만들기

2. 
1번테이블 (사용자명,점수,날짜) > score table
 
2번테이블 (사용자명, 월별 사용자 수,월별 사용 횟수) > date table

3. 1인용으로 가능하면 2인용 




bowling 예시


#include <stdio.h> 

int main() {
    int frames[10][2]; // 각 프레임의 투구 결과를 저장하는 배열
    int scores[10] = {0}; // 각 프레임의 점수를 저장하는 배열
    int totalScore = 0; // 최종 점수

    // 투구 결과 입력 (예시)
    frames[0][0] = 7; frames[0][1] = 2;
    frames[1][0] = 10; frames[1][1] = 0; // 스트라이크
    frames[2][0] = 5; frames[2][1] = 3;
    frames[3][0] = 9; frames[3][1] = 1; // 스페어
    frames[4][0] = 8; frames[4][1] = 1;
    // ... 나머지 프레임 입력 ...

    // 점수 계산
    for (int i = 0; i < 10; i++) {
        if (frames[i][0] == 10) { // 스트라이크
            scores[i] = 10 + frames[i + 1][0] + frames[i + 2][0];
        } else if (frames[i][0] + frames[i][1] == 10) { // 스페어
            scores[i] = 10 + frames[i + 1][0];
        } else { // 오픈 프레임
            scores[i] = frames[i][0] + frames[i][1];
        }
        totalScore += scores[i];
    }

    // 결과 출력
    printf("최종 점수: %d\n", totalScore);

    return 0;
}

오전 9:03 2025-04-01

ATmega -> main이라는 하나의 쓰레드만 작동 > 단순하기에 복잡한 하드웨어와 커다란 시스템 작동 x > 이것들을 작동하기 위해 OS필요
 > OS를 이용해 핸드폰, 로봇, 키오스크 등 개발이 가능

라즈베리파이(임베디드+OS) -> 최적화를 위한 깊은 설정(커널)

펌웨어 : atmega128(레지스트리: ddrx, portx, pinx..), STM32, 라즈베리파이-pico

커널: 운영체제의 핵심 서비스 


오전 9:17 2025-04-02
OS서비스 > 복합적인 프로세스 1. 다중 터미널 한계
					   2. 데몬(주소 연산자를 붙여 실행)   ./limit & < 터미널 종속적으로 실행
					   3. nohup      ./limit & < 터미널 미 종속적으로 실행       
(ps,kill... 등으로 데몬 관리) 

systemd   syscotal   restartmysql


mydemon만들기

     touch mydemon.sh
     code mydemon.sh
     ls
     sudo chmod +x /mydemon.sh
     sudo chmod +x mydemon.sh
     ls -al | grep mydemon
     ./mydemon.sh   (안됨)
     sudo ./mydemon.sh
     cat /var/log/mydemon/system_info.log

//led1 255밝기 led2 120정도 밝기 led3 0밝기 led4 점점 올라가는 밝기 > led_pwm

//RGB LED 빨 > 녹 >파 > 자연스럽게 변화되는 색 나오기 > i2c_rgb_led

//버저에 소리내기  > hard_tone_buzzer

test
// 스위치 1,2,3 을 이용해서   
// 1-> R 색 변화
// 2-> G 색 변화
// 3-> B 색 변화
// 스위치를 오래 누르면(0 ~ 1 초)-> (0~4095) 높은 값으로 변화 할 수 있게 만들기  > i2c_rgb_led_switch

//servo모터 돌리기 > i2c_servo