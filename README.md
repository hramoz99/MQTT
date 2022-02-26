# SPRINT 8 Sensor Magnetico

## Objetivo 
  O objetivo  desse  projeto é  utilizar um Arduino Uno junto com um Sensor  Magnético para monitorar uma porta de um Rack de Rede se está *ABERTA* ou *FECHADA*, assim  enviando essa informação via internet utilizando o protocolo MQTT (Message Queuing Telemetry Transport)  para um servidor MQTT hospedado na Amazon  Web Service (AWS) e exibir  a mensagem em um cliente  MQTT (MQTT Dash) instalado em um smartphone, de acordo com a figura abaixo:


![circuito](https://github.com/Hugo123br/SPRINT-8-Sensor-Magnetico/blob/main/Primeira%20imagem.png) 

Bibliotecas utilizadas:

UIPEthernet (conexão do ENC28J60 com o Arduino)

PubSubClient (cliente MQTT para o Arduino)

## Materiais

- Arduino Uno

- Módulo Ethernet (ENC28J60)

- Sensor Magnético (MC-38)

-  Jumpers

## *Circuito*






![image](https://user-images.githubusercontent.com/78046279/155854992-1b9b342d-86a5-45e4-8b9d-192a75521daa.png)
