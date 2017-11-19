/*/ CRIADO POR: CAMILA FERNANDES CARDOZO, UNISINOS.
   DATA: 2017/2
*/


#define Echo 12 //denomina a porta digital 12 de Echo
#define Trig 13 //denomina a porta digital 13 de Trig
unsigned long t;  // declara t e tempo como unsigned long
int x = 0; //declara d como uma float

void setup() {  // bloco para ações que serão executas somente uma vez, na inicialização do programa.
  Serial.begin(9600); // inicializa a comunicação serial com a placa Arduino numa velocidade de 9600 bits/s
  pinMode(Trig, OUTPUT); //define o pino Trig como uma saída de dados
  pinMode(Echo, INPUT); // define o pino Echo como uma entrada de dados
}
void loop() { // bloco para as ações que serão executadas repetidas vezes após a inicialização do programa
  x++;
  digitalWrite(Trig, LOW);  //coloca o pino Trig no estado 0
  delayMicroseconds(2); //espera 2 microssegundos
  digitalWrite(Trig,  HIGH); //coloca a porta digital Trig no estado 1
  delayMicroseconds(10); // espera 10 microssegundos
  digitalWrite(Trig, LOW); // retorna o pino Trig para 0
  t = pulseIn(Echo, HIGH); // coleta o tempo em que o pino Echo esteve no estado 1, em microssegundos
  Serial.println(t / 2); // escreve no monitor serial o valor guardado em time
  if (x >= 50) {
    Serial.println("50 COLETAS");
    x = 0;
  }
  delay(500); // aguarda 1000 milissegundos e recomeça o void loop
}

