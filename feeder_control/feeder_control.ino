// Declaration stage
const int pulsePerRev = 1300;
const float gearRatio = 2;
int motorDelay = 2000;

void updateEncode();
void stepMotor();

int state = 0;
int pos = 0;

int prevEncode[] = {0, 0};
int currEncode[] = {0, 0};

int canLocation;
int pulseMove;
int i;

int canDistance;

const int hallPin[] = {11, 12, 3};
const int enbPin = 7;
const int dirPin = 6;
const int pulPin = 5;
const int devButPin = 3;

bool homeDir = HIGH;
bool usedCans[] = {0, 0, 0, 0};

int numSlots = 5;
int numCans = numSlots - 1;

// Setup stage
void setup() {
    Serial.begin(9600);

    pinMode(enbPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
    pinMode(pulPin, OUTPUT);

    pinMode(hallPin[0], INPUT);
    pinMode(hallPin[1], INPUT);
    pinMode(hallPin[2], INPUT);
    pinMode(devButPin, INPUT_PULLUP);

    while (digitalRead(devButPin) == HIGH) {}
    digitalWrite(dirPin, HIGH);

    while (digitalRead(hallPin[2]) != LOW) {
        stepMotor();
    }
    updateEncode();
}

// Stepper motor control
void stepMotor() {
    digitalWrite(pulPin, HIGH);
    delayMicroseconds(motorDelay);
    digitalWrite(pulPin, LOW);
    delayMicroseconds(motorDelay);
}

// Loop and state machine
void loop() {
    switch (state) {
        case 0:
            Serial.print("\nWaitHome");

            while (digitalRead(devButPin) != HIGH) {}
            state = 1; // movefeed
            break;

        case 1: // movefeed
            Serial.print("\nMoveFeed");

            canLocation = 0;
            for (i = 0; i < numCans; i++) {
                if (usedCans[i] == 0) {
                    canLocation = i + 1;
                    usedCans[i] = 1;
                    break;
                }
            }

            if (usedCans[numCans - 1] == 1) {
                for (i = 0; i < numCans; i++) {
                    usedCans[i] = 0;
                }
            }

            if (canLocation > (numCans / 2)) {
                digitalWrite(dirPin, LOW);
                homeDir = HIGH;
                canDistance = canLocation - (numCans / 2);
            } else {
                digitalWrite(dirPin, HIGH);
                homeDir = LOW;
                canDistance = canLocation;
            }

            pulseMove = canDistance * ((pulsePerRev * gearRatio) / numSlots);
            Serial.println(pulseMove);
            for (i = 0; i < pulseMove; i++) {
                stepMotor();
            }
            break;
    }
}

void updateEncode() {
    // Placeholder for encoder update logic
}