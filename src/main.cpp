#include <Arduino.h>
                          // First two are ecoder inputs like A+ and A-
                          // Second ones you don't have to use only if you want to use this as external out
                          //
#define ENC_1 25          //        A+
#define ENC_2 26          //        A-
#define ENC_OUTPUT_A1 14  //      
#define ENC_OUTPUT_A2 12  //

boolean stan_p;
long enkoder_ticks = 0;
void setup() {
  Serial.begin(115200);
////////////////////////////////////////////  
  for(int i = 0; i<10; i++) {
    Serial.print(". ");
    delay(40);
  }
  Serial.println();Serial.println("Welcom to encoder world :)");
  delay(50);
/////////////////////////////////////////////
  
  pinMode(ENC_OUTPUT_A1, OUTPUT);
  pinMode(ENC_OUTPUT_A2, OUTPUT);
  pinMode(ENC_1, INPUT_PULLUP);
  pinMode(ENC_2, INPUT_PULLUP);

}

boolean oneshoot(boolean stan){
  boolean X;
  if(stan != stan_p)  {X = 1;}
  else                {X = 0;}
  stan_p = stan;
  
  return X;
}


void loop() {
  boolean A_p = digitalRead(ENC_1);
  boolean A_m = digitalRead(ENC_2);
  boolean ONS_p = oneshoot(A_p);
  boolean ONS_m = oneshoot(A_m);

  digitalWrite(ENC_OUTPUT_A1, ONS_p);
  digitalWrite(ENC_OUTPUT_A2, ONS_m);

  if(!ONS_p && ONS_m) {
    enkoder_ticks++;
  }
  if(ONS_p && !ONS_m) {
    enkoder_ticks--;
    }

  
}


