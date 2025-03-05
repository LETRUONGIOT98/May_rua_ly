#define bom 4
#define uv A3
#define ledbom 13 
#define chay A4
#define dung A5
#define chayuv 9
long time;
bool i = false;
int thoigianchay = 10; // thời gian chạy tính bằng giây
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(bom, OUTPUT);
  pinMode(uv, OUTPUT);
  digitalWrite(bom, LOW);
  digitalWrite(uv, LOW);
  pinMode(ledbom, OUTPUT);
  pinMode(dung, INPUT_PULLUP);
  pinMode(chay, INPUT_PULLUP);
  pinMode(chayuv, INPUT_PULLUP);
}

void loop() {

  /////LỆNH BẮT ĐẦU CHẠY///////////
  if (digitalRead(chay) == 0 && digitalRead(chayuv) == 0) {
    i = true;
    time = millis();
  }
  if (i) {
    if (digitalRead(chayuv) == 0) {
      if (millis() - time < thoigianchay*1000) {
        digitalWrite(bom, HIGH);
        digitalWrite(ledbom, HIGH);
      }
      else {
        digitalWrite(bom, LOW);
        digitalWrite(ledbom, LOW);
        i = false;
      }
    }
    else {
      time = millis();
      digitalWrite(bom, LOW);
      digitalWrite(ledbom, LOW);
    }
  }
  else {
    time = millis();
    digitalWrite(bom, LOW);
    digitalWrite(ledbom, LOW);
  }
  /////////LỆNH DỪNG KHẨN CẤP///////////
  if (digitalRead(dung) == 0) {
    digitalWrite(bom, LOW);
    digitalWrite(ledbom, LOW);
    i = false;
  }
  if(digitalRead(chayuv) == 0){
  digitalWrite(uv, 1);
}
else digitalWrite(uv, 0);
}
