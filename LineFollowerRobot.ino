#define LEFT_SENSOR  33 
#define RIGHT_SENSOR 32  

#define IN1  27  
#define IN2  14  
#define IN3  25  
#define IN4  26  

#define ENA  5   
#define ENB  18  

#define SPEED  100  
#define TURN_SPEED 130  
#define BACKWARD_SPEED 100  

void setup() {
    pinMode(LEFT_SENSOR, INPUT);
    pinMode(RIGHT_SENSOR, INPUT);

    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);

    Serial.begin(115200);
}

void loop() {
    int leftSensor = digitalRead(LEFT_SENSOR);
    int rightSensor = digitalRead(RIGHT_SENSOR);

    Serial.print("Left Sensor: "); Serial.print(leftSensor);
    Serial.print(" | Right Sensor: "); Serial.println(rightSensor);

    if (leftSensor == HIGH && rightSensor == LOW) {
        turnRight();
    }
    else if (leftSensor == LOW && rightSensor == HIGH) {
        turnLeft();
    }
    else if (leftSensor == LOW && rightSensor == LOW) {
        moveForward();
    }
    else if (leftSensor == HIGH && rightSensor == HIGH) {
        moveBackward();
    }
    else {
        stopMotors();
    }

    delay(50);
}

void moveForward() {
    analogWrite(ENA, SPEED);
    analogWrite(ENB, SPEED);
    
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void turnLeft() {
    analogWrite(ENA, TURN_SPEED);
    analogWrite(ENB, TURN_SPEED);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void turnRight() {
    analogWrite(ENA, TURN_SPEED);
    analogWrite(ENB, TURN_SPEED);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void moveBackward() {
    analogWrite(ENA, BACKWARD_SPEED);
    analogWrite(ENB, BACKWARD_SPEED);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void stopMotors() {
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
    
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}
