/******
  Leds
*******/
byte ledPin[] = {12, 11, 10, 9, 8, 7};

int pin_movimento = 2;
int stato = LOW;
int val = 0;

int luminosita;
int pin_luminosita = A0;
void setup() {
  // ciclo for per leggere tutti i pin
  for (int i=0; i<6; i++){
    pinMode(ledPin[i], OUTPUT);  
  }
  
  pinMode(pin_movimento, INPUT);
  pinMode(pin_luminosita,INPUT);
  Serial.begin(9600);

}

void loop() {
 
  val = digitalRead(pin_movimento);
  luminosita = analogRead(pin_luminosita);
  
  if (val == HIGH && luminosita < 20) {

    for (int i=0; i<6; i++) {
      digitalWrite(ledPin[i], HIGH);   
    }
    
    Serial.print("poca luce, quindi luce acende al movimento!");
    Serial.print('\n');//a capo
    
    if (stato == LOW) {
      		Serial.println("Movimento detectato!"); 
					Serial.print('\n'); //a capo
      		stato = HIGH; // aggiorno stato variabile
    }

    delay(20000);
    
  } else {
    
     	Serial.print("troppa luce, quindi luce spenta!");
    	Serial.print('\n'); //a capo 
    
      for (int i=0; i<6; i++) {
        		digitalWrite(ledPin[i], LOW);   
      }

      if (stato == HIGH){
        		Serial.println("Nussun movimento!");
        		stato = LOW; // aggiorno stato variabile
      }
      
      Serial.print("valore luminosita : ");
  		Serial.println(luminosita);
  		Serial.print('\n'); //a capo
  
      delay(100);  
    
  }
  
}