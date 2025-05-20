#define trigPin 9
#define echoPin 10

int leftIR = A0;
int midIR = A1;
int rightIR = A2;

int leftMotor = 5;
int rightMotor = 6;

bool isParking = false;

void setup() {
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
  pinMode(leftIR, INPUT);
  pinMode(midIR, INPUT);
  pinMode(rightIR, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int L = digitalRead(leftIR);
  int M = digitalRead(midIR);
  int R = digitalRead(rightIR);

  if (!isParking) {
    // 라인 따라 이동
    if (M == LOW && L == HIGH && R == HIGH) forward();
    else if (L == LOW) turnLeft();
    else if (R == LOW) turnRight();
    else if (L == LOW && M == LOW && R == LOW) {
      // T자형 주차라인 인식
      stopCar();
      delay(1000);
      isParking = true;
    }
  } else {
    // 후진 주차 실행
    backward();  // 일정 시간 후진

    // 초음파 거리 측정으로 뒤에 벽 있으면 정지
    int dist = readDistance();
    if (dist < 10) {
      stopCar();
      Serial.println("주차 완료!");
      delay(5000); // 주차 상태 유지
      forward();   // 출차 시작
      isParking = false;
    }
  }
}

void forward() {
  analogWrite(leftMotor, 150);
  analogWrite(rightMotor, 150);
}

void backward() {
  analogWrite(leftMotor, -150);  // 일부 모터 드라이버는 방향핀 필요
  analogWrite(rightMotor, -150);
}

void turnLeft() {
  analogWrite(leftMotor, 0);
  analogWrite(rightMotor, 150);
}

void turnRight() {
  analogWrite(leftMotor, 150);
  analogWrite(rightMotor, 0);
}

void stopCar() {
  analogWrite(leftMotor, 0);
  analogWrite(rightMotor, 0);
}

int readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}
