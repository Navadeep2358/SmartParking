#include <Servo.h>
#include <LiquidCrystal_I2C.h>

Servo tap_servo1;
Servo tap_servo2;
LiquidCrystal_I2C lcd(0x27, 16, 2);  

int sensor_pin1 = 4;
int sensor_pin2 = 3;
int tap_servo_pin1 = 5;
int tap_servo_pin2 = 6;
int buzzer_pin = 9;   
int red_led_pin = 10; 
int yellow_led_pin = 11; 

const int max_total_slots = 9; 

int total_slots = max_total_slots; 
int free_slots = max_total_slots;  

void setup() {
  Serial.begin(9600);  
  pinMode(sensor_pin1, INPUT);
  pinMode(sensor_pin2, INPUT);

  tap_servo1.attach(tap_servo_pin1);
  tap_servo2.attach(tap_servo_pin2);
  
  pinMode(buzzer_pin, OUTPUT);   
  pinMode(red_led_pin, OUTPUT); 
  pinMode(yellow_led_pin, OUTPUT); 

  lcd.begin(16, 2);  

  updateLCD(total_slots, free_slots);

  updateFreeSlots(0); 
}

void loop() {
 
  int val1 = digitalRead(sensor_pin1);

  if (val1 == 0) {
    tap_servo1.write(0);
    delay(3000);
    
    Serial.println("Sensor 1 triggered!");
    updateFreeSlots(-1);

    digitalWrite(red_led_pin, HIGH);
    digitalWrite(buzzer_pin, HIGH);
    delay(500);
    digitalWrite(red_led_pin, LOW);
    digitalWrite(buzzer_pin, LOW);
  }
  if (val1 == 1) {
    tap_servo1.write(90);
  }

  
  int val2 = digitalRead(sensor_pin2);

  if (val2 == 0) {
    tap_servo2.write(0);
    delay(3000);
    
    Serial.println("Sensor 2 triggered!");
    updateFreeSlots(1);
   
    digitalWrite(yellow_led_pin, HIGH);
    digitalWrite(buzzer_pin, HIGH);
    delay(500);
    digitalWrite(yellow_led_pin, LOW);
    digitalWrite(buzzer_pin, LOW);
  }
  if (val2 == 1) {
    tap_servo2.write(90);
  }

  
  if (free_slots == 0) {
    
    digitalWrite(buzzer_pin, HIGH);
    delay(3000);
    digitalWrite(buzzer_pin, LOW);
    
   
    for (int i = 0; i < 6; i++) {
      digitalWrite(red_led_pin, HIGH);
      digitalWrite(yellow_led_pin, LOW);
      delay(100);
      digitalWrite(red_led_pin, LOW);
      digitalWrite(yellow_led_pin, HIGH);
      delay(100);
    }
  }
}

void updateFreeSlots(int change) {
  free_slots += change;
  if (free_slots < 0) {
    free_slots = 0; 
  }
  if (free_slots > max_total_slots) {
    free_slots = max_total_slots; 
  }

 
  updateLCD(max_total_slots, free_slots);
}

void updateLCD(int total_slots, int free_slots) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Total: " + String(total_slots));
  lcd.setCursor(0, 1);
  if (free_slots == 0) {
    lcd.print("Parking is full");
  } else {
    lcd.print("Free: " + String(free_slots));
  }
}