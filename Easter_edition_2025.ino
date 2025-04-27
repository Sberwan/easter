#include <LiquidCrystal.h>

// LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Buzzer passivo
const int buzzerPin = 8;

// Notas musicais principais
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_Fs4 370
#define NOTE_Gs4 415
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_Cs5 554
#define NOTE_E5  659

// Letra da música em blocos de 2 linhas
String letra[] = {
  "Coelhinho da", "pascoa, que trazes",
  "pra mim?", "Um ovo, dois ovos,",
  "tres ovos, assim", "Coelhinho da",
  "pascoa, que trazes", "pra mim?",
  "Um ovo, dois ovos,", "tres ovos, assim",
  "Coelhinho da", "pascoa, que cor",
  "eles tem?", "Azul, amarelo,",
  "vermelho tambem", "Azul, amarelo,",
  "vermelho tambem"
};

// Nova melodia: 8 notas por bloco (x9 blocos = 72 notas)
int melodia[][8] = {
  {NOTE_A4, NOTE_E4, NOTE_Cs5, NOTE_A4, NOTE_E4, NOTE_Cs5, NOTE_A4, NOTE_E4},
  {NOTE_D4, NOTE_A4, NOTE_Fs4, NOTE_D4, NOTE_A4, NOTE_Fs4, NOTE_D4, NOTE_A4},
  {NOTE_E4, NOTE_Gs4, NOTE_B4, NOTE_E4, NOTE_Gs4, NOTE_B4, NOTE_E4, NOTE_Gs4},
  {NOTE_D4, NOTE_A4, NOTE_Fs4, NOTE_D4, NOTE_A4, NOTE_Fs4, NOTE_D4, NOTE_Fs4},
  {NOTE_E4, NOTE_B4, NOTE_Gs4, NOTE_E4, NOTE_B4, NOTE_E4, NOTE_B4, NOTE_E4},
  {NOTE_A4, NOTE_Cs5, NOTE_E5, NOTE_A4, NOTE_Cs5, NOTE_E5, NOTE_A4, NOTE_E5},
  {NOTE_D4, NOTE_A4, NOTE_Fs4, NOTE_D4, NOTE_Fs4, NOTE_D4, NOTE_A4, NOTE_Fs4},
  {NOTE_E4, NOTE_Gs4, NOTE_B4, NOTE_E4, NOTE_Gs4, NOTE_E4, NOTE_Gs4, NOTE_B4},
  {NOTE_D4, NOTE_Fs4, NOTE_A4, NOTE_D4, NOTE_Fs4, NOTE_D4, NOTE_A4, NOTE_D4}
};

// Duração de cada nota (em milissegundos)
int durations[8] = {500, 400, 400, 500, 400, 400, 500, 400};

void playNote(int freq, int duration) {
  if (freq > 0) {
    tone(buzzerPin, freq, duration);
  }
  delay(duration * 1.2); // pausa leve entre as notas
  noTone(buzzerPin);
}

void setup() {
  lcd.begin(16, 2);
  pinMode(buzzerPin, OUTPUT);

  // Scroll inicial "Feliz Páscoa"
  String mensagem = "Feliz Pascoa!";
  for (int pos = 16; pos > -mensagem.length(); pos--) {
    lcd.clear();
    lcd.setCursor(pos, 0);
    lcd.print(mensagem);
    delay(300);
  }

  delay(1000);
  lcd.clear();
}

void loop() {
  int totalBlocos = sizeof(letra) / sizeof(letra[0]) / 2;

  for (int i = 0; i < totalBlocos; i++) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(letra[i * 2]);
    lcd.setCursor(0, 1);
    lcd.print(letra[i * 2 + 1]);

    // Toca 8 notas suaves relacionadas a esse bloco
    for (int j = 0; j < 8; j++) {
      playNote(melodia[i][j], durations[j]);
    }

    delay(500); // Pequena pausa após bloco
  }

  lcd.clear();
  delay(3000); // Pausa antes de recomeçar
}
