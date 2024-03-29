#include <PubSubClient.h>

#include <UIPEthernet.h>
#include <utility/logging.h>
#include <SPI.h>


//Define o endereço MAC que será utilizado
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};



//Inicia o cliente Ethernet
EthernetClient client;

PubSubClient mqttClient(client);

bool mensagem;
int pino = 2;
bool sensor;

void setup() {

  pinMode(pino, INPUT_PULLUP);
  
    //Inicia o controlador Ethernet e solicita um IP para o servidor de DHCP
    Ethernet.begin(mac);

    //Inicia o monitor Serial
    Serial.begin(9600);

    mqttClient.setServer("54.144.190.205",1883);

    //Exibe no Monitor Serial as informações sobre o IP do Arduino Uno
    Serial.print("O IP do Arduino e: ");
    Serial.println(Ethernet.localIP());

    //Exibe no Monitor Serial as informações sobre a Máscara de Rede do Arduino
    Serial.print("A Mascara de Rede do Arduino e: ");
    Serial.println(Ethernet.subnetMask());

    //Exibe no Monitor Serial as informações sobre o Gateway do Arduino
    Serial.print("O Gateway do Arduino e: ");
    Serial.println(Ethernet.gatewayIP());

    //Exibe uma linha em Branco
    Serial.println("");
    
    
    
}

void loop() {
  
  sensor = digitalRead(pino);

  if (sensor == 0){
    mqttClient.connect("Hugoramoz");
    
   mensagem = mqttClient.publish("Hugoramoz-t", "FECHADA!");
    
    Serial.println(mensagem);
    
    Serial.println("O rack esta FECHADO!");
    
    
  }
  if(sensor == 1){
    mqttClient.connect("Hugoramoz");
    
    mensagem = mqttClient.publish("Hugoramoz-t", "ABERTA!");
    
    Serial.println(mensagem);
    
    Serial.println("O rack esta ABERTO!");
    
    mqttClient.loop();
    
    }
    
}
