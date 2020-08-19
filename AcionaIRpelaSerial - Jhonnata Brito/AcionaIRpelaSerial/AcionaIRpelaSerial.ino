// INCLUSÃO DE BIBLIOTECA
#include <IRremote.h>
//#include <PushButton.h>

// DIRETIVAS DE COMPILAÇÃO
#define tempoTecla 5000
#define frequencia 38 // kHz

// DEFINIÇÃO DOS PINOS
//#define pinReceptor 11
//#define pinBot1 8
//#define pinLed 3  colocar LED infravermelho

// INSTANCIANDO OBJETOS
//IRrecv receptorIR(pinReceptor);

#include <IRremote.h>

IRsend emissorIR;
//PushButton botaoLeitura(pinBot1);

// DECLARAÇÃO VARIÁVEIS GLOBAIS
bool lerComando = false;
int khz = 38; // 38kHz carrier frequency for the NEC protocol


// DECLARAÇÃO DAS FUNÇÕES DE LEITURA

void ircode   (decode_results *results);
void encoding (decode_results *results);
void dumpInfo (decode_results *results);
void dumpRaw  (decode_results *results);
void dumpCode (decode_results *results);

//  DECLARAÇÃO DAS TECLAS CLONADAS

unsigned int teclaA[] = {6060, 7420, 508, 584, 536, 584, 508, 608, 504, 588, 504, 588, 504, 584, 532, 588, 508, 552, 532, 612, 532, 560, 532, 556, 536, 556, 532, 612, 508, 584, 508, 584, 504, 612, 504, 612, 508, 588, 500, 616, 500, 560, 536, 556, 536, 556, 532, 612, 508, 580, 508, 584, 532, 616, 504, 556, 536, 584, 504, 584, 532, 560, 536, 556, 528, 588, 508, 636, 508, 556, 532, 560, 536, 608, 504, 560, 532, 588, 504, 584, 532, 588, 504, 1692, 508, 556, 532, 1668, 508, 584, 508, 584, 508, 612, 500, 588, 508, 584, 504, 612, 532, 556, 536, 584, 504, 560, 532, 612, 504, 592, 500, 588, 508, 580, 532, 612, 508, 1668, 504, 588, 504, 1664, 536, 584, 504, 588, 504, 612, 504, 588, 508, 608, 504, 616, 504, 588, 504, 556, 532, 588, 528, 588, 504, 556, 532, 564, 532, 636, 508, 584, 504, 560, 532, 608, 512, 584, 504, 1664, 508, 588, 504, 556, 536, 1692, 504, 616, 504, 1640, 504, 584, 536, 584, 508, 1668, 504, 632, 456, 1672, 504, 608, 508, 584, 504, 1640, 536, 560, 528, 1640, 532, 588, 504, 1640, 536, 1696, 504, 7392, 536};

unsigned int teclaB[] = {6092, 7392, 512, 608, 516, 580, 512, 584, 512, 612, 484, 608, 508, 588, 540, 556, 540, 584, 536, 584, 512, 588, 508, 612, 484, 608, 512, 592, 508, 580, 540, 556, 516, 580, 540, 584, 512, 584, 512, 588, 508, 612, 484, 616, 480, 608, 516, 580, 544, 556, 536, 584, 540, 556, 540, 556, 516, 636, 484, 612, 508, 588, 508, 588, 512, 584, 516, 608, 536, 560, 536, 560, 540, 556, 512, 588, 512, 584, 512, 584, 512, 612, 484, 636, 512, 584, 516, 580, 540, 560, 536, 560, 540, 556, 540, 556, 544, 556, 540, 580, 516, 584, 516, 584, 512, 584, 512, 584, 512, 612, 484, 612, 488, 612, 484, 640, 512, 584, 516, 1636, 516, 584, 512, 584, 516, 580, 520, 580, 512, 584, 516, 636, 484, 612, 512, 588, 488, 608, 488, 612, 488, 608, 488, 612, 488, 608, 512, 612, 540, 560, 544, 556, 540, 556, 540, 560, 540, 1644, 516, 580, 520, 608, 516, 1692, 544, 556, 544, 1612, 548, 580, 544, 560, 544, 1636, 488, 612, 488, 1668, 532, 1652, 516, 584, 516, 584, 544, 1668, 516, 584, 512, 588, 488, 1668, 544, 1612, 544, 7400, 520};

unsigned int teclaC[] = {6064, 7388, 536, 612, 504, 612, 508, 584, 504, 560, 532, 584, 508, 608, 508, 556, 536, 556, 536, 636, 504, 556, 536, 556, 536, 608, 508, 584, 508, 584, 508, 584, 532, 584, 508, 612, 504, 584, 532, 588, 500, 560, 532, 588, 508, 580, 536, 556, 536, 584, 508, 636, 508, 552, 536, 556, 536, 580, 532, 560, 532, 560, 532, 560, 532, 616, 500, 612, 508, 584, 504, 616, 504, 584, 508, 584, 504, 584, 508, 608, 508, 588, 504, 612, 504, 612, 508, 556, 532, 560, 532, 612, 504, 588, 504, 588, 504, 584, 524, 624, 504, 580, 508, 584, 508, 612, 504, 556, 532, 576, 516, 616, 504, 584, 508, 612, 504, 1692, 508, 1636, 536, 588, 504, 588, 528, 584, 508, 556, 536, 556, 532, 640, 508, 556, 532, 560, 532, 612, 504, 556, 536, 592, 496, 588, 504, 612, 508, 1692, 508, 584, 508, 584, 504, 1668, 504, 560, 532, 584, 532, 560, 536, 552, 536, 1664, 532, 592, 504, 1636, 536, 556, 532, 588, 532, 1640, 508, 612, 504, 1640, 556, 588, 532, 584, 508, 1640, 536, 632, 456, 1668, 504, 1696, 508, 552, 536, 1668, 508, 7388, 536};

//unsigned int teclaD[] = {6032, 7396, 540, 632, 508, 560, 532, 560, 536, 584, 508, 612, 508, 584, 508, 556, 536, 584, 536, 636, 512, 584, 512, 552, 536, 588, 504, 588, 508, 608, 508, 588, 508, 556, 532, 616, 504, 616, 508, 556, 536, 588, 504, 560, 536, 584, 508, 608, 512, 584, 508, 584, 536, 584, 508, 612, 508, 556, 536, 588, 508, 556, 536, 584, 508, 612, 508, 584, 536, 556, 536, 556, 536, 612, 508, 556, 540, 552, 536, 560, 532, 588, 508, 1668, 532, 1700, 508, 580, 508, 560, 536, 584, 536, 556, 536, 556, 536, 584, 508, 612, 536, 584, 508, 584, 508, 556, 536, 584, 508, 612, 508, 560, 532, 588, 508, 584, 536, 1636, 540, 556, 536, 1668, 508, 556, 536, 1668, 508, 1612, 536, 584, 536, 612, 512, 552, 536, 584, 504, 616, 504, 588, 512, 584, 504, 588, 504, 560, 532, 644, 508, 556, 536, 556, 532, 588, 512, 608, 508, 1668, 508, 584, 532, 588, 512, 1692, 508, 584, 508, 1640, 512, 608, 508, 584, 512, 1612, 532, 612, 512, 1612, 536, 640, 508, 1612, 536, 584, 508, 612, 508, 1668, 508, 1640, 536, 556, 536, 588, 508, 7400, 532};

void setup() {
  Serial.begin(9600);
  //  pinMode(pinLed, OUTPUT);

  // INICIANDO RECEPTOR IR
  //receptorIR.enableIRIn();
  Serial.print("Setup Concluído");
  pinMode(13, OUTPUT);
}

void loop() {
  // MÉTODO PARA LEITURA E ATUALIZAÇÃO DAS PROPRIEDADES DO BOTÃO
  // botaoLeitura.button_loop();

  // BLOCO CONDIÇÕES PARA INICIAR LEITURA
  /* if (botaoLeitura.pressed() && !lerComando) {
     lerComando = true;
     digitalWrite(pinLed, HIGH);
    } else if (botaoLeitura.pressed() && lerComando) {
     lerComando = false;
     digitalWrite(pinLed, LOW);
    }
    // LAÇO PARA LEITURA DO RECEPTOR IR QUANDO FOR PRESSIONADO O BOTÃO
    while (lerComando) {

     decode_results  results;

     if (receptorIR.decode(&results)) {
       ircode   (&results);
       encoding (&results);
       dumpInfo (&results);
       dumpRaw  (&results);
       dumpCode (&results);
       receptorIR.resume();
       lerComando = false;
       digitalWrite(pinLed, LOW);
     }
    }
  */
  // BLOCO PARA RECEBER DADOS DA SERIAL E INICIAR EMISSOR IR
  if (Serial.available()) {
    char tecla = Serial.read();

    switch (tecla) {
      case 'a':
        emissorIR.sendRaw(teclaA, sizeof(teclaA) / sizeof(teclaA[0]), frequencia);
       
        delay(tempoTecla); Serial.println("Enviando Tecla A clonada");
       // delay(5000);
         Serial.println("Enviada >A<");
        break;

      case 'b':
        emissorIR.sendRaw(teclaB, sizeof(teclaB) / sizeof(teclaB[0]), frequencia);
        Serial.println("Enviando Tecla B clonada");
        delay(tempoTecla);
        
        emissorIR.sendRaw(teclaB, sizeof(teclaB) / sizeof(teclaB[0]), frequencia);
        Serial.println("Enviando Tecla B clonada");
        delay(tempoTecla);
                  
        break;

      case 'c':
            emissorIR.sendRaw(teclaC, sizeof(teclaC) / sizeof(teclaC[0]), frequencia);
            Serial.println("Enviando Tecla C clonada");
              delay(tempoTecla);
        break;
      //
      case 'd':
      //            emissorIR.sendRaw(teclaD, sizeof(teclaD) / sizeof(teclaD[0]), frequencia);
         digitalWrite(13, HIGH);
            Serial.println("Enviando Tecla D clonada");
            delay(tempoTecla);
             digitalWrite(13, LOW);
        break;
    }
  }
}
