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

int sensorLow = 1023;
int sensorHigh = 0;

int variation_1 = 0;
int variation_2 = 0;
int variation_3 = 0;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(led_1_pin, OUTPUT);
  pinMode(led_2_pin, OUTPUT);
  pinMode(led_3_pin, OUTPUT);

  digitalWrite(led_1_pin, LOW);
  digitalWrite(led_2_pin, LOW);
  digitalWrite(led_3_pin, LOW);

  // while (millis() < 5000) {
  //   sensor_1_value = analogRead(sensor_1_pin);
  //   if (sensor_1_value > sensorHigh) {
  //     sensorHigh = sensor_1_value;
  //   }
  //   if (sensor_1_value < sensorLow) {
  //     sensorLow = sensor_1_value;
  //   }    
  // }

  // digitalWrite(led_1_pin, HIGH);
  // digitalWrite(led_2_pin, HIGH);
  // digitalWrite(led_3_pin, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  sensor_1_value = analogRead(sensor_1_pin);
  sensor_2_value = analogRead(sensor_2_pin);
  sensor_3_value = analogRead(sensor_3_pin);

  delay(20);

  variation_1 = abs(sensor_1_value - analogRead(sensor_1_pin));
  variation_2 = abs(sensor_1_value - analogRead(sensor_2_pin));
  variation_3 = abs(sensor_1_value - analogRead(sensor_3_pin));

  Serial.print("Variation in raw sensor values \t 1:" );
  Serial.print(variation_1);
  Serial.print("\t 2: ");
  Serial.print(variation_2);
  Serial.print("\t 3: ");
  Serial.println(variation_3);

  if (variation_1 > 20 or variation_2 > 20 or variation_3 > 20) {

    digitalWrite(led_1_pin, HIGH);
    digitalWrite(led_2_pin, HIGH);
    digitalWrite(led_3_pin, HIGH);

    delay(1000);

    digitalWrite(led_1_pin, LOW);
    digitalWrite(led_2_pin, LOW);
    digitalWrite(led_3_pin, LOW);

    variation_1 = 0;
    variation_2 = 0;
    variation_3 = 0;

  }







  digitalWrite(led_1_pin, LOW);
  digitalWrite(led_2_pin, LOW);
  digitalWrite(led_3_pin, LOW);

}
