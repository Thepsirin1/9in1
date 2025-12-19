#include <DHT.h>

#define sw1 2
#define sw2 3
#define ledR 12
#define ledB 13
#define dht1 4
#define dhttype DHT11
#define pot A0
#define ldr A1
#define lm35 A2

DHT dht(dht1, dhttype);

int time = 1000;

void setup()
{
    pinMode(sw1, INPUT_PULLUP);
    pinMode(sw2, INPUT_PULLUP);
    pinMode(ledR, OUTPUT);
    pinMode(ledB, OUTPUT);

    Serial.begin(9600);

    dht.begin();
}

void loop()
{
    SW();
    LEDBLINK();
    DHT5();
    ADCVDC();
    LDR();
    LM35();
}

void SW()
{
    int b1 = digitalRead(sw1);
    int b2 = digitalRead(sw2);

    if (b1 == 0)
    {
        digitalWrite(ledR, 1);
        digitalWrite(ledB, 0);
    }
    else if (b2 == 0)
    {
        digitalWrite(ledR, 0);
        digitalWrite(ledB, 1);
    }
    else
    {
        digitalWrite(ledR, 0);
        digitalWrite(ledB, 0);
    }
}

void LEDBLINK()
{
    digitalWrite(ledR, 1);
    digitalWrite(ledB, 1);
    delay(time);
    digitalWrite(ledR, 0);
    digitalWrite(ledB, 0);
    delay(time);
}

void DHT5()
{
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();

    Serial.print("TEMP : ");
    Serial.print(temp);
    Serial.print(" | ");
    Serial.print("HUM : ");
    Serial.print(hum);
    Serial.println();
}

void ADCVDC()
{
    int adc = analogRead(pot);
    float vdc = (adc * (5.0 / 1023.0));

    Serial.print("ADC : ");
    Serial.print(adc);
    Serial.print(" | ");
    Serial.print("VDC : ");
    Serial.print(vdc);
    Serial.println();
}

void LDR()
{
    int ldradc = analogRead(ldr);
    float ldrvdc = (ldradc * (5.0 / 1023.0));

    Serial.print("LDR ADC : ");
    Serial.print(ldradc);
    Serial.print(" | ");
    Serial.print("LDR VDC : ");
    Serial.print(ldrvdc);
    Serial.println();
}

void LM35()
{
    int lm35adc = analogRead(lm35);
    float lm35vdc = (lm35adc * (5.0 / 1024.0));

    Serial.print("LM35 ADC : ");
    Serial.print(lm35adc);
    Serial.print(" | ");
    Serial.print("LM35 VDC : ");
    Serial.print(lm35vdc);
    Serial.println();
}
