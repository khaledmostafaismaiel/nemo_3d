#include <Servo.h>
#include <stdio.h>
#include <stdlib.h>

#define RGHT_ARM_SERVO_PIN 3   // Connect RGHT_ARM_SERVO_PIN pin to 1
#define LEFT_ARM_SERVO_PIN 5   // Connect LEFT_ARM_SERVO_PIN pin to 2
#define RGHT_LEG_SERVO_PIN 6   // Connect RGHT_LEG_SERVO_PIN pin to 3
#define LEFT_LEG_SERVO_PIN 9   // Connect LEFT_LEG_SERVO_PIN pin to 4
#define RGHT_FOOT_SERVO_PIN 10 // Connect RGHT_FOOT_SERVO_PIN pin to 5
#define LEFT_FOOT_SERVO_PIN 11 // Connect LEFT_FOOT_SERVO_PIN pin to 6
#define BUZZER_PIN 7           // Connect BUZZER_PIN pin to 7
#define LED_PIN 8              // Connect LED_PIN pin to 8
#define ECHO_PIN 12            // Connect ECHO_PIN pin to 12
#define TRIG_PIN 13            // Connect TRIG_PIN pin to 13

#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978

//Mario main theme melody
int melody[] = {
    NOTE_E7, NOTE_E7, 0, NOTE_E7,
    0, NOTE_C7, NOTE_E7, 0,
    NOTE_G7, 0, 0, 0,
    NOTE_G6, 0, 0, 0,

    NOTE_C7, 0, 0, NOTE_G6,
    0, 0, NOTE_E6, 0,
    0, NOTE_A6, 0, NOTE_B6,
    0, NOTE_AS6, NOTE_A6, 0,

    NOTE_G6, NOTE_E7, NOTE_G7,
    NOTE_A7, 0, NOTE_F7, NOTE_G7,
    0, NOTE_E7, 0, NOTE_C7,
    NOTE_D7, NOTE_B6, 0, 0,

    NOTE_C7, 0, 0, NOTE_G6,
    0, 0, NOTE_E6, 0,
    0, NOTE_A6, 0, NOTE_B6,
    0, NOTE_AS6, NOTE_A6, 0,

    NOTE_G6, NOTE_E7, NOTE_G7,
    NOTE_A7, 0, NOTE_F7, NOTE_G7,
    0, NOTE_E7, 0, NOTE_C7,
    NOTE_D7, NOTE_B6, 0, 0};
//Mario main them tempo
int tempo[] = {
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,

    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,

    9,
    9,
    9,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,

    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    9,
    9,
    9,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
    12,
};
//Underworld melody
int underworld_melody[] = {
    NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
    NOTE_AS3, NOTE_AS4, 0,
    0,
    NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
    NOTE_AS3, NOTE_AS4, 0,
    0,
    NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
    NOTE_DS3, NOTE_DS4, 0,
    0,
    NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
    NOTE_DS3, NOTE_DS4, 0,
    0, NOTE_DS4, NOTE_CS4, NOTE_D4,
    NOTE_CS4, NOTE_DS4,
    NOTE_DS4, NOTE_GS3,
    NOTE_G3, NOTE_CS4,
    NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
    NOTE_GS4, NOTE_DS4, NOTE_B3,
    NOTE_AS3, NOTE_A3, NOTE_GS3,
    0, 0, 0};
//Underwolrd tempo
int underworld_tempo[] = {
    12, 12, 12, 12,
    12, 12, 6,
    3,
    12, 12, 12, 12,
    12, 12, 6,
    3,
    12, 12, 12, 12,
    12, 12, 6,
    3,
    12, 12, 12, 12,
    12, 12, 6,
    6, 18, 18, 18,
    6, 6,
    6, 6,
    6, 6,
    18, 18, 18, 18, 18, 18,
    10, 10, 10,
    10, 10, 10,
    3, 3, 3};

int song = 0;
int status = 0;
int action = 0;

Servo right_arm;  //  create the right_arm object
Servo left_arm;   //  create the left_arm object
Servo right_leg;  //  create the right_leg object
Servo left_leg;   //  create the left_leg object
Servo right_foot; //  create the right_foot object
Servo left_foot;  //  create the left_foot object

void setup()
{
  Serial.begin(9600);
  //Define the outputs and inputs
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  right_arm.attach(RGHT_ARM_SERVO_PIN);   // attach right_arm to RGHT_ARM_SERVO_PIN
  left_arm.attach(LEFT_ARM_SERVO_PIN);    // attach left_arm to LEFT_ARM_SERVO_PIN
  right_leg.attach(RGHT_LEG_SERVO_PIN);   // attach right_leg to RGHT_LEG_SERVO_PIN
  left_leg.attach(LEFT_LEG_SERVO_PIN);    // attach left_leg to LEFT_LEG_SERVO_PIN
  right_foot.attach(RGHT_FOOT_SERVO_PIN); // attach right_foot to RGHT_FOOT_SERVO_PIN
  left_foot.attach(LEFT_FOOT_SERVO_PIN);  // attach left_foot to LEFT_FOOT_SERVO_PIN

  delay(1000); // wait a moment to allow the movement into position
}

void stop(void);                                       // stop decleration
void buzz(int targetPin, long frequency, long length); // buzz decleration
void sing(int s);                                      // sing decleration
void move_forward(void);                               // move_forward decleration
void ballet_stand();                                   // ballet_stand decleration
void left_foot_down(int min, int max, int time);       // left_foot_down decleration
void left_foot_up(int min, int max, int time);         // left_foot_up decleration
void right_foot_down(int min, int max, int time);      // right_foot_down decleration
void right_foot_up(int min, int max, int time);        // right_foot_up decleration
void left_leg_out(int min, int max, int time);         // left_leg_out decleration
void left_leg_in(int min, int max, int time);          // left_leg_in decleration
void right_leg_out(int min, int max, int time);        // right_leg_out decleration
void rightt_leg_in(int min, int max, int time);        // rightt_leg_in decleration
void left_arm_down(int min, int max, int time);        // left_arm_down decleration
void left_arm_up(int min, int max, int time);          // left_arm_up decleration
void right_arm_down(int min, int max, int time);       // right_arm_down decleration
void right_arm_up(int min, int max, int time);         // right_arm_up decleration
int ultra_scan(void);                                  // ultra_scan decleration
void wave();                                           // wave decleration
void flash(void);                                      // flash decleration

void loop()
{

  if (status == 0)
  {

    stop();

    status = 1;
  }
  if (ultra_scan() <= 10)
  {
    digitalWrite(LED_PIN, LOW);

    action = rand() % 5;

    switch (action)
    {
    case 0:
      sing(1);
      break;

    case 1:
      sing(2);
      break;

    case 2:
      ballet_stand();
      break;

    case 3:
      wave();
      break;

    default:
      flash();

      break;
    }
  }
  else
  {
    digitalWrite(LED_PIN, HIGH);
    move_forward();
  }

  delay(100); // waits 100ms
}

int ultra_scan(void)
{
  int duration; // to calculate the time taken
  int distance; // to measure the distance

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration * 0.034 / 2);

  return distance;
}

void right_arm_up(int start, int end, int time)
{

  for (int pos = start; pos <= end; pos += 1)
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    right_arm.write(pos - 20); // tell servo to go to position in variable 'pos'

    delay(time); // waits 15ms for the servo to reach the position
  }
}

void right_arm_down(int start, int end, int time)
{
  for (int pos = start; pos >= end; pos -= 1)
  {                            // goes from 180 degrees to 0 degrees
    right_arm.write(pos - 20); // tell servo to go to position in variable 'pos'

    delay(time); // waits 15ms for the servo to reach the position
  }
}

void left_arm_up(int start, int end, int time)
{
  for (int pos = start; pos <= end; pos += 1)
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    left_arm.write(pos - 10); // tell servo to go to position in variable 'pos'

    delay(time); // waits 15ms for the servo to reach the position
  }
}

void left_arm_down(int start, int end, int time)
{

  for (int pos = start; pos >= end; pos -= 1)
  {                           // goes from 180 degrees to 0 degrees
    left_arm.write(pos - 10); // tell servo to go to position in variable 'pos'

    delay(time); // waits 15ms for the servo to reach the position
  }
}

void right_leg_in(int start, int end, int time)
{

  for (int pos = start; pos >= end; pos -= 1)
  {                            // goes from 180 degrees to 0 degrees
    right_leg.write(pos - 10); // tell servo to go to position in variable 'pos'

    delay(time); // waits 15ms for the servo to reach the position
  }
}

void right_leg_out(int start, int end, int time)
{
  for (int pos = start; pos <= end; pos += 1)
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    right_leg.write(pos - 10); // tell servo to go to position in variable 'pos'

    delay(time); // waits 15ms for the servo to reach the position
  }
}

void left_leg_out(int start, int end, int time)
{

  for (int pos = start; pos >= end; pos -= 1)
  {                           // goes from 180 degrees to 0 degrees
    left_leg.write(pos - 10); // tell servo to go to position in variable 'pos'

    delay(time); // waits 15ms for the servo to reach the position
  }
}

void left_leg_in(int start, int end, int time)
{
  for (int pos = start; pos <= end; pos += 1)
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    left_leg.write(pos - 10); // tell servo to go to position in variable 'pos'

    delay(time); // waits 15ms for the servo to reach the position
  }
}

/* right_foot  */

void right_foot_up(int start, int end, int time)
{

  for (int pos = start; pos <= end; pos += 1)
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    right_foot.write(pos); // tell servo to go to position in variable 'pos'

    delay(time); // waits 15ms for the servo to reach the position
  }
}

void right_foot_down(int start, int end, int time)
{
  for (int pos = start; pos >= end; --pos)
  {                        // goes from 180 degrees to 0 degrees
    right_foot.write(pos); // tell servo to go to position in variable 'pos'

    delay(time); // waits 15ms for the servo to reach the position
  }
}

/* left_foot  */

void left_foot_up(int start, int end, int time)
{

  for (int pos = start; pos >= end; --pos)
  {                       // goes from 180 degrees to 0 degrees
    left_foot.write(pos); // tell servo to go to position in variable 'pos'

    delay(time); // waits 15ms for the servo to reach the position
  }
}

void left_foot_down(int start, int end, int time)
{

  for (int pos = start; pos <= end; ++pos)
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    left_foot.write(pos); // tell servo to go to position in variable 'pos'

    delay(time); // waits 15ms for the servo to reach the position
  }
}

void ballet_stand(void)
{
  right_arm.write(150); // tell servo to go to 150
  left_arm.write(150);  // tell servo to go to 150
  right_leg.write(80);  // tell servo to go to 80
  left_leg.write(60);   // tell servo to go to 60
  right_foot.write(75); // tell servo to go to 75
  left_foot.write(65);  // tell servo to go to 65

  for (int pos = 65; pos <= 150; ++pos)
  {
    left_foot.write(pos); // tell servo to go to i

    delay(30);
  }
  delay(3000);
  for (int pos = 150; pos >= 65; --pos)
  {
    left_foot.write(pos); // tell servo to go to i

    delay(30);
  }
  stop();
}

void move_forward(void)
{
  right_arm.write(160); // tell servo to go to 50
  left_arm.write(0);    // tell servo to go to 180
  right_leg.write(80);  // tell servo to go to 80
  left_leg.write(80);   // tell servo to go to 60
  right_foot.write(80); // tell servo to go to 70
  left_foot.write(55);  // tell servo to go to 65

  right_foot_down(80, 40, 5);
  right_leg_out(80, 130, 5);

  right_foot_up(40, 80, 5);

  left_foot_down(55, 80, 5);
  left_leg_out(80, 30, 5);

  left_foot_up(80, 55, 5);

  right_leg_in(130, 80, 5);
  left_leg_in(30, 80, 5);

  right_arm.write(160); // tell servo to go to 50
  left_arm.write(0);    // tell servo to go to 180
  right_leg.write(80);  // tell servo to go to 80
  left_leg.write(80);   // tell servo to go to 60
  right_foot.write(80); // tell servo to go to 70
  left_foot.write(55);  // tell servo to go to 65
}

void sing(int s)
{
  // iterate over the notes of the melody:
  song = s;
  if (song == 2)
  {
    Serial.println(" 'Underworld Theme'");
    int size = sizeof(underworld_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++)
    {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / underworld_tempo[thisNote];

      buzz(BUZZER_PIN, underworld_melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(BUZZER_PIN, 0, noteDuration);
    }
  }
  else
  {

    Serial.println(" 'Mario Theme'");
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++)
    {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / tempo[thisNote];

      buzz(BUZZER_PIN, melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(BUZZER_PIN, 0, noteDuration);
    }
  }
}

void buzz(int targetPin, long frequency, long length)
{
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++)
  {                                // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW);  // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
}

void stop(void)
{

  right_arm.write(50);  // tell servo to go to 50
  left_arm.write(0);    // tell servo to go to 180
  right_leg.write(80);  // tell servo to go to 80
  left_leg.write(60);   // tell servo to go to 60
  right_foot.write(75); // tell servo to go to 75
  left_foot.write(65);  // tell servo to go to 65
}

void wave(void)
{
  stop();

  for (int i = 0; i < 2; ++i)
  {
    left_arm_down(180, 150, 30);
    left_arm_up(150, 180, 30);

    right_arm_down(50, 120, 30);

    right_foot_down(75, 0, 30);
    right_foot_up(0, 75, 30);

    left_foot_down(65, 120, 30);
    left_foot_up(120, 65, 30);
  }

  stop();
}

void flash(void)
{
  for (int i = 0; i < 10; ++i)
  {
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    delay(500);
  }
}
