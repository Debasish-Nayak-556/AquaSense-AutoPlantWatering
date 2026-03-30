// ============================================================
//   Automatic Plant Watering System — AquaSense
//   Hardware : Arduino Uno + Soil Moisture Sensor + Relay + Pump
//   Language : Arduino C++
//   IDE      : Arduino IDE 2.x
//   Author   : YOUR_NAME
//   GitHub   : github.com/YOUR_USERNAME
// ============================================================

// ── Pin Definitions ─────────────────────────────────────────
const int SOIL_SENSOR_PIN = A0;   // Soil moisture sensor analog output
const int RELAY_PIN       = 7;    // Relay module signal pin
const int LED_PIN         = 13;   // Onboard LED — HIGH when pump is ON

// ── Threshold & Timing Settings ─────────────────────────────
// Sensor output: ~1023 = bone dry | ~200 = saturated wet
// Adjust DRY_THRESHOLD after calibrating your sensor (see README)
const int DRY_THRESHOLD   = 600;   // Raw ADC value; above = soil is dry
const int PUMP_ON_TIME    = 5000;  // ms — how long pump runs each cycle
const int CHECK_INTERVAL  = 3000;  // ms — how often soil is sampled

// ── State ───────────────────────────────────────────────────
int  soilRaw     = 0;
bool pumpRunning = false;

// ============================================================
void setup() {
  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN,   OUTPUT);

  // Relay is ACTIVE-LOW → HIGH means pump OFF at startup
  digitalWrite(RELAY_PIN, HIGH);
  digitalWrite(LED_PIN,   LOW);

  Serial.println(F("╔══════════════════════════════════════╗"));
  Serial.println(F("║   AquaSense — Plant Watering System  ║"));
  Serial.println(F("╚══════════════════════════════════════╝"));
  Serial.println(F("Monitoring soil every 3 seconds...\n"));
}

// ============================================================
void loop() {
  // 1 — Read sensor
  soilRaw = analogRead(SOIL_SENSOR_PIN);

  // 2 — Convert to moisture percentage (0 % = dry, 100 % = wet)
  int moisture = constrain(map(soilRaw, 1023, 0, 0, 100), 0, 100);

  // 3 — Print to Serial Monitor
  Serial.print(F("Moisture: "));
  Serial.print(moisture);
  Serial.print(F("% | Raw: "));
  Serial.print(soilRaw);
  Serial.print(F(" | "));

  // 4 — Decision
  if (soilRaw > DRY_THRESHOLD) {
    Serial.println(F("DRY  ▶ Activating pump..."));
    activatePump();
  } else {
    Serial.println(F("MOIST ✔ No action needed."));
    deactivatePump();
  }

  delay(CHECK_INTERVAL);
}

// ── Helpers ─────────────────────────────────────────────────
void activatePump() {
  if (!pumpRunning) {
    digitalWrite(RELAY_PIN, LOW);    // Relay ON  → pump receives power
    digitalWrite(LED_PIN,   HIGH);   // LED on    → visual indicator
    pumpRunning = true;
    Serial.println(F("  >> Pump ON"));
    delay(PUMP_ON_TIME);             // Water for set duration
    deactivatePump();                // Auto-stop
  }
}

void deactivatePump() {
  digitalWrite(RELAY_PIN, HIGH);   // Relay OFF → pump loses power
  digitalWrite(LED_PIN,   LOW);    // LED off
  pumpRunning = false;
}
