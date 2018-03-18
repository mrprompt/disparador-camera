/**
  * Controlando câmera NewLink Sport Mini
 */
#define pinoFoto  9
#define pinoForca 8
#define pinoModo  7

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
int contador;

void setup() {
  Serial.begin(9600);

  pinMode(pinoForca, OUTPUT);
  pinMode(pinoFoto, OUTPUT);
  pinMode(pinoModo, OUTPUT);

  ligado = false;
  contador = 0;
  onCam = false;
}

void loop() {
  // ligando a camera
  startCam();

  // tirando a foto e desligando
  tiraFoto();

  for (int t = 0; t <= 6; t++) {
    delay(4000);
  }
  
  contador++;
}

void startCam() {
  if (ligado == false) {
    Serial.println("ligando");
    
    digitalWrite(pinoForca, HIGH);
    delay(2000);
    
    digitalWrite(pinoForca, LOW);
    delay(1000);

    ligado = true;
    contador = 0;

    for (int i = 1; i <= MODO_CAMERA; i++) {
      digitalWrite(pinoModo, HIGH);
      delay(1000);
      
      digitalWrite(pinoModo, LOW);
      delay(1000);
  
      if (i == MODO_CAMERA) onCam = true;
    }
  }
}


void tiraFoto() {
  if (ligado == true && contador == 10 && onCam == true) {
    Serial.println("tirando foto");

    digitalWrite(pinoFoto, HIGH);
    delay(2000);
    
    digitalWrite(pinoFoto, LOW);
    delay(2000);

    contador = 0;
  }
}

