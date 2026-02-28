#include <Arduino.h>

/**
 * @file main.cpp
 * @brief Embedded Obstacle Detection System using IR Sensor
 * @author Vansh Saxena
 * @date 2026-02-28
 *
 * @details
 * This program reads digital input from an IR obstacle sensor.
 * When an obstacle is detected, the sensor outputs LOW.
 * The system displays obstacle status on the Serial Monitor.
 */

// Define IR sensor digital pin (Use pin 2)
#define IR_PIN 2

// Variable to store sensor state
int sensorState;

/**
 * @brief Initializes serial communication and configures IR sensor pin.
 *
 * Serial communication is started at 9600 baud rate.
 * IR sensor pin is configured as INPUT.
 */
void setup() {

    Serial.begin(9600);
    pinMode(IR_PIN, INPUT);

    Serial.println("IR Obstacle Detection System Initialized");
}

/**
 * @brief Continuously reads IR sensor and prints obstacle status.
 *
 * LOW  -> Obstacle detected
 * HIGH -> No obstacle
 */
void loop() {

    // Read digital value from IR sensor
    sensorState = digitalRead(IR_PIN);

    if (sensorState == LOW) {
        Serial.println("Obstacle Detected");
    }
    else {
        Serial.println("No Obstacle");
    }

    // Small delay for stable output
    delay(300);
}