/*

**ATENÇÃO**
 NÃO TOCAR NOS POLOS DO TRANSDUTOR LIGADO!
 ALTA VOLTAGEM (400V)

Referências
  http://blog.163.com/zhangmwen@126/blog/static/11343750220103112314708/
  http://www.robotstorehk.com/6500.pdf
  http://www.investigacion.frc.utn.edu.ar/sensores/ultrasonido/acroname_US.pdf
  http://www.senscomp.com/pdfs/Series-600-Envir-Grade-Ultrasonic-Sensor-Spec.pdf
  http://www.senscomp.com/pdfs/6500-Ranging-Modules-Spec-Rev.2.51.pdf
Dados
  Polaroid / Senscomp 6500
  Transducer 600 Series
  Medição: de 6 polegadas à 35 pés 
  Voltagem: 4,5 à 6,8V (5V nominal)
  Corrente:
    Contante: 100mA
    Pico: 2000mA (por isso é necessário o capacitor)
    
Modificações
  Capacitor de 1F entre os pinos 1(GND) e 9(Vcc)
  Resistor 4,5K (1,2K+3,3K)ohm entre os pinos 4(INIT) e 9
  Resistor 4,5K (1,2K+3,3K)ohm entre os pinos 7(ECHO) e 9
  Ponto entre os pinos 1, 2(BLNK) e 8(BINH)
*/

#define  INIT 4   // Dispara medição (fio amarelo)
#define  ECHO 5  // Recebe retorno do sinal ultrasonic (fio azul)

unsigned long tempo; // Em microsegundos

void setup()
{
  Serial.begin(9600);
  pinMode(INIT, OUTPUT);
  pinMode(ECHO, INPUT);
  delay(1000);
}

void loop()
{
  digitalWrite(INIT, HIGH); // Gatilho
  
  tempo = micros();
  while(digitalRead(ECHO) == LOW); 
  tempo = micros() - tempo;
  
  Serial.print("Tempo = ");
  Serial.print(tempo);
  Serial.print(" micro segundos\tDistancia = ");
  Serial.print((tempo*172)-273000); // (tempo*(velocidade do som em m/s)/2 (já que é ida e volta) -uma calibragem)
  Serial.println(" micrometros");
  
  digitalWrite(INIT, LOW); // Solta gatilho
  delay(1000); // Tempo entre medições 
}
