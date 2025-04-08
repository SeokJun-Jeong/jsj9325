#!/bin/bash

#반복문
#for 변수 in 리스트; do
    #반복할 코드
#done

for name in "seok" "석준" "jeong"; do   
    echo "이름 : $name"
done

echo "0부터 100까지 숫자 프린트 ----"
for int in {0..100}; do
    echo -n "$int "
done

# while() 문장1, 문장2,.. --> while [condition]; do 문장1, 문장2; done
# until 루프 (while의 반대) --> until [condition]; do 문장1, 문장2; done
#break continue와 동일

#함수 -> 아규먼트 없음($1,$2,$3) 소괄호 없음 리턴 없음 > $?
function hello
{
    local testInt=45
    echo "안녕하세요~ $1님"
    return 3
}

hello "정석준"
echo "반환된 값음 $? 입니다."   #return 값 출력
echo "$testInt"


#변수의 선언 > 모든 선언이 전역변수다.


# 크론잡 crontab cron : 시간에 맞추어서 쉘 스크립트를 실행하는 기능

