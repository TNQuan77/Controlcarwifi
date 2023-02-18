
#define inA1 12 // Khai báo 2 chân điều khiển chạy tới, chạy lui cho động cơ 1
#define inA2 10
#define inB1 13 // Khai báo 2 chân điều khiển chạy tới, chạy lui cho đông cơ 2
#define inB2 11
#define Buzzer 4 // Khai báo tin hiệu buzzer


char data;

void setup()
{

  Serial.begin(9600);    // Tốc độ truyền nhận từ board bluetooth với ARDUINO
  pinMode(inA1, OUTPUT); // Định nghĩa các chân inA1 và inA2 là chân xuất ra tín hiệu
  pinMode(inA2, OUTPUT);
  pinMode(inB1, OUTPUT); // Định nghĩa các chân inB1 và inB2 là chân xuất ra tín hiệu
  pinMode(inB2, OUTPUT);
  pinMode(Buzzer, OUTPUT);

  // digitalWrite(inA2, HIGH);
  // digitalWrite(inB2, HIGH);
}
void loop() //***** Vào vòng lặp liên tục*******
{
  // //delay(50);

  if (Serial.available() > 0) // Ghi lại dữ liệu từ điện thoại gửi
  {
    data = Serial.read();
    Serial.print(data);
  }

  // delay(1000);
  // Serial.print(data);

  switch (data)
  {
  case 'L': // rẽ trái khi nhận được "L"
    // digitalWrite(Buzzer, HIGH);
    digitalWrite(inA1, LOW);
    digitalWrite(inB1, HIGH);
    digitalWrite(inA2, HIGH);
    digitalWrite(inB2, HIGH);
    // delay(5);
    Serial.print("TURN LEFT\n");
    break;
  // case 'G': // FL
  //   // digitalWrite(Buzzer, HIGH);
  //   digitalWrite(inA1, LOW);
  //   digitalWrite(inB1, LOW);
  //   digitalWrite(inA2, HIGH);
  //   digitalWrite(inB2, HIGH - 100);
  //   // delay(5);
  //   Serial.print("FORWORD LEFT\n");
  //   break;
  // case 'I': // FR
  //   // digitalWrite(Buzzer, HIGH);
  //   digitalWrite(inA1, LOW);
  //   digitalWrite(inB1, LOW);
  //   digitalWrite(inA2, HIGH - 100);
  //   digitalWrite(inB2, HIGH);
  //   // delay(5);
  //   Serial.print("FORWORD RIGHT\n");
  //   break;
  // case 'H': // BL
  //   // digitalWrite(Buzzer, HIGH);
  //   digitalWrite(inA1, HIGH);
  //   digitalWrite(inB1, HIGH);
  //   digitalWrite(inA2, HIGH);
  //   digitalWrite(inB2, HIGH - 100);
  //   // delay(5);
  //   Serial.print("BACK LEFT\n");
  //   break;
  // case 'J': // BR
  //   // digitalWrite(Buzzer, HIGH);
  //   digitalWrite(inA1, HIGH);
  //   digitalWrite(inB1, HIGH);
  //   digitalWrite(inA2, HIGH - 100);
  //   digitalWrite(inB2, HIGH);
  //   // delay(5);
  //   Serial.print("BACK\n");
  //   break;

  case 'R': // rẽ phải khi nhận được "R"
    // digitalWrite(Buzzer, HIGH);
    digitalWrite(inA1, HIGH);
    digitalWrite(inB1, LOW);
    digitalWrite(inA2, HIGH);
    digitalWrite(inB2, HIGH);
    // delay(5);
    Serial.print("TURN RIGHT\n");
    break;
  case 'F': // đi thẳng khi nhận được "F"
            // digitalWrite(Buzzer, HIGH);
    digitalWrite(inA1, LOW);
    digitalWrite(inB1, LOW);
    digitalWrite(inA2, HIGH);
    digitalWrite(inB2, HIGH);
    // delay(5);
    Serial.print("FORWARD\n");
    break;
  case 'B': // đi lùi khi nhận được "B"
    // digitalWrite(Buzzer, HIGH);
    digitalWrite(inA1, HIGH);
    digitalWrite(inB1, HIGH);
    digitalWrite(inA2, HIGH);
    digitalWrite(inB2, HIGH);
    // delay(5);
    Serial.print("BACK\n");
    break;
  case 'E': // dừng lại khi nhận được "S"
    digitalWrite(Buzzer, LOW);
    digitalWrite(inA1, LOW);
    digitalWrite(inB1, LOW);
    digitalWrite(inA2, LOW);
    digitalWrite(inB2, LOW);
    // delay(5);
    Serial.print("STOP\n");
    break;
  case 'V': // bật còi buzzer khi nhận được "V"
    digitalWrite(Buzzer, HIGH);
    // delay(5);
    Serial.print("BUZZER\n");
    break;
  case 'v': // bật còi buzzer khi nhận được "v"
    digitalWrite(Buzzer, LOW);
    // delay(5);
    Serial.print("BUZZER\n");
    break;
  // case '0': // cai dat toc do
  //   HIGH = 0;
  //   Serial.print("\nHIGH: ");
  //   Serial.print(HIGH);
  //   break;
  // case '1':
  //   HIGH = 25;
  //   Serial.print("\nHIGH: ");
  //   Serial.print(HIGH);
  //   break;
  // case '2':
  //   HIGH = 51;
  //   Serial.print("\nHIGH: ");
  //   Serial.print(HIGH);
  //   break;
  // case '3':
  //   HIGH = 76;
  //   Serial.print("\nHIGH: ");
  //   Serial.print(HIGH);
  //   break;
  // case '4':
  //   HIGH = 102;
  //   Serial.print("\nHIGH: ");
  //   Serial.print(HIGH);
  //   break;
  // case '5':
  //   HIGH = 127;
  //   Serial.print("\nHIGH: ");
  //   Serial.print(HIGH);
  //   break;
  // case '6':
  //   HIGH = 153;
  //   Serial.print("\nHIGH: ");
  //   Serial.print(HIGH);
  //   break;
  // case '7':
  //   HIGH = 178;
  //   Serial.print("\nHIGH: ");
  //   Serial.print(HIGH);
  //   break;
  // case '8':
  //   HIGH = 204;
  //   Serial.print("\nHIGH: ");
  //   Serial.print(HIGH);
  //   break;
  // case '9':
  //   HIGH = 229;
  //   Serial.print("\nHIGH: ");
  //   Serial.print(HIGH);
  //   break;
  // case 'q':
  //   HIGH = 255;
  //   Serial.print("\nHIGH: ");
  //   Serial.print(HIGH);
  //   break;
  default: // tắt còi buzzer & stop
    // digitalWrite(Buzzer, LOW);
    data = 'E';
    break;
  }
}
