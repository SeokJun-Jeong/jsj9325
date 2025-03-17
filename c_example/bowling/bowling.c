#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 100  // 사용자 최대 수
#define MAX_NAME_LEN 50 // 사용자명 최대 길이


char userName[MAX_NAME_LEN];
int month, choice;


// 사용자 정보를 저장하는 구조체
typedef struct {
    char name[MAX_NAME_LEN]; // 사용자명
    int usageCount[12];      // 월별 사용 횟수 (1월 ~ 12월)
} User;

User users[MAX_USERS];  // 사용자 목록
int userCount = 0;      // 현재까지 등록된 사용자 수

// 볼링 점수를 저장하는 구조체
typedef struct {
    int first;
    int second;
    int bonus;
    int totalScore;  // 현재 프레임까지의 총점 저장
} Frame;

// 사용자명과 월을 받아 사용 횟수를 업데이트하는 함수
void updateUsageCount(const char *name, int month) {
    int found = -1;

    // 사용자 찾기
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, name) == 0) {
            found = i;
            break;
        }
    }

    // 사용자가 없으면 새 사용자 추가
    if (found == -1) {
        strcpy(users[userCount].name, name);
        for (int i = 0; i < 12; i++) {
            users[userCount].usageCount[i] = 0;
        }
        found = userCount;
        userCount++;
    }

    // 월별 사용 횟수 업데이트
    users[found].usageCount[month - 1]++;
}

// 월별 사용자 사용 횟수 출력
void printUsageStats() {
    printf("\n===== 월별 사용자 사용 횟수 =====\n");
    for (int i = 0; i < userCount; i++) {
        printf("사용자: %s\n", users[i].name);
        for (int j = 0; j < 12; j++) {
            printf("  %d월: %d회\n", j + 1, users[i].usageCount[j]);
        }
    }
}

// 점수가 음수일 경우 오류를 출력하는 함수
int isValidScore(int score) {
    if (score < 0) {
        printf("error: 점수는 음수일 수 없습니다.\n");
        return 0;  // 점수 오류
    }
    return 1;  // 정상 점수
}

// 볼링 점수를 계산하고 출력하는 함수
void calculateBowlingScores() {
    Frame frames[10];  // 10개의 프레임 선언
    int totalScore = 0; // 총 점수 저장 변수
    int i;

    // 1. 프레임 초기화
    for (i = 0; i < 10; i++) {
        frames[i].first = 0;
        frames[i].second = 0;
        frames[i].bonus = 0;
        frames[i].totalScore = 0;
    }

    // 2. 점수 입력 (각 프레임마다)
    for (i = 0; i < 10; i++) {
        printf("\n===== Frame %d =====\n", i + 1);

        // 첫 번째 투구
        printf("첫번쩨: ");
        scanf("%d", &frames[i].first);
        if (!isValidScore(frames[i].first)) return; // 음수일 경우 종료

        // 스트라이크 처리 (1~9프레임)
        if (frames[i].first == 10 && i < 9) 
        {
            printf("스트라이크\n");
            frames[i].second = 0; // 스트라이크는 두 번째 투구가 없으므로 0으로 설정
        } 
        else 
        {
            // 두 번째 투구
            printf("두번째: ");
            scanf("%d", &frames[i].second);
            if (!isValidScore(frames[i].second)) return; // 음수일 경우 종료

            // 1~9프레임에서 10점 이상일 경우 오류
            if (frames[i].first + frames[i].second > 10 & i <9) {
                printf("10을 초과할수 없습니다.\n");
                return;
            }
        }

        // 10번째 프레임의 보너스 투구 처리
        if (i == 9 && (frames[i].first == 10 || (frames[i].first + frames[i].second == 10))) 
        {
            printf("bonus: ");
            scanf("%d", &frames[i].bonus);
            if (!isValidScore(frames[i].bonus)) return; // 음수일 경우 종료
        }

        // 3. 점수 계산
        totalScore = 0;
        for (int j = 0; j <= i; j++) {
            totalScore += frames[j].first + frames[j].second + frames[j].bonus;

            // 1~9 프레임에서 보너스 점수 계산
            if (j < 9) {
                if (frames[j].first == 10) {  // 스트라이크
                    totalScore += frames[j + 1].first + frames[j + 1].second;
                    if (frames[j + 1].first == 10 && j + 2 <= 10) {
                        totalScore += frames[j + 2].first;  // 연속 스트라이크일 경우, 세 번째 프레임 첫 번째 투구까지 더함
                    }
                } else if (frames[j].first + frames[j].second == 10) {  // 스페어
                    totalScore += frames[j + 1].first;
                }
            }

            // 10프레임에서 보너스 점수 추가
            else 
            {
                if (frames[j].first == 10) 
                {
                    totalScore += frames[j].second + frames[j].bonus;
                } 
                else if (frames[j].first + frames[j].second == 10) 
                {
                    totalScore += frames[j].bonus;
                }
            }

            frames[j].totalScore = totalScore;  // 현재 프레임까지의 총점 저장
        }

        // 4. 현재 점수 출력
        printf("Current score after frame %d: %d\n", i + 1, frames[i].totalScore);
    }

    // 5. 최종 점수 출력
    printf("Total score: %d\n", frames[9].totalScore);
}

int main() {

    // 사용자명과 월 입력 받기
    printf("사용자명을 입력하세요: ");
    scanf("%s", userName);
    
    time_t t =t;
    time(&t);
    struct  tm *localtime = localtime(&t);
   
    printf("현재 날짜 %d-%d"localtime->tm_mon,localtime->tm_mday);
    

    // 월별 사용자 사용 횟수 갱신
    updateUsageCount(userName, month);

    // 메뉴 출력
    do {
        printf("\n===== 선택하세요 =====\n");
        printf("1. 볼링 점수 계산\n");
        printf("2. 월별 사용자 사용 횟수 출력\n");
        printf("3. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // 볼링 점수 계산
                calculateBowlingScores();
                break;
            case 2:
                // 월별 사용자 사용 횟수 출력
                printUsageStats();
                break;
            case 3:
                // 종료
                printf("프로그램을 종료합니다.\n");
                break;
            default:
                printf("잘못된 선택입니다. 다시 선택하세요.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}