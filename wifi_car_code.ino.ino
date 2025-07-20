const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

WiFiServer server(80);

int IN1 = D1;
int IN2 = D2;
int IN3 = D3;
int IN4 = D4;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println(WiFi.localIP());
  server.begin();

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    if (request.indexOf("/forward") != -1) {
      forward();
    } else if (request.indexOf("/backward") != -1) {
      backward();
    } else if (request.indexOf("/left") != -1) {
      left();
    } else if (request.indexOf("/right") != -1) {
      right();
    } else if (request.indexOf("/stop") != -1) {
      stopCar();
    }

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println();
    client.println("<html><body>");
    client.println("<h1>Wi-Fi Car</h1>");
    client.println("<button onclick=\"location.href='/forward'\">Forward</button>");
    client.println("<button onclick=\"location.href='/backward'\">Backward</button>");
    client.println("<button onclick=\"location.href='/left'\">Left</button>");
    client.println("<button onclick=\"location.href='/right'\">Right</button>");
    client.println("<button onclick=\"location.href='/stop'\">Stop</button>");
    client.println("</body></html>");
  }
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
