#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int left_sensor = 4;
const int right_sensor = 5;
const int front_sensor = 6;
const int led_red = 7;
const int led_green = 8;
unsigned long start_time;
unsigned long speed_reaction_time;
unsigned long output_time;

int count = 0;
int start = 1;

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  pinMode(left_sensor, INPUT_PULLUP);
  pinMode(right_sensor, INPUT_PULLUP);
  pinMode(front_sensor, INPUT_PULLUP);
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  digitalWrite(led_green, LOW);
  digitalWrite(led_red, LOW);
  lcd.setCursor(0, 0);
  lcd.print(" Ready to start  ");
  lcd.setCursor(0, 1);
  lcd.print("       3");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Ready to start  ");
  lcd.setCursor(0, 1);
  lcd.print("       2");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Ready to start  ");
  lcd.setCursor(0, 1);
  lcd.print("       1");
  delay(1000);
  lcd.clear();
  lcd.print("     Start");
}

void loop() {
  int output_sensor_left = digitalRead(left_sensor);
  int output_sensor_right = digitalRead(right_sensor);
  int output_sensor_front = digitalRead(front_sensor);
  if(start == 1){
      digitalWrite(led_green, HIGH);
      start_time = millis();
  }
  while(output_sensor_left == 1 && output_sensor_right == 1 && output_sensor_front == 1 && start == 1){
      output_sensor_left = digitalRead(left_sensor);
      output_sensor_right = digitalRead(right_sensor);
      output_sensor_front = digitalRead(front_sensor);
  }
  if(output_sensor_left == 0 || output_sensor_right == 0 || output_sensor_front == 0  && start == 1){
      start = 0;
      speed_reaction_time = millis() - start_time;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("   Speed time  ");
      lcd.setCursor(0,1);
      lcd.print(speed_reaction_time);
      lcd.print(" milliseconds"); 
      digitalWrite(led_green, LOW);
      digitalWrite(led_red, HIGH);
      delay(100);
      stop();
  }
}

void stop() {
  //stop
  while(true){
    
  }
}
