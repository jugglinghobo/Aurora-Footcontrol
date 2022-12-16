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
#define OUTPUT_3 A2
#define OUTPUT_4 A3

#define OUTPUT_LED 13

static bool active = false;

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

  
  if (digitalRead(INPUT_SWITCH_0)) // 0
  {
    active = true;
    Serial.print("0: ");
    // 1001
    // send(1, 0, 0, 1);
    // 1110: switch to previous preset
    send(1, 1, 1, 0);
    return;
  } else if (digitalRead(INPUT_SWITCH_1)) // 1
  {
    active = true;
    Serial.print("1: ");
     // 0000
    send(1, 0, 1, 1);
    return;
  } else if (digitalRead(INPUT_SWITCH_2)) // 2
  {
    active = true;
    Serial.print("2: ");
    // 0001
    send(0, 0, 0, 1);
    return;
  } else if (digitalRead(INPUT_SWITCH_3)) // 3
  {
    active = true;
    Serial.print("3: ");
    // 1000
    send(1, 0, 0, 0);
    return;
  } else if (digitalRead(INPUT_SWITCH_4)) // 4
  {
    active = true;
    Serial.print("4: ");
    // 0010
    send(0, 0, 1, 0);
    return;
  } else if (digitalRead(INPUT_SWITCH_5)) // 5
  {
    active = true;
    Serial.print("5: ");
    // 0011
    send(0, 0, 1, 1);
    return;
  } else if (digitalRead(INPUT_SWITCH_6)) // 6
  {
    active = true;
    Serial.print("6: ");
    // 1010
    send(1, 0, 1, 0);
    return;
  } else if (digitalRead(INPUT_SWITCH_7)) // 7
  {
    active = true;
    Serial.print("7: ");
    // 0100
    send(0, 1, 0, 0);
    return;
  } else if (digitalRead(INPUT_SWITCH_8)) // 8
  {
    active = true;
    Serial.print("8: ");
    // 0101
    send(0, 1, 0, 1);
    return;
  } else if (digitalRead(INPUT_SWITCH_9)) // 9
  {
    active = true;
    Serial.print("9: ");
    // 1100
    send(1, 1, 0, 0);
    return;
  } else if (active) {
    active = false;
    send(0, 0, 0, 0);
  }
}

void send(uint8_t signal3, uint8_t signal4, uint8_t signal1, uint8_t signal2)
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