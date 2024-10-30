#include <SPI.h>
#include <Ethernet.h>

#define trigPin1 2
#define trigPin2 3
#define echoPin1 4
#define echoPin2 5

#define SERVO 6
int servoValue = 200;


// A MAC address for the controller
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

// The IP address will be dependet on your local network:
IPAddress ip(127,0,0,1);

// Initialiation of Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(80); // Because this is a simulation, the port 80 is transfered
                          // to port 2080

float duration;
float distance1, distance2; 


void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);

  pinMode(SERVO, OUTPUT);
  analogWrite(SERVO,servoValue);

  Ethernet.init(10); // Most Adrduino shields

  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial.println("Ethernet WebServer 2017");

  // Start the Ethernet connection ans the server:
  Ethernet.begin(mac,ip);

  // Check for Ethernet hardware present
  if(Ethernet.hardwareStatus() == EthernetNoHardware){ // Check if we have ethernet card
    Serial.println("Ethernet sheild was not found.");
    while(true){
      delay(1); // Do nothing, no point in running without Ethernet hardware
    }
  }

  if(Ethernet.linkStatus() == LinkOFF){ // Check if the ethernet cable is connected
    Serial.println("Ethernet cable is not connected");
  }

  // Start the server
  server.begin();
  Serial.print("HTTP Server started with IP: ");
  Serial.print(Ethernet.localIP());
  Serial.println(" and port: 80.");

  Serial.println("Waiting for client connection... ");



}

void loop() {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  duration = pulseIn(echoPin1, HIGH);
  distance1 = duration*0.01723; //343 m/s iso me 0.01723 m/ms kai kanoyme dia 2 dioti to shma lambanete san phgaine-ela, emeis theloume to phgaine

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration = pulseIn(echoPin2, HIGH);
  distance2 = duration*0.01723;

  if(distance1 > distance2 + 10){
    servoValue = 170;
  }else if(distance2 > distance1 + 10){
    servoValue = 250;
  }else{
    servoValue = 200;
  }

  analogWrite(SERVO, servoValue);

  delay(100);

  // listen for incoming clients
  EthernetClient client = server.available();  // instance of client, check if someone is connected to our server, waiting to see if we have an HTTP request
  if(client){
    Serial.println("New Client connected.");

    // An HTTP request end with a blank request from client
    bool currentLineIsBlank = true;
    while(client.connected()){
      if (client.available()){ // If we have data from client
        char c = client.read(); // read request drom client
        Serial.write(c);
        // If you have gotten to the end of the endline (receive a newline
        // character) and the line is blank, the HTTP request has enabled,
        // so youcan send a reply 

        if(c == '\n' && currentLineIsBlank){ // Read until you found the next line char
          // Send a standard HTTP respone header
          client.println("HTTP/1.1 200 OK"); // Ack 
          client.println("Content-Type: text/html");
          client.println("Connection: close"); // the connection will be terminated
          client.println("Refresh: 5"); // refresh the page automatically

          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          client.println("Hello from my webserver");
          client.println("<br />");

          client.println("<br/>");
          client.println(" Left distance is: ");
          client.println(distance1);
          client.println("<br/>");
          
          client.println("<br/>");
          client.println(" Right distance is: ");
          client.println(distance2);
          client.println("<br/>");

          client.println("<br/>");
          client.println(" Servo value is: ");
          client.println(servoValue);
          client.println("<br/>");
          client.println("<br/>");

          client.println("</html>");
          break;
        }

        if(c == '\n'){
          // you are starting a new line
          currentLineIsBlank = true;
        } else if(c != '\r'){
          // You have gotten a character on the current line
          currentLineIsBlank = false;
        }
        }

      
    }

    // Give the web browser time to receive data
    delay(1);
    // Close the connection:
    client.stop();
    Serial.println("Client disconnected");

  }   

}
