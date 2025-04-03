const int irpin1 = 5; // Chân cắm cho cảm biến hồng ngoại 1
const int irpin2 = 6; // Chân cắm cho cảm biến hồng ngoại 2
const int led1 = 2;   // Chân cắm cho đèn LED 1
const int led2 = 3;   // Chân cắm cho đèn LED 2


void setup() {
  pinMode(irpin1, INPUT);
  pinMode(irpin2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600); // Khởi tạo giao tiếp Serial
}


void loop() {
  // Đọc giá trị từ cảm biến hồng ngoại 1
  int irValue1 = digitalRead(irpin1);
  // Đọc giá trị từ cảm biến hồng ngoại 2
  int irValue2 = digitalRead(irpin2);


  // Kiểm tra tính hiệu từ cảm biến và điều khiển đèn LED tương ứng
  if (irValue1 == 0 && irValue2 == 0) {
    digitalWrite(led1, 1); // Bật đèn LED 1
    digitalWrite(led2, 1);  // Tắt đèn LED 2
    Serial.println("di thang"); // Ghi lên Serial "re phai"
    Serial.print("digital chan phai :");
    Serial.println(irValue1);
    Serial.print("digital chan trai :");
    Serial.println(irValue2);
  } else if (irValue1 == 1 && irValue2 == 1) {
    digitalWrite(led1, 0);  // Tắt đèn LED 1
    digitalWrite(led2, 0); // Bật đèn LED 2
    Serial.println("dung lai"); // Ghi lên Serial "re trai"
    Serial.print("digital chan phai :");
    Serial.println(irValue1);
    Serial.print("digital chan trai :");
    Serial.println(irValue2);
  } else if (irValue1 == 0 && irValue2 == 1) {
    digitalWrite(led1, 1); // Bật đèn LED 1
    digitalWrite(led2, 0); // Bật đèn LED 2
    Serial.println("re phai"); // Ghi lên Serial "di thang"
    Serial.print("digital chan phai :");
    Serial.println(irValue1);
    Serial.print("digital chan trai :");
    Serial.println(irValue2);
  } else {
    digitalWrite(led1, 0);  // Tắt đèn LED 1
    digitalWrite(led2, 1);
    Serial.println("re trai"); // Tắt đèn LED 2
    Serial.print("digital chan phai :");
    Serial.println(irValue1);
    Serial.print("digital chan trai :");
    Serial.println(irValue2);
  }delay(500);
}




