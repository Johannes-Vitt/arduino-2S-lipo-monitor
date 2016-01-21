/*
 * Licensed under CC BY-SH by Johannes Vitt 2016
 * 
 * This programm measures the voltage of the cells of a 2S (two cells) lipo. 
 * Please be cautious while handling LiPos, they can explode or burn if not 
 * treated correctly. This program is distributed without any warranty,  
 * please be cautious. 
 * 
 * In order to monitor LiPos you need to measure the Voltage of each individual
 * cell. The cells can be extremly damaged if their voltage drops below a 
 * certain value (about 3.3 V). This sketch uses the A0 pin to monitor the 
 * first cell, and a voltage divider(https://en.wikipedia.org/wiki/Voltage_divider) 
 * on A1 to measure the voltage of the second one. If you have a 3S Lipo you 
 * have to add another voltage divider (so that the input on the analog pin is 
 * under 5V). 
 */

int firstCell = A0;
int secondCell = A1;

void setup() {

  pinMode(firstCell,INPUT);
  pinMode(secondCell,INPUT);
  Serial.begin(9600);
}

void loop() {
  
  double firstValue = analogRead(firstCell);
  double firstVoltage = firstValue/1023.0*5.0;
  double secondValue = analogRead(secondCell);
  double secondVoltage = secondValue/1023.0*5.0*2-firstValue/1023.0*5.0;
  show("first",firstVoltage);
  show("second",secondVoltage);
  delay(1000);
}

void show(String whatCell, double voltage){
  Serial.print(whatCell);
  Serial.print(" cell: ");
  Serial.print(voltage);
  Serial.println(" V");

  if(voltage<3.3){
     Serial.print(whatCell);
     Serial.println(" cell has a low voltage!!!");
    }
}
