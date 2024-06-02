//..................................................................................................................................................................................
#include <AccelStepper.h>  //biblioteca para introduzir aceleração e desaceleração progressiva no motor
#include <Stepper.h>       //biblioteca para controle de motor de passo
#include <MillisTimer.h>
#define stepPinRA 7           //define porta na placa do arduino; configurar conforme as portas que estão sendo usadas e fiação com o driver
#define dirPinRA 6            //define porta na placa do arduino; configurar conforme as portas que estão sendo usadas e fiação com o driver
#define stepPinDEC 4          //define porta na placa do arduino; configurar conforme as portas que estão sendo usadas e fiação com o driver
#define dirPinDEC 3           //define porta na placa do arduino; configurar conforme as portas que estão sendo usadas e fiação com o driver
#define motorInterfaceType 1  // necessário para o accelstepper
long stepsRA;
long stepsDEC;
int jatoRA = 25;
int jatoDECnorte = -10;
int jatoDECsul = 10;
int jatoRAleste = 300;
int microjatoDECnorte = -5;
int microjatoDECsul = 5;
AccelStepper RA = AccelStepper(motorInterfaceType, stepPinRA, dirPinRA);
AccelStepper dec = AccelStepper(motorInterfaceType, stepPinDEC, dirPinDEC);
//unsigned long miliRA = 32;  // aplica valor de delay para controlar a velocidade do motor; 86.164.000/(1600x139x3); dia sideral/quantidade de passos do motor em uma volta completa do RA;
long microRA2 = 16000;
long microRA1 = 16000;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  dec.setMaxSpeed(8000);      //implementa o avanço rápido; limitado pelo microstep configurado
  dec.setAcceleration(1000);  //implementa o valor da aceleração progressiva do motor para aceleração suave
  RA.setMaxSpeed(12000);
  RA.setAcceleration(1000);
  Serial.begin(9600);  //taxa de baud do monitor serial; valores mais altos são mais rápidos, porém mais instáveis
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
inicio:
  char c = Serial.read();
  if (c == 'd') {  //se, ao ler o serial, o valor encontrado é 'd', acontece em seguida...
    Serial.print("<");
    Serial.println("move RA em minutos");  //Printa expressão entre aspas na tela do monitor serial
    Serial.print(">");
    delay(100);  //espera 0,1 segundos
    Serial.available() > 1;
    stepsRA = (Serial.parseInt() * 1858);
    RA.move(stepsRA);  //desloca a quantidade de minutos lançada no serial
    RA.runToPosition();
    delay(500);
    Serial.print("<");
    Serial.println("movimento completo");
    Serial.print(">");  //printa no serial
    delay(1500);
  }
  if (c == 'e') {
    Serial.print("<");
    Serial.println("move RA em segundos");
    Serial.print(">");
    delay(100);
    Serial.available() > 1;
    stepsRA = (Serial.parseInt() * 31);
    RA.move(stepsRA);
    RA.runToPosition();
    delay(500);
    Serial.print("<");
    Serial.println("Movimento completo");
    Serial.print(">");
    delay(1500);
  }
  if (c == 'f') {
    //o cálculo de deslocamento em DEC 360x60x60 = 1296000 arcossegundos = 222400 = quantidade de micropassos em uma volta completa do eixo dec
    Serial.print("<");
    Serial.println("move dec em graus");
    Serial.print(">");
    delay(100);
    Serial.available() > 1;
    stepsDEC = (Serial.parseInt() * 2471);  // 111200 passos / 360 graus = 77
    dec.move(stepsDEC);
    dec.runToPosition();
    delay(1500);
    Serial.print("<");
    Serial.println("movimento completo");  //Printa expressão entre aspas na tela do monitor serial
    Serial.print(">");
  }
  if (c == 'r') {
    Serial.print("<");
    Serial.println("move dec em minutos");  //Printa expressão entre aspas na tela do monitor serial
    Serial.print(">");
    delay(100);
    Serial.available() > 1;
    stepsDEC = (Serial.parseInt() * 41);  //222400/21600=10,3
    dec.move(stepsDEC);
    dec.runToPosition();
    delay(1500);
    Serial.print("<");
    Serial.println("movimento completo");  //Printa expressão entre aspas na tela do monitor serial
    Serial.print(">");
  }
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (c == 'a') {
    while (c != 't') {
      if (Serial.available() > 0) {
        c = Serial.read();
      }
      if (c == 'z') {  //pode ser inserido no serial, será lido em microssegundos, o tracker é retomado com o valor agregado
        Serial.print("<");
        Serial.println("Acelerando");  //Printa expressão entre aspas na tela do monitor serial
        Serial.print(">");
        microRA1 = microRA1 - 350;  // a variável miliRA passa a assumir um decréscimo de valor do intervalo entre passos. Aceleração do motor
        c = ' ';
        if (microRA1 < 2000) {  //aqui é um limite de aceleração; o motor não acelerera atém deste ponto
          microRA1 = 2000;
        }
      }
      if (c == 'x') {
        Serial.print("<");
        Serial.println("desacelerando");  //Printa expressão entre aspas na tela do monitor serial
        Serial.print(">");
        microRA1 = microRA1 + 350;
        c = ' ';
        if (microRA1 > 32000) {  //limite para desacelerar, basta alterar
          microRA1 = 32000;
        }
      }
      if (c == '2') {
        c = ' ';
        delay(jatoRAleste);
        Serial.print("<");
        Serial.println("Leste");  //Printa expressão entre aspas na tela do monitor serial
        Serial.print(">");
      }
      if (c == '8') {
        c = ' ';
        RA.move(jatoRA);
        RA.runToPosition();
        Serial.print("<");
        Serial.println("Oeste");  //Printa expressão entre aspas na tela do monitor serial
        Serial.print(">");
      }
      if (c == '4') {
        c = ' ';
        dec.move(jatoDECnorte);
        dec.runToPosition();
        Serial.print("<");
        Serial.println("Norte");  //Printa expressão entre aspas na tela do monitor serial
        Serial.print(">");
      }
      if (c == '6') {
        c = ' ';
        dec.move(jatoDECsul);
        dec.runToPosition();
        Serial.print("<");
        Serial.println("Sul");  //Printa expressão entre aspas na tela do monitor serial
        Serial.print(">");
      }
      if (c == '9') {
        c = ' ';
        dec.move(microjatoDECsul);
        dec.runToPosition();
        Serial.print("<");
        Serial.println("Sul");  //Printa expressão entre aspas na tela do monitor serial
        Serial.print(">");
      }
      if (c == '7') {
        c = ' ';
        dec.move(microjatoDECnorte);
        dec.runToPosition();
        Serial.print("<");
        Serial.println("Norte");  //Printa expressão entre aspas na tela do monitor serial
        Serial.print(">");
      }

      if (c == 'v') {
        microRA1 = 16000;
      }
    digitalWrite(dirPinDEC, HIGH);
    digitalWrite(dirPinRA, HIGH);
    delayMicroseconds(microRA1);
    delayMicroseconds(microRA2);
    delayMicroseconds(251);
    digitalWrite(stepPinRA, LOW);
    digitalWrite(stepPinRA, HIGH);
    Serial.print("<");
    Serial.println(microRA2 + microRA1 + 251);
    Serial.print(">");
    }
  }
}
