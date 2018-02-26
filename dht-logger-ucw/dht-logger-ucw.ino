/* 
  DHT Logger Firmware - Data logger for DHTx sensors
  Copyright 2018 Unity{Cloud}Ware - UCW Industries Ltd. All rights reserved.
 */


#include "config.h"

/*
  Edit the config.h to configure the connection string to the UCW Platform
  and any additional configuration needed for WiFi, cellular, or ethernet
  clients.
 */

#include "DHT.h"

#define DHTPIN 6
#define DHTTYPE DHT22

//comment appropriately
   UCW_API_REST ucw_api =  ucw.api();         //REST API
// UCW_API_MQTT ucw_api =  ucw.api_m();      //MQTT

#define DEVICE_ID   "your_device_id" // use device id from device section in UCW project
#define DATA_STREAM "ucw-dhtlogger"

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  
  // Start the serial connection
  Serial.begin(9600);

  while (!Serial) {
    ; // Wait for serial port to connect. Needed for native USB port only
  }

  // Connect to UCW IoT Cloud
  Serial.print("Connecting to UCW IoT Cloud...");
  ucw.connect();

  // Wait for a connection
  while (ucw.status() != UCW_NET_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // We are connected
  Serial.println(" Connected!");
  ucw.printNetworkInfo();
  
  dht.begin();
}

void loop() {
  ucw.sys();

  // read data()
  //Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

   //Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  //sending data for temperature and heat index in Celsius
  String data = "{\"humidity\": \"%humidity\", \"temperature\": \"%temperature\",\"heatIndex\": \"%heatIndex\"}";
  data.replace("%humidity", String(h));
  data.replace("%temperature", String(t));
  data.replace("%heatIndex", String(hic));
  
  ucw_api.sendData(DEVICE_ID, DATA_STREAM, data);
  
  delay(1000);
 
}

