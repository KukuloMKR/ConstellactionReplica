const int led_1_pin = 8;
const int led_2_pin = 12;
const int led_3_pin = 13;

const int sensor_1_pin = A1;
const int sensor_2_pin = A2;
const int sensor_3_pin = A3;

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

  reset_variables();

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

    // condition_verified = "";

}