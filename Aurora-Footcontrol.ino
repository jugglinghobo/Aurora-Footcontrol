#define INPUT_SWITCH_1 3
#define INPUT_SWITCH_2 4
#define INPUT_SWITCH_3 5
#define INPUT_SWITCH_4 6
#define INPUT_SWITCH_5 7
#define INPUT_SWITCH_6 8
#define INPUT_SWITCH_7 9
#define INPUT_SWITCH_8 10
#define INPUT_SWITCH_9 11
#define INPUT_SWITCH_0 12

#define OUTPUT_1 A0
#define OUTPUT_2 A1
#define OUTPUT_3 A3
#define OUTPUT_4 A4

#define OUTPUT_LED 13

void setup()
{
  pinMode(INPUT_SWITCH_0, INPUT_PULLUP);
  pinMode(INPUT_SWITCH_1, INPUT_PULLUP);
  pinMode(INPUT_SWITCH_2, INPUT_PULLUP);
  pinMode(INPUT_SWITCH_3, INPUT_PULLUP);
  pinMode(INPUT_SWITCH_4, INPUT_PULLUP);
  pinMode(INPUT_SWITCH_5, INPUT_PULLUP);
  pinMode(INPUT_SWITCH_6, INPUT_PULLUP);
  pinMode(INPUT_SWITCH_7, INPUT_PULLUP);
  pinMode(INPUT_SWITCH_8, INPUT_PULLUP);
  pinMode(INPUT_SWITCH_9, INPUT_PULLUP);
  pinMode(OUTPUT_1, OUTPUT);
  pinMode(OUTPUT_2, OUTPUT);
  pinMode(OUTPUT_3, OUTPUT);
  pinMode(OUTPUT_4, OUTPUT);
  pinMode(OUTPUT_LED, OUTPUT);

  // Serial.begin(115200);
  Serial.println("LOADED");
}

void loop()
{

  digitalWrite(OUTPUT_LED, LOW);

  // 0
  if (digitalRead(INPUT_SWITCH_0))
  {
    Serial.print("0: ");
    send(1, 0, 0, 1);
    return;
  }

  // 1
  if (digitalRead(INPUT_SWITCH_1))
  {
    Serial.print("1: ");
    send(0, 0, 0, 0);
    return;
  }

  // 2
  if (digitalRead(INPUT_SWITCH_2))
  {
    Serial.print("2: ");
    send(0, 0, 0, 1);
    return;
  }

  // 3
  if (digitalRead(INPUT_SWITCH_3))
  {
    Serial.print("3: ");
    send(1, 0, 0, 0);
    return;
  }

  // 4
  if (digitalRead(INPUT_SWITCH_4))
  {
    Serial.print("4: ");
    send(0, 0, 1, 0);
    return;
  }

  // 5
  if (digitalRead(INPUT_SWITCH_5))
  {
    Serial.print("5: ");
    send(0, 0, 1, 1);
    return;
  }

  // 6
  if (digitalRead(INPUT_SWITCH_6))
  {
    Serial.print("6: ");
    send(1, 0, 1, 0);
    return;
  }

  // 7
  if (digitalRead(INPUT_SWITCH_7))
  {
    Serial.print("7: ");
    send(0, 1, 0, 0);
    return;
  }

  // 8
  if (digitalRead(INPUT_SWITCH_8))
  {
    Serial.print("8: ");
    send(0, 1, 0, 1);
    return;
  }

  // 9
  if (digitalRead(INPUT_SWITCH_9))
  {
    Serial.print("9: ");
    send(1, 1, 0, 0);
    return;
  }
}

void send(uint8_t signal1, uint8_t signal2, uint8_t signal3, uint8_t signal4)
{
  digitalWrite(OUTPUT_LED, HIGH);
  Serial.print(signal1);
  Serial.print(", ");
  Serial.print(signal2);
  Serial.print(", ");
  Serial.print(signal3);
  Serial.print(", ");
  Serial.println(signal4);
  digitalWrite(OUTPUT_1, signal1);
  digitalWrite(OUTPUT_2, signal2);
  digitalWrite(OUTPUT_3, signal3);
  digitalWrite(OUTPUT_4, signal4);
}