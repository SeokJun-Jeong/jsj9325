#include <Arduino.h>

// IR 센서 핀 정의
#define IR_LEFT D5
#define IR_RIGHT D6

// 초음파 센서 핀 정의
#define TRIG_PIN D7
#define ECHO_PIN D1

// 모터 제어 핀 정의
#define IN1 D2
#define IN2 D3
#define IN3 D8
#define IN4 3  // RX 핀 (GPIO3)

// 거리 측정 함수 (C 스타일 함수 정의)
long readDistanceCM()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}

// 모터 제어 함수들 (C 스타일)
void forward()
{
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void stopMotors()
{
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}

void turnLeft()
{
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void turnRight()
{
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}

// 아두이노 진입점: setup(), loop()
void setup()
{
  Serial.begin(9600);

  pinMode(IR_LEFT, INPUT);
  pinMode(IR_RIGHT, INPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop()
{
  int leftIR = digitalRead(IR_LEFT);
  int rightIR = digitalRead(IR_RIGHT);
  long distance = readDistanceCM();

  if (distance < 10)
  {
    stopMotors();
    Serial.println("장애물 감지: 정지");
    return;
  }

  if (leftIR == HIGH && rightIR == HIGH)
  {
    forward();
    Serial.println("전진");
  }
  else if (leftIR == LOW && rightIR == HIGH)
  {
    turnLeft();
    Serial.println("좌회전");
  }
  else if (leftIR == HIGH && rightIR == LOW)
  {
    turnRight();
    Serial.println("우회전");
  }
  else
  {
    stopMotors();
    Serial.println("정지 or 선 벗어남");
  }

  delay(100);
}
