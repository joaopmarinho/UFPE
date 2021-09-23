int botao = 9;
int som = 13;

int tempo1 = 300;
int tempo2 = 100;
void setup()
{
  pinMode(botao, OUTPUT);
  pinMode(som, OUTPUT);
}

void loop()
{
  if (digitalRead(botao)) {
    tone(som, 659);
    delay(100);
    noTone(som);
    delay(75);
    tone(som, 587);
    delay(100);
    noTone(som);
    delay(75);
    tone(som, 455);
    delay(250);
    noTone(som);

    tone(som, 370);
    delay(100);
    noTone(som);
    delay(75);
    tone(som, 523);
    delay(100);
    noTone(som);
    delay(75);
    tone(som, 466);
    delay(250);
    noTone(som);

    tone(som, 294);
    delay(100);
    noTone(som);
    delay(75);
    tone(som, 329);
    delay(100);
    noTone(som);
    delay(75);
    tone(som, 466);
    delay(350);
    noTone(som);

    tone(som, 440);
    delay(100);
    noTone(som);
    delay(75);
    tone(som, 280);
    delay(100);
    noTone(som);
    delay(75);
    tone(som, 329);
    delay(250);
    noTone(som);
    delay(150);
  } 
}