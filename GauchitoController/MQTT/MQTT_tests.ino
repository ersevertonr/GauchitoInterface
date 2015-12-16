#include <SPI.h>
#include <PubSubClient.h>
#include <Ethernet.h>

/*
 * m2m.io Client App
 *
 * Client application for m2m.io M2M platform.
 *
 * Client handles provioning as well as provides a template
 * for publishing sensor data to the platform.
 */

#define  M2MIO_USERNAME   "<insert m2m.io username here>"
#define  M2MIO_PASSWORD   "<insert md5 hash of m2m.io password here>"
#define  M2MIO_DOMAIN     "<insert domain from m2m.io here - can be found on account tab>"
#define  M2MIO_DEVICE_ID  "<insert desired device id here - should be unique from your other devices>"

#define MQTT_SERVER "q.m2m.io"

byte MAC_ADDRESS[] = { 0x90, 0xA2, 0xDA, 0x0D, 0x31, 0xB8 };

EthernetClient ethernetClient;
PubSubClient sensorClient(MQTT_SERVER, 1883, sensorCallback, ethernetClient);
PubSubClient provisionClient(MQTT_SERVER, 1883, provisionCallback, ethernetClient);;

char clientID[50];
char topic[50];
char msg[50];

// jumper pin
// (tie to ground to provision device on startup)
// (leave floating for normal sensor mode)
int jPin = 0;
// potentiometer sensor pin
int potPin = 5;

// variables to store current time (millis)
// used to control frequency of sensor reporting
unsigned long now = 0;
unsigned long sentTime = 0;
#define REPORTING_INTERVAL_MS  1000

// flag to keep track of provisioning message sent (only send one)
boolean provisionMsgSent = false;

// device mode
// true = provisioning device to user on platform
//        upon bootup or reset device sends registration
//        message to m2m.io platform
// false = normal, sensor reporting mode
//         device connects to platform and sends a sensor
//         value to the platform at a configurable interval
boolean provisioningMode = 0;

void setup()
{
  // init serial link for debugging
  Serial.begin(9600);

  // setup potentiometer pin
  pinMode(potPin, INPUT);

  // read jumper to determine mode (provisioning / normal)
  pinMode(jPin, INPUT);
  delay(2000);
  //Serial.println(analogRead(jPin));
  if (analogRead(jPin) < 50) {
    Serial.println("Entering Provisioning Mode");
    provisioningMode = true;
  } else {
    Serial.println("Entering Sensor Mode");
    provisioningMode = false;
  }

  // initialize ethernet library  
  if (Ethernet.begin(MAC_ADDRESS) == 0)
  {
      Serial.println("Failed to configure Ethernet using DHCP");
      return;
  }


  if (provisioningMode) {
    // Device is in provisioning mode:
    //   1. create MQTT client for provisioning
    //   2. configure enrollment message and topic
    //   3. (message is sent later in loop())
    
    String clientIDStr = M2MIO_DEVICE_ID;
    clientIDStr.toCharArray(clientID, clientIDStr.length()+1);
    provisionClient.connect(clientID);
    Serial.println(clientIDStr);
    
    String topicStr = "public/enroll/";
    topicStr.concat(M2MIO_USERNAME);
    topicStr.toCharArray(topic, topicStr.length()+1);
    Serial.println(topicStr);
    
    String enrollMsg = "{\"type\":\"Arduino\",\"mac\":\"";
    enrollMsg.concat(M2MIO_DEVICE_ID);
    enrollMsg.concat("\"}");
    enrollMsg.toCharArray(msg, enrollMsg.length()+1);
    Serial.println(enrollMsg);
    
  } else {
    // Device is in sensor mode:
    //   1. create MQTT client for publishing sensor data
    //   2. configure sensor topic
    //   3. (messages are sent later in loop())

    String clientIDStr = "Arduino/";
    clientIDStr.concat(M2MIO_DEVICE_ID);
    clientIDStr.toCharArray(clientID, clientIDStr.length()+1);
    
    String topicStr = M2MIO_DOMAIN;
    topicStr.concat("/Arduino/");
    topicStr.concat(M2MIO_DEVICE_ID);
    topicStr.toCharArray(topic, topicStr.length()+1);
  }
}

void loop()
{
  now = millis();
  
  if (!provisioningMode) {
    // sensor mode
    // 1. If not connected to MQTT broker --> connect
    // 2. If time to publish:
    //       - get sensor reading
    //       - build payload with sensor value
    //       - publish to m2m.io platform
    if (!sensorClient.connected()) {
      sensorClient.connect(clientID, M2MIO_USERNAME, M2MIO_PASSWORD);
    }
    
    // loop runs more frequently than we'd want to pubish
    // only publish every "reporting interval" milliseconds
    if ((now - sentTime) > REPORTING_INTERVAL_MS) {
      sentTime = now;
      
      // get sensor value
      int levelReading = analogRead(potPin);

      // build MQTT message payload
      // m2m.io messages need to be JSON encoded for
      //   data to be stored in the platform for later recall
      String dataMsg = "{\"t\":";
      dataMsg.concat(levelReading);
      dataMsg.concat("}");
      dataMsg.toCharArray(msg, dataMsg.length()+1);
      sensorClient.publish(topic, msg);       
    }
    sensorClient.loop();
  
  } else {
    // provisioning mode
    // 1. If not connected to MQTT broker --> connect
    // 2. Publish provisioning message
    if (!provisionClient.connected()) {
      provisionClient.connect(clientID, M2MIO_USERNAME, M2MIO_PASSWORD);
    }
    
    // send the provisioning message (only once)
    if (!provisionMsgSent) {
      Serial.println("Sending provisioning message.");
      provisionClient.publish(topic, msg);
      provisionMsgSent = true;
    }    
    provisionClient.loop();
  }
}

// handles message arrived on subscribed topic(s)
// in this application we do not subscribe so this is a dummy method
void sensorCallback(char* topic, byte* payload, unsigned int length) { }

// handles message arrived on subscribed topic(s)
// in this application we do not subscribe so this is a dummy method
void provisionCallback(char* topic, byte* payload, unsigned int length) { }
