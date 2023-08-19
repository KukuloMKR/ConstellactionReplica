// #include <MIDI.h>
// MIDI_CREATE_DEFAULT_INSTANCE(); // Create and bind the MIDI interface to the default hardware Serial port

#include <toneAC.h>

const int led_1_pin = 8;
const int led_2_pin = 12;
const int led_3_pin = 13;

const int sensor_1_pin = A1;
const int sensor_2_pin = A2;
const int sensor_3_pin = A3;

const int speaker_pin = 10;

int led_1_value = 0;
int led_2_value = 0;
int led_3_value = 0;

int sensor_1_value = 0;
int sensor_2_value = 0;
int sensor_3_value = 0;

int sensor_1_value_h = 0;
int sensor_2_value_h = 0;
int sensor_3_value_h = 0;

int variation_1 = 0;
int variation_2 = 0;
int variation_3 = 0;

int variation_reference = 20;

String condition_verified;


void setup() {

  Serial.begin(9600);

  pinMode(sensor_1_pin, INPUT);
  pinMode(sensor_2_pin, INPUT);
  pinMode(sensor_3_pin, INPUT);

  pinMode(led_1_pin, OUTPUT);
  pinMode(led_2_pin, OUTPUT);
  pinMode(led_3_pin, OUTPUT);

  pinMode(speaker_pin, OUTPUT);

  reset_variables();

  // MIDI.begin(MIDI_CHANNEL_OMNI);  // Listen to all incoming messages

  toneAC(2600,10,100);  delay(50);

  toneAC(3000,10,100);  delay(40);

  toneAC(3100,10,100);  delay(30);
  toneAC(3300,10,50);  delay(40);
  toneAC(3500,10,50);  delay(60);

  toneAC(3200,9,90);  delay(30);
  toneAC(3400,9,40);  delay(40);
  toneAC(3600,9,40);  delay(60);

  toneAC(3300,8,80);  delay(30);
  toneAC(3500,8,30);  delay(40);
  toneAC(3700,8,30);  delay(60);

  toneAC(3400,7,100);  delay(30);
  toneAC(3600,7,50);  delay(40);
  toneAC(3800,7,50);  delay(60);

  toneAC(3400,5,50);  delay(30);
  toneAC(3600,5,25);  delay(40);
  toneAC(3800,5,25);  delay(60);
  toneAC(0);

  // for (unsigned long freq = 2000; freq <= 6000; freq += 50) {  
  //   toneAC(freq,10,90); // Play the frequency (150 Hz to 15 kHz in 10 Hz steps).
  //   Serial.print("Frequency: ");Serial.println(freq);
  //   delay(50);     // Wait 1 ms so you can hear it.
  // }
  toneAC(0); // Turn off toneAC, can also use noToneAC(). 
    
  // tone(speaker_pin, 2637, 90);
  // delay(30);
  // delay(1000);
  // tone(speaker_pin, 2959, 90);
  // delay(40);
  // delay(80);
  // tone(speaker_pin, 2959, 90);
  // delay(30);
  // tone(speaker_pin, 3135, 30);
  // delay(10);
  // delay(30);
  // tone(speaker_pin, 3135, 150);
  // delay(60);



}

void loop() {
  
  sensor_1_value = analogRead(sensor_1_pin);
  sensor_2_value = analogRead(sensor_2_pin);
  sensor_3_value = analogRead(sensor_3_pin);

  variation_1 = (sensor_1_value - sensor_1_value_h);
  variation_2 = (sensor_2_value - sensor_2_value_h);
  variation_3 = (sensor_3_value - sensor_3_value_h);

  if (variation_1 > variation_reference or variation_2 > variation_reference or variation_3 > variation_reference) {

    start_light_and_sound();

  }

  // Serial.print("Raw sensor values ->");
  // Serial.print("\t 1: " ); Serial.print(sensor_1_value); Serial.print(" vs "); Serial.print(sensor_1_value_h);
  // Serial.print("\t 2: " ); Serial.print(sensor_2_value); Serial.print(" vs "); Serial.print(sensor_2_value_h);
  // Serial.print("\t 3: " ); Serial.print(sensor_3_value); Serial.print(" vs "); Serial.print(sensor_3_value_h);
  // Serial.println();

  delay(100);

  sensor_1_value_h = sensor_1_value;
  sensor_2_value_h = sensor_2_value;
  sensor_3_value_h = sensor_3_value;

}



void start_light_and_sound() {
	
    digitalWrite(led_1_pin, HIGH);
    digitalWrite(led_2_pin, HIGH);
    digitalWrite(led_3_pin, HIGH);

    // condition_verified = "********************************************************************************";
    // Serial.println(condition_verified);

    // Insert here code for tone sound
    digitalWrite(speaker_pin, HIGH);
    // MIDI.sendNoteOn(42, 127, 1); // Send note 42 with velocity 127 on channel 1
    // MIDI.read(); // Read incoming messages
    //play_midi();
    digitalWrite(speaker_pin, LOW);

    delay(2000);

    reset_variables();
	
}



void reset_variables() {

    digitalWrite(led_1_pin, LOW);
    digitalWrite(led_2_pin, LOW);
    digitalWrite(led_3_pin, LOW);

    variation_1 = 0;
    variation_2 = 0;
    variation_3 = 0;

    digitalWrite(speaker_pin, LOW);
    noToneAC();

    // condition_verified = "";

}



void play_midi() {

    tone(speaker_pin, 2637, 26.1627906977);
    delay(29.0697674419);
    delay(1036.82170543);
    tone(speaker_pin, 2959, 34.8837209302);
    delay(38.7596899225);
    delay(77.519379845);
    tone(speaker_pin, 2959, 26.1627906977);
    delay(29.0697674419);
    tone(speaker_pin, 3135, 8.72093023256);
    delay(9.68992248062);
    delay(29.0697674419);
    tone(speaker_pin, 3135, 52.3255813953);
    delay(58.1395348837);

    noToneAC();

}