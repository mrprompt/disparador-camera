/**
 * Controlando câmera NewLink Sport Mini
 * 
 * O script liga a câmera, troca para modo desejado
 * e tira uma foto a cada aproximadamente, 64 segundos.
 * 
 * @author Thiago Paes <mrprompt@gmail.com>
 */
#define PINO_FOTO  2
#define PINO_FORCA 3
#define PINO_MODO  4
#define INTERVALO_FOTO  60000 // uma foto por minuto
#define MODO_CAMERA 4

boolean ligado;
boolean onCam;
long ultimaFoto;

void setup() {
  Serial.begin(9600);

  pinMode(PINO_FORCA, OUTPUT);
  pinMode(PINO_FOTO, OUTPUT);
  pinMode(PINO_MODO, OUTPUT);

  ligado = false;
  onCam = false;
  ultimaFoto = 0;
}

void loop() {
  startCam();
  tiraFoto();

  delay(1000);
}

/**
 * Liga a câmera e coloca no modo correto
 * definido em MODO_CAMERA.
 * 
 * Modos da câmera:
 * 
 * 1 & 2 = vídeo (baixa e alta resolução, respectivamente)
 * 3 & 4 = foto (baixa e alta resolução, respectivamente)
 */
void startCam() {
  if (ligado == false) {
    Serial.println("ligando");
    
    digitalWrite(PINO_FORCA, HIGH);
    delay(1000);
    
    digitalWrite(PINO_FORCA, LOW);
    delay(1000);

    for (int i = 1; i <= MODO_CAMERA; i++) {
      digitalWrite(PINO_MODO, HIGH);
      delay(1000);
      
      digitalWrite(PINO_MODO, LOW);
      delay(1000);
  
      if (i == MODO_CAMERA) {
        onCam = true;
        ligado = true;
      }
    }
  }
}

void tiraFoto() {
  if (ligado == true && onCam == true && (millis() - ultimaFoto > INTERVALO_FOTO)) {
    Serial.println("tirando foto");

    digitalWrite(PINO_FOTO, HIGH);
    delay(1000);
    
    digitalWrite(PINO_FOTO, LOW);
    delay(1000);

    ultimaFoto = millis();

    Serial.println();
  }

  Serial.print('.');
}

