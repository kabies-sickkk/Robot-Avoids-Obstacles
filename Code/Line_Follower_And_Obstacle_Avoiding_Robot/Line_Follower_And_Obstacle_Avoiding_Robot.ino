//     Dò line và tránh vật cản


distance_F = Ultrasonic_read();
Serial.print("D F=");Serial.println(distance_F);




// nếu Cảm biến bên phải và Cảm biến bên trái đều truyền tính hiệu = 0, thì hàm sẽ gọi chức năng cho robot đi tiếp
 if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)){
  if(distance_F > Set){forword();}
                  else{Check_side();}  
 }  
 
//nếu Cảm biến bên phải trả về 1 và Cảm biến bên trái trả về 0 thì nó sẽ gọi chức năng cho robot rẽ phải
else if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)){turnRight();}  


//nếu Cảm biến bên phải trả về 0 và Cảm biến bên trái trả về 1 thì nó sẽ gọi chức năng cho robot rẽ trái
else if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)){turnLeft();}
   
delay(10);
}


void servoPulse (int pin, int angle){
int pwm = (angle*11) + 500;      // điều chỉnh góc quay thành micro giây
 digitalWrite(pin, HIGH);
 delayMicroseconds(pwm);
 digitalWrite(pin, LOW);
 delay(50); // chu kỳ làm mới của servo
}


