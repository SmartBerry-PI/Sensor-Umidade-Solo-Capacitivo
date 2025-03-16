// declarando a porta do sensor como uma variavel constante
const int PINO_SENSOR_UMIDADE_SOLO = A0;
// declarando variaveis  contastes para as metricas de minimo e maximo
const float UmidadeMax = 75;
const float UmidadeMin = 65;
// função executada assim que o arduino ligar
void setup() {
  //  taxa de velocidade de processamento entre o arduino  e a  máquina 
  Serial.begin(9600);
  // o dado que o arduino armazenará atraves do sensor 
  pinMode(PINO_SENSOR_UMIDADE_SOLO, INPUT);
}
// função para o cálculo e apresentação dos dados da umidade do solo 
// a função será executada  constantemente enquanto o arduino estiver ligado
void loop() {
  // variavel local do tipo inteiro que irá armazenar o dado coletado anteriormente pela porta A0
  int leituraSensor = analogRead(PINO_SENSOR_UMIDADE_SOLO);
  // variavel local que ira armazenar o calulo da porcentagem da umidade do solo atual
  // usando a função map para converter os valor maximo e minimo que o senor captura para o 
  //intervalo de 0 a 100, colocando o 100 na frente para inverter os valores 
  float porcentagemUmidade = map(leituraSensor, 0.0, 1023.0, 100.0, 0.0);
  // imprimindo o calculo  feito anteriormente na tela 
  // Serial.print("Umidade do Solo: ");
  Serial.print("UmidadeAtual:");
  Serial.print(porcentagemUmidade);
  Serial.print(" ");
  Serial.print("Encharcamento:");
  Serial.print(UmidadeMax);
  Serial.print(" ");
  Serial.print("EstresseHidrico:");
  Serial.print(UmidadeMin);
  Serial.println(" ");

  // o tempo da espera de um segundo para repetir o loop 
  delay(1000);
}