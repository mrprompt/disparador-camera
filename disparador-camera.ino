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

/**
 * Modo da câmera 
 * 
 * 1 & 2 = vídeo
 * 3 & 4 = foto
 * 
 * baixa e alta resolução, respectivamente.
 */
#define MODO_CAMERA 4

boolean ligado;
boolean onCam;

void setup() {
  Serial.begin(9600);

  pinMode(PINO_FORCA, OUTPUT);
  pinMode(PINO_FOTO, OUTPUT);
  pinMode(PINO_MODO, OUTPUT);

  ligado = false;
  onCam = false;
}

void loop() {
  // ligando a camera
  startCam();

  // tirando a foto e desligando
  tiraFoto();
}

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
  
      if (i == MODO_CAMERA) onCam = true;
    }

    ligado = true;
  }
}

void tiraFoto() {
  if (ligado == true && onCam == true) {
    Serial.println("tirando foto");

    digitalWrite(PINO_FOTO, HIGH);
    delay(1000);
    
    digitalWrite(PINO_FOTO, LOW);
    delay(1000);

    // long delay
    geraIntervalo();
  }
}

void geraIntervalo() {
  for (int t = 0; t <= 7; t++) {
    Serial.print('.');
    delay(8000);
  }
  
  Serial.println();
}

