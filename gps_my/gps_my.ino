String inString = "";
boolean DataCompleta = false;
String signal = "$GPGLL";

void setup() {
    Serial.begin(9600);
    inString.reserve(200);
}

void loop() {
    if (DataCompleta) {
        String KM = inString.substring(0, 6);
        if (KM == signal) {
            String Latitud = inString.substring(7, 17);
            int LatitudCero = Latitud.indexOf('0');
            if (LatitudCero == 0) {
                Latitud = Latitud.substring(1);
            }

            String Longitud = inString.substring(20, 31);
            int LongitudCero = Longitud.indexOf('0');
            if (LongitudCero == 0) {
                Longitud = Longitud.substring(1);
            }
            Serial.print("Longitud: ");
            Serial.println(Longitud);
            Serial.print("Latitud: ");
            Serial.println(Latitud);
    
        }
        inString = "";
        DataCompleta = false;
    }
}

/*
 * SerialEvent ocurre cuando entra data nueva por el puerto serial Rx.
 * Esta rutina corre dentro de cada bucle, asi que al usar delay dentro del loop
 * puede retrasar una respuesta que puede estar almacenada en los bytes disponibles.
 */

 void serialEvent(){
  while (Serial.available()){
    char Datos = (char) Serial.read();
    inString += Datos;
    if(Datos == '\n'){
      DataCompleta = true;
    }
  }
 }
