

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <json-c/json.h>

#define API_URL "http://apis.data.go.kr/1360000/VilageFcstInfoService_2.0/getVilageFcst"
#define SERVICE_KEY "ca9r8VuUVqipZgh0faFDUCDqEJ9aE0Die5Pukgv9HhJgCNzmre3V7cgTmubPrg1TZXhAO5Ue%2Fu13xqtFRDMIxw%3D%3D" // 기상청에서 발급받은 API 키

// 데이터를 받아서 처리하는 콜백 함수
size_t write_callback(void *ptr, size_t size, size_t nmemb, char *data) {
    strcat(data, ptr);
    return size * nmemb;
}

int main() {
    CURL *curl;
    CURLcode res;
    char url[1024];
    char response[10000] = "";

    // 기상청 API 요청 URL을 작성
    snprintf(url, sizeof(url),
             "%s?serviceKey=%s&numOfRows=10&pageNo=1&base_date=20250325&base_time=0600&nx=60&ny=127", 
             API_URL, SERVICE_KEY);

    // curl 초기화
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        // 요청 URL 설정
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);

        // 요청 실행
        res = curl_easy_perform(curl);

        // 요청이 성공했는지 확인
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // 응답을 출력
            printf("Response: \n%s\n", response);

            // JSON 응답 파싱
            struct json_object *parsed_json;
            struct json_object *response_body;
            struct json_object *item;
            
            parsed_json = json_tokener_parse(response);
            json_object_object_get_ex(parsed_json, "response", &response_body);
            json_object_object_get_ex(response_body, "body", &item);
            
            // 예시로, JSON 응답에서 필요한 데이터 출력 (필요한 데이터에 맞게 수정 가능)
            printf("First item: %s\n", json_object_to_json_string(item));
        }

        // curl 종료
        curl_easy_cleanup(curl);
    }

    // curl 전역 종료
    curl_global_cleanup();

    return 0;
}


