#define MQ2_PIN A2 // CO, Methane
#define MQ3_PIN A0 // Alcohol
#define MQ7_PIN A1 // Combustible gas
#define MQ135_PIN A3 // Air Quality
#define TEMPERATURE_PIN A4 // Temperature

#define baud_rate 115200

#define samples 6

void setup() {
  pinMode(INPUT, MQ2_PIN);
  pinMode(INPUT, MQ3_PIN);
  pinMode(INPUT, MQ7_PIN);
  pinMode(INPUT, MQ135_PIN);
  pinMode(INPUT, TEMPERATURE_PIN);
  Serial.begin(baud_rate);
  //delay(300000); // Preheating time = 5 Mins
}

void loop() {
  float mq2_sum = 0;
  float mq3_sum = 0;
  float mq7_sum = 0;
  float mq135_sum = 0;
  float temperature_sum = 0;

  for (int i = 0; i < samples; i++ ) {
    mq2_sum += analogRead(MQ2_PIN);
    mq3_sum += analogRead(MQ3_PIN);
    mq7_sum += analogRead(MQ7_PIN);
    mq135_sum += analogRead(MQ135_PIN);
    temperature_sum += convert_temperature(analogRead(TEMPERATURE_PIN));
    delay(10000); // get data every 10 sec
  }

//  Serial.print("CO: ");
  Serial.print(mq2_sum/samples);
  Serial.print(",");
//  Serial.print(" Alco: ");
  Serial.print(mq3_sum/samples);
  Serial.print(",");
//  Serial.print(" COM: ");
  Serial.print(mq7_sum/samples);
  Serial.print(",");
//  Serial.print(" AQ: ");
  Serial.print(mq135_sum/samples);
  Serial.print(",");
//  Serial.print(" Temp: ");
  Serial.print(temperature_sum/samples);
  Serial.println();
}

float convert_temperature(float analog_val) {
  float voltage = (analog_val / 1024.0) * 5.0;
  float temperature = (voltage - 0.5) * 100.0;
  return temperature;
}
