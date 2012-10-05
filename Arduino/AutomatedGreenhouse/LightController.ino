/**
 * Fisher Innovation Automated Greenhouse Controller
 * @author Matt Fisher (Fisher Innovation) [fisher.matt@gmail.com]
 *
 * Copyright (c) 2012 Fisher Innovation
 * Licensed the MIT license.
 *
 * http://www.fisherinnovation.com
 * https://github.com/fisherinnovation/FI-Automated-Greenhouse
 */
 
const int LightRelayPin = 8;  // Lighting on pin D8.

boolean LIGHTS_ON = false; // Status of the lights.

/**
 * Setup the Relay Controller.
 */
void setupLightController() {
  Serial.println("> NOTICE: Activating 120VAC Lighting Relay System...");
  
  pinMode(LightRelayPin, OUTPUT);
  Serial.println("> NOTICE: Lighting System Active.");
}

/**
 * Tests the light relays.
 */
void testLights() {
  Serial.println("> NOTICE: Testing Relay #1..");      
  digitalWrite(LightRelayPin, HIGH);
  delay(5000);
  digitalWrite(LightRelayPin, LOW);
  Serial.println("> NOTICE: Relay #1 Test Complete!");
  delay(5000);
}

/**
 * Turns the lights on.
 */
void turnLightsOn() {
  if(LIGHTS_ON == true) return;
  LIGHTS_ON = true;
  
  Serial.println("> NOTICE: Activating Lights");      
  displayLCDMessage("Lighting System", "Activating", true, 1);
  digitalWrite(LightRelayPin, HIGH);
}

/**
 * Turns the lights off.
 */
void turnLightsOff() {
  if(LIGHTS_ON == false) return;
  LIGHTS_ON = false;
  
  Serial.println("> NOTICE: Deactivating Lights");
  displayLCDMessage("Lighting System", "Deactivaing", true, 1);
  digitalWrite(LightRelayPin, LOW);
}

/**
 * Returns the current active state of the lighting system.
 */
boolean getLightsActiveState() {
  return LIGHTS_ON;
}
