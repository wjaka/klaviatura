/*Arduino KLAVIATURA
   Jaka Waldhütter

 **************

   Piskač je z daljšo nogico povezan na digitalni priključek 10 s krajšo pa na GND.


   4 Načini, način se nastavi ob vklopu oz. resetu  če ga želiš spremeniti klikni rdeči gumb
   Piskač ostane vedno na istih priključkih

   1. Način:
   A5 in A4 sta povezana na GND. Tipka je povezana v levem zgornjem kotu na GND (na minus) v desnem pa na priključek 1.
   Potenciometer je povezan s sredinskim priključkom na analogni vhod A0, s stranskima pa na GND in +5V
   Piskač predvaja en ton, ko držimo tipko. S spreminjanjem vrednosti potenciometra se višina tona spreminja.

   2. Način:
   A5 je povezan na GND, A4 je povezan na +5. Tipka je povezana v levem zgornjem kotu na GND (na minus) v desnem pa na priključek 1.
   Ob stisnjeni tipki piskač predvaja melodijo

   3. Način:
   A5 je povezan na +5, A4 je povezan na GND. Piskač in tipke. Priključenih imamo 8 tipk.
   Tipke delujejo tako, da diagonalna priključka s stiskom povežejo oz. razvežejo. Z enim smo povezani na GND z drugim priključkim - njemu diagonalnim pa na digitalne priključke:
   Leve zgornje kote povežemo na GND. Desne spodnje pa: prvi tipki na priključek 1, drugi na priključek 2. in tako dalje do osmega priključka.
   Ob stisku gumba piskač zaigra ton, ki je povezan s tem gumbom.


   4. Način:
   A5 in A4 sta povezana na +5
   Vezava je enaka, kot v prejšnjem primeru, le da dodamo en potenciometer. Prvi potenciometer je povezan s sredinskim priključkom na analogni vhod A0, s stranskima pa na GND in +5V.
   Program deluje kot klaviatura. S spreminjanjem vrednosti potenciometra spreminjamo višino tona.

   Prototipna ploščica ima plus in minus razdeljena na polovico
*/

const int c = 261;          //Zbrane frekvence tonov oz. not (c - je spodnji C, cH je višji C ton (c high))
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;
const int hH = 988;
const int C6 = 1047;

int note[] = {cH, dH, eH, fH, gH, aH, hH, C6}; //Seznam not, ki jih bomo igrali na klaviaturi


const int tipka1 = 1;
const int tipka2 = 2;
const int tipka3 = 3;
const int tipka4 = 4;
const int tipka5 = 5;
const int tipka6 = 6;
const int tipka7 = 7;
const int tipka8 = 8;
const int piskac = 10;
const int pot = A0;
const int pot2 = A1;
int potenciometer1;
int potenciometer2;

long trajanje;
int razdalja;
int nacin;

void setup() {
  pinMode(tipka1, INPUT_PULLUP);  //določimo ali bodo priključki delovali, kot izhodi(OUTPUT) ali vhodi(INPUT). V našem primeru uporabljamo vgrajene upore, zato imamo INPUT_PULLUP - to je zato, da preprečimo kratke stike ob kliku tipk
  pinMode(tipka2, INPUT_PULLUP);
  pinMode(tipka3, INPUT_PULLUP);
  pinMode(tipka4, INPUT_PULLUP);
  pinMode(tipka5, INPUT_PULLUP);
  pinMode(tipka6, INPUT_PULLUP);
  pinMode(tipka7, INPUT_PULLUP);
  pinMode(tipka8, INPUT_PULLUP);
  pinMode(piskac, OUTPUT);

  Serial.begin(9600);
  int a = digitalRead(A5);
  int b = digitalRead(A4);

  if (a == 0 && b == 0)  //Preverimo v katerem načinu smo
    nacin = 1;
  else if (a == 0 && b == 1)
    nacin = 2;
  else if (a && b == 1)
    nacin = 4;
  else
    nacin = 3;
}

void loop() {

  if (nacin == 1) {
    if (digitalRead(tipka1) == LOW) {           //Če ima tipka vrednost 0 - je pritisnjena, se melodija predvaja. drugače se ne predvaja.
      potenciometer1 = analogRead(pot);        //Preberi analogno vrednost potenciometra - koliko je obrnjen (vrednosti 0 - 1032) - vrednost nič je na tisti strani, kjer smo priključili GND priključek
      int visina = 300 + potenciometer1;         //Da bi to spremembo lahko slišali prištejemo 300
      tone(piskac, visina);
    }
    else
    noTone(piskac);
  }

  if (nacin == 2) {
    if (digitalRead(tipka1) == LOW) {
      beep(a, 500);         //Kličemo funkcijo beep - njej pošljemo noto, ki jo more predvajati in čas kako dolgo mora to nota trajati. To napišemo za vsako noto posebej
      beep(a, 500);
      beep(a, 500);
      beep(f, 350);
      beep(cH, 150);
      beep(a, 500);
      beep(f, 350);
      beep(cH, 150);
      beep(a, 650);
      delay(500);         //Pavza za 500 milisekund

      beep(eH, 500);
      beep(eH, 500);
      beep(eH, 500);
      beep(fH, 350);
      beep(cH, 150);
      beep(gS, 500);
      beep(f, 350);
      beep(cH, 150);
      beep(a, 650);
      delay(500);
      
      if (digitalRead(tipka1) == LOW) {
      beep(aH, 500);
      beep(a, 300);
      beep(a, 150);
      beep(aH, 500);
      beep(gSH, 325);
      beep(gH, 175);
      beep(fSH, 125);
      beep(fH, 125);
      beep(fSH, 250);
      delay(325);

      beep(aS, 250);
      beep(dSH, 500);
      beep(dH, 325);
      beep(cSH, 175);
      beep(cH, 125);
      beep(b, 125);
      beep(cH, 250);
      delay(350);

      beep(f, 250);
      beep(gS, 500);
      beep(f, 350);
      beep(a, 125);
      beep(cH, 500);
      beep(a, 375);
      beep(cH, 125);
      beep(eH, 650);
      delay(500);
      
      if (digitalRead(tipka1) == LOW) {
      beep(aH, 500);
      beep(a, 300);
      beep(a, 150);
      beep(aH, 500);
      beep(gSH, 325);
      beep(gH, 175);
      beep(fSH, 125);
      beep(fH, 125);
      beep(fSH, 250);
      delay(325);

      beep(aS, 250);
      beep(dSH, 500);
      beep(dH, 325);
      beep(cSH, 175);
      beep(cH, 125);
      beep(b, 125);
      beep(cH, 250);
      delay(350);

      beep(f, 250);
      beep(gS, 500);
      beep(f, 375);
      beep(cH, 125);
      beep(a, 500);
      beep(f, 375);
      beep(cH, 125);
      beep(a, 650);
      delay(650);
    }
    }
    }
  }

  if (nacin == 3) {
    if (!digitalRead(tipka1))             //Če je pritisnjena prva tipka, predvajaj 1 noto iz seznama not - prva nota je na poziciji 0.
      tone(piskac, note[0]);                  //Na piskaču predvajaj noto na poziciji nič v seznamu note - to je nota C4 - NOTE_C4
    else if (digitalRead(tipka2) == LOW)       //Če prvi pogoj ne drži - prva tipka ni prtisinjena, preveri, če je pritisnjena druga tipka. Če je predvajaj drugo noto iz seznama
      tone(piskac, note[1]);
    else if (digitalRead(tipka3) == LOW)
      tone(piskac, note[2]);
    else if (digitalRead(tipka4) == LOW)
      tone(piskac, note[3]);
    else if (digitalRead(tipka5) == LOW)
      tone(piskac, note[4]);
    else if (digitalRead(tipka6) == LOW)
      tone(piskac, note[5]);
    else if (digitalRead(tipka7) == LOW)
      tone(piskac, note[6]);
    else if (digitalRead(tipka8) == LOW)
      tone(piskac, note[7]);
    else
      noTone(piskac);                        //Če nobena tipka ni pritisnjena se zvok izklopi
  }


  if (nacin == 4) {
    int pritisnjenaTipka = 0;                 //Določimo eno spremenljivko, ki nam bo povedala, če je pritisnjena katerakoli tipka.
    potenciometer1 = analogRead(pot);        //Preberi analogno vrednost potenciometra - koliko je obrnjen (vrednosti 0 - 255) - vrednost nič je na tisti strani, kjer smo priključili GND priključek
    int ton;
    if (!digitalRead(tipka1)) {            //Če je pritisnjena prva tipka, predvajaj 1 noto iz seznama not - prva nota je na poziciji 0.
      ton = note[0];
      pritisnjenaTipka = 1;
    }                         //Na piskaču je vrednost ton enaka vrednosti note na poziciji nič v seznamu note - to je nota C4 - NOTE_C4
    else if (digitalRead(tipka2) == LOW) { //Če prvi pogoj ne drži - prva tipka ni prtisinjena, preveri, če je pritisnjena druga tipka. Če je bo ton prevzel vrednost druge note iz seznama
      ton = note[1];
      pritisnjenaTipka = 1;
    }
    else if (digitalRead(tipka3) == LOW) {
      ton = note[2];
      pritisnjenaTipka = 1;
    }
    else if (digitalRead(tipka4) == LOW) {
      ton = note[3];
      pritisnjenaTipka = 1;
    }
    else if (digitalRead(tipka5) == LOW) {
      ton = note[4];
      pritisnjenaTipka = 1;
    }
    else if (digitalRead(tipka6) == LOW) {
      ton = note[5];
      pritisnjenaTipka = 1;
    }
    else if (digitalRead(tipka7) == LOW) {
      ton = note[6];
      pritisnjenaTipka = 1;
    }
    else if (digitalRead(tipka8) == LOW) {
      ton = note[7];
      pritisnjenaTipka = 1;
    }
    else {
      pritisnjenaTipka = 0;                       //Če nobena tipka in pritisnjena si zapišemo to v spremenljivko pritisnjenaTipka
    }
    if (pritisnjenaTipka == 0) {                  //Če nobena tipka ni pritisnjena se zvok izklopi
      noTone(piskac);
    }
    else {                                   //Če pa je katera tipka pritisnjena (pritisnjenaTipka = 1) pa bomo izračunali noto, ki jo bo predvajal piskač
      int visina = ton + potenciometer1;      //Vrednost višine se bo spremenila s potenciometrom. Tonu, ki bi ga tipka proizvajala prištejemo vrednost potenciometra.
      tone(piskac, visina);

    }
  }

}
void beep(int nota, int trajanje)
{
  tone(piskac, nota);     //Predvajaj na piskačo noto, ki je podana v klicu funkcije
  delay(trajanje);        //Ta nota naj se predvaja tako dolgo, kot smo zapisali v klicu funkcije
  noTone(piskac);         //Izklopi zvok
  delay(50);              //Pusti ga izklopljenega za 50 milisekund - tako se sliši vsaka nota posebej
}
