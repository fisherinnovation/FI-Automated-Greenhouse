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

/**
 * Polls the DHT22 sensors for the current temperature and humidity readings.
 * Pending the data validates, the temperature and humidity values are
 * pushed to public variables.
 */
void getDHT22Data() {
  DHT22_ERROR_t errorCode;
  
  // Power's voltage should be 3.3-6V DC. When power is supplied to sensor, don't send any instruction to the sensor 
  // within one second to pass unstable status. One capacitor valued 100nF can be added between VDD and GND for wave filtering.
  delay(2000);
  
  errorCode = myDHT22.readData();
  
  switch(errorCode) {
    case DHT_ERROR_NONE:
    {
      CURRENT_TEMP = myDHT22.getTemperatureC();
      CURRENT_HUMIDITY = myDHT22.getHumidity();
    }
    break;
    
    case DHT_ERROR_CHECKSUM:
      Serial.print("DHT22 ERROR: Check Sum Error.");
      Serial.print(myDHT22.getTemperatureC(), DEC);
      Serial.println("C");
    break;
    
    // Errors
    case DHT_BUS_HUNG:           Serial.println("ERROR: DHT22 ERROR: BUS Hung.");        break;
    case DHT_ERROR_NOT_PRESENT:  Serial.println("ERROR: DHT22 ERROR: Not Present.");     break;
    case DHT_ERROR_ACK_TOO_LONG: Serial.println("ERROR: DHT22 ERROR: ACK time out.");    break;
    case DHT_ERROR_SYNC_TIMEOUT: Serial.println("ERROR: DHT22 ERROR: Sync Timeout.");    break;
    case DHT_ERROR_DATA_TIMEOUT: Serial.println("ERROR: DHT22 ERROR: Data Timeout.");    break;
    case DHT_ERROR_TOOQUICK:     Serial.println("ERROR: DHT22 ERROR: Polled to quick."); break;
  }
}
