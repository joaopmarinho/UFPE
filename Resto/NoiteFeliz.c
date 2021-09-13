int botao = 8;
int ledPin1 = 10;
int ledPin2 = 11;
int buzzerPin = 12;
int counter = 0;
//Notas
const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int a = 440;
const int b = 466;
//Notas mais altas
const int cH = 523;
const int dH = 587;
const int eH = 659;
const int fH = 698;
const int gH = 784;
const int aH = 880;
//Tempos
int minP = 1500;
int min = 1000;
int semiP = 750;
int semi = 500;
int coc = 250;

void setup()
{
  pinMode(botao, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}
//Separados por compasso 3/4
void Fsession() {
  beep(g, semiP);
  beep(a, coc);
  beep(g, semi);

  beep(e, minP);
}

void Ssession() {
  beep(dH, min);
  beep(dH, semi);
  
  beep(b, minP);
  
  beep(cH, min);
  beep(cH, semi);
  
  beep(g, minP);
}

void Tsession() {
  beep(a, min);
  beep(a, semi);
  
  beep(cH, semiP);
  beep(b, coc);
  beep(a, semi);

  beep(g, semiP);
  beep(a, coc);
  beep(g, semi);

  beep(e, minP);
}

void Qsession() {
    beep(dH, min);
    beep(dH, semi);

    beep(fH, semiP);
    beep(dH, coc);
    beep(b, semi);

    beep(cH, minP);

    beep(eH, minP);
}

void Lsession() {
    beep(cH, semiP);
    beep(g, coc);
    beep(e, semi);

    beep(g, semiP);
    beep(f, coc);
    beep(d, semi);

    beep(c, minP);
    beep(c, min);
    delay(250);
}

void music() {
  Fsession();
  Fsession();
  Ssession();
  Tsession();
  Tsession();
  Qsession();
  Lsession();
}

void loop()
{
  if (digitalRead(botao)) {
 	music();
    music();
  } 
}

void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(buzzerPin, note, duration);
 
  //Play different LED depending on value of 'counter'
  if(counter % 2 == 0)
  {
    digitalWrite(ledPin1, HIGH);
    delay(duration);
    digitalWrite(ledPin1, LOW);
  }else
  {
    digitalWrite(ledPin2, HIGH);
    delay(duration);
    digitalWrite(ledPin2, LOW);
  }
 
  //Stop tone on buzzerPin
  noTone(buzzerPin);
 
  delay(50);
 
  //Increment counter
  counter++;
}