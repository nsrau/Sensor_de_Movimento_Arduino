/******
  Leds
*******/
byte ledPin[] = {12, 11, 10, 9, 8, 7};

int pin_movimento = 2;
int state = LOW;
int val = 0;

int luminosidade;
int pin_luminosidade = A0;
void setup() {
  // assim leio todos os pins leds
  for (int i=0; i<6; i++){
    pinMode(ledPin[i], OUTPUT);  
  }
  
  pinMode(pin_movimento, INPUT);
  pinMode(pin_luminosidade,INPUT);
  Serial.begin(9600);

}

void loop() {
 
  val = digitalRead(pin_movimento);
  luminosidade = analogRead(pin_luminosidade);
  
  if (val == HIGH && luminosidade < 20) {

    for (int i=0; i<6; i++) {
      digitalWrite(ledPin[i], HIGH);   
    }
    
    Serial.print("pouca luz, entao acendo os leds!");
    Serial.print('\n');
    
    if (state == LOW) {
      	Serial.println("Movimento detectado!"); 
	Serial.print('\n');
      	state = HIGH; // update state
    }

    delay(20000);
    
  } else {
    
     	Serial.print("luz detectada, entao apago os leds!");
    	Serial.print('\n'); 
    
      for (int i=0; i<6; i++) {
        digitalWrite(ledPin[i], LOW);   
      }

      if (state == HIGH){
        Serial.println("Nenuhm movimento!");
        state = LOW; 
      }
      
    	Serial.print("valor luminosidade : ");
  	Serial.println(luminosidade);
  	Serial.print('\n'); 
  
      delay(100);  
    
  }
  
}
