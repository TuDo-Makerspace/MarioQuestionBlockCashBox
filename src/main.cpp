/*
 * main.cpp
 *
 * Author       : Yunis, Patrick Pedersen
 * Description  : Main code for the coin box
 * 
 */

#include <PCM.h>
#include <Arduino.h>

#include "sounds.h"

//// Parameters

// Pins
// Sound is on pin 11
#define SENSOR_PIN 8

// Number of coins to trigger sound
#define POWER_UP 4
#define ONE_UP 10

// Function
#define WAIT_AFTER_COIN 100 // ms

void print_boot_msg() {
  Serial.println("@@@@/////////////////////////////////////////////////@@@@\n");         
  Serial.println("////,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@@@@\n");
  Serial.println("////,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@@@@\n");
  Serial.println("////,,,@@@@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@@@@,,,@@@@\n");
  Serial.println("////,,,,,,,,,,,,,,/////////////////*,,,,,,,,,,,,,,,,,@@@@\n");
  Serial.println("////,,,,,,,,,,,,,,/////////////////*,,,,,,,,,,,,,,,,,@@@@\n");
  Serial.println("////,,,,,,,,,,///////@@@@@@@@@@@///////,,,,,,,,,,,,,,@@@@\n");
  Serial.println("////,,,,,,,,,,///////@@@@,,,,,,,///////@@@@,,,,,,,,,,@@@@\n");
  Serial.println("////,,,,,,,,,,///////@@@@,,,,,,,///////@@@@,,,,,,,,,,@@@@\n");
  Serial.println("////,,,,,,,,,,///////@@@@,,,,,,,///////@@@@,,,,,,,,,,@@@@\n");
  Serial.println("////,,,,,,,,,,,,,,@@@@@@@,,,///////////@@@@,,,,,,,,,,@@@@\n");
  Serial.println("////,,,,,,,,,,,,,,,,,,,,,///////@@@@@@@@@@@,,,,,,,,,,@@@@\n");
  Serial.println("////,,,,,,,,,,,,,,,,,,,,,///////@@@@@@@@@@@,,,,,,,,,,@@@@\n");
  Serial.println("////,,,,,,,,,,,,,,,,,,,,,///////@@@#,,,,,,,,,,,,,,,,,@@@@\n");
  Serial.println("////,,,,,,,,,,,,,,,,,,,,,,,,@@@@@@@#,,,,,,,,,,,,,,,,,@@@@\n");
  Serial.println("////,,,,,,,,,,,,,,,,,,,,,///////,,,,,,,,,,,,,,,,,,,,,@@@@\n");
  Serial.println("////,,,,,,,,,,,,,,,,,,,,,///////,,,,,,,,,,,,,,,,,,,,,@@@@\n");
  Serial.println("////,,,,,,,,,,,,,,,,,,,,,///////@@@#,,,,,,,,,,,,,,,,,@@@@\n");
  Serial.println("////,,,@@@@,,,,,,,,,,,,,,,,,@@@@@@@#,,,,,,,,,,@@@@,,,@@@@\n");
  Serial.println("////,,,@@@@,,,,,,,,,,,,,,,,,@@@@@@@#,,,,,,,,,,@@@@,,,@@@@\n");
  Serial.println("////,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@@@@\n");
  Serial.println("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
  Serial.println("\n\n");
  Serial.println("Mario Coin box by Yunis! ft. Patrick :) !!!!11!\n");
}

int money = 1;

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  Serial.begin(9600);
  print_boot_msg();
}

void loop() {
  static uint8_t last_val = digitalRead(SENSOR_PIN);
  uint8_t val = digitalRead(SENSOR_PIN);

  if(last_val == LOW && val == HIGH) {

    Serial.print("Coin detected! Playing: ");

    if ((money % POWER_UP) == 0) {
      Serial.println("Power up!");
      startPlayback(powerup, sizeof(powerup));
    }
    else if ((money % ONE_UP) == 0) {
      Serial.println("One up!");
      startPlayback(oneup, sizeof(oneup));
    }
    else {
      Serial.println("Coin sound!");
      startPlayback(coin, sizeof(coin));
    }
    money++;

    delay(WAIT_AFTER_COIN);
  }

  last_val = val;
}
