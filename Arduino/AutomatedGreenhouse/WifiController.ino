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
 
prog_char s_WT_SETUP_01[] PROGMEM = "set u m 0x1";
prog_char s_WT_SETUP_02[] PROGMEM = "set comm remote 0";
prog_char s_WT_SETUP_03[] PROGMEM = "set comm idle 30";
prog_char s_WT_SETUP_04[] PROGMEM = "set comm time 2000";
prog_char s_WT_SETUP_05[] PROGMEM = "set comm size 64";
prog_char s_WT_SETUP_06[] PROGMEM = "set comm match 0x9";
prog_char s_WT_SETUP_07[] PROGMEM = "time";
prog_char s_WT_STATUS_SENSORS[] PROGMEM = "show q 0x177 ";
prog_char s_WT_STATUS_TEMP[] PROGMEM = "show q t ";
prog_char s_WT_STATUS_RSSI[] PROGMEM = "show rssi ";
prog_char s_WT_STATUS_BATT[] PROGMEM = "show battery ";
prog_char s_WT_MSG_JOIN[] PROGMEM = "Credentials Set, Joining ";
prog_char s_WT_MSG_START_WEBCLIENT[] PROGMEM = "Establishing Wifi Connection - Please wait...";
prog_char s_WT_MSG_RAM[] PROGMEM = "RAM :";
prog_char s_WT_MSG_START_WIFLY[] PROGMEM = "Started WiFly, RAM :";
prog_char s_WT_MSG_WIFI[] PROGMEM = "Initial WiFi Settings :";
prog_char s_WT_MSG_APP_SETTINGS[] PROGMEM = "Configure WebClientGetPost Settings...";
prog_char s_WT_MSG_WIRE_RX[] PROGMEM = "Wifi Rx Pin:";
prog_char s_WT_MSG_WIRE_TX[] PROGMEM = "Wifi Tx Pin:";
prog_char s_WT_MSG_FAIL_OPEN[] PROGMEM = "Failed on opening connection to:";
prog_char s_WT_HTML_HEAD_01[] PROGMEM = "HTTP/1.1 200 OK \r ";
prog_char s_WT_HTML_HEAD_02[] PROGMEM = "Content-Type: text/html;charset=UTF-8\r ";
prog_char s_WT_HTML_HEAD_03[] PROGMEM = " Content-Length: ";
prog_char s_WT_HTML_HEAD_04[] PROGMEM = "Connection: close \r\n\r\n";
prog_char s_WT_POST_HEAD_01[] PROGMEM = "HTTP/1.1\n";
prog_char s_WT_POST_HEAD_02[] PROGMEM = "Content-Type: application/x-www-form-urlencoded\n";
prog_char s_WT_POST_HEAD_03[] PROGMEM = "Content-Length: ";
prog_char s_WT_POST_HEAD_04[] PROGMEM = "Connection: close\n\n";

#define WIFI_RX_PIN  10
#define WIFI_TX_PIN  11

#define MY_SERVER_GET "mydomain.com"
#define MY_SERVER_GET_URL "file-to-log-data.php"

#define IDX_WT_SETUP_00 0
#define IDX_WT_SETUP_01 IDX_WT_SETUP_00 
#define IDX_WT_SETUP_02 IDX_WT_SETUP_01 +1
#define IDX_WT_SETUP_03 IDX_WT_SETUP_02 +1
#define IDX_WT_SETUP_04 IDX_WT_SETUP_03 +1
#define IDX_WT_SETUP_05 IDX_WT_SETUP_04 +1
#define IDX_WT_SETUP_06 IDX_WT_SETUP_05 +1
#define IDX_WT_SETUP_07 IDX_WT_SETUP_06 +1

#define IDX_WT_STATUS_SENSORS    IDX_WT_SETUP_07 +1
#define IDX_WT_STATUS_TEMP       IDX_WT_STATUS_SENSORS +1
#define IDX_WT_STATUS_RSSI       IDX_WT_STATUS_TEMP +1
#define IDX_WT_STATUS_BATT       IDX_WT_STATUS_RSSI +1

#define IDX_WT_MSG_JOIN          IDX_WT_STATUS_BATT +1
#define IDX_WT_MSG_START_WEBCLIENT IDX_WT_MSG_JOIN +1
#define IDX_WT_MSG_RAM           IDX_WT_MSG_START_WEBCLIENT +1
#define IDX_WT_MSG_START_WIFLY   IDX_WT_MSG_RAM +1
#define IDX_WT_MSG_WIFI          IDX_WT_MSG_START_WIFLY +1
#define IDX_WT_MSG_APP_SETTINGS  IDX_WT_MSG_WIFI +1
#define IDX_WT_MSG_WIRE_RX       IDX_WT_MSG_APP_SETTINGS +1
#define IDX_WT_MSG_WIRE_TX       IDX_WT_MSG_WIRE_RX +1
#define IDX_WT_MSG_FAIL_OPEN     IDX_WT_MSG_WIRE_TX +1

#define IDX_WT_HTML_HEAD_01      IDX_WT_MSG_FAIL_OPEN + 1
#define IDX_WT_HTML_HEAD_02      IDX_WT_HTML_HEAD_01 + 1
#define IDX_WT_HTML_HEAD_03      IDX_WT_HTML_HEAD_02 + 1
#define IDX_WT_HTML_HEAD_04      IDX_WT_HTML_HEAD_03 + 1

#define IDX_WT_POST_HEAD_01      IDX_WT_HTML_HEAD_04 + 1
#define IDX_WT_POST_HEAD_02      IDX_WT_POST_HEAD_01 + 1
#define IDX_WT_POST_HEAD_03      IDX_WT_POST_HEAD_02 + 1
#define IDX_WT_POST_HEAD_04      IDX_WT_POST_HEAD_03 + 1

PROGMEM const char *WT_string_table[] = 	   
{   
//  s_WT_SETUP_00,
  s_WT_SETUP_01,
  s_WT_SETUP_02,
  s_WT_SETUP_03,
  s_WT_SETUP_04,
  s_WT_SETUP_05,
  s_WT_SETUP_06,
  s_WT_SETUP_07,
  s_WT_STATUS_SENSORS,
  s_WT_STATUS_TEMP,
  s_WT_STATUS_RSSI,
  s_WT_STATUS_BATT,
  s_WT_MSG_JOIN,
  s_WT_MSG_START_WEBCLIENT,
  s_WT_MSG_RAM,
  s_WT_MSG_START_WIFLY,
  s_WT_MSG_WIFI,
  s_WT_MSG_APP_SETTINGS,
  s_WT_MSG_WIRE_RX,
  s_WT_MSG_WIRE_TX,
  s_WT_MSG_FAIL_OPEN,
  s_WT_HTML_HEAD_01,
  s_WT_HTML_HEAD_02,
  s_WT_HTML_HEAD_03,
  s_WT_HTML_HEAD_04,
  s_WT_POST_HEAD_01,
  s_WT_POST_HEAD_02,
  s_WT_POST_HEAD_03,
  s_WT_POST_HEAD_04
};

// various buffer sizes
#define REQUEST_BUFFER_SIZE 180
#define POST_BUFFER_SIZE 360
#define TEMP_BUFFER_SIZE 120

char chMisc;
int iRequest = 0;
int iTrack = 0;
int iLoopCounter = 0;

WiFlySerial wifi(WIFI_RX_PIN ,WIFI_TX_PIN);
char bufRequest[REQUEST_BUFFER_SIZE];
char bufTemp[TEMP_BUFFER_SIZE];


// Function for setSyncProvider
time_t GetSyncTime() {
  time_t tCurrent = (time_t) wifi.getTime();
  wifi.exitCommandMode();
  return tCurrent;
}

// GetBuffer_P
// Returns pointer to a supplied Buffer, from PROGMEM based on StringIndex provided.
// based on example from http://arduino.cc/en/Reference/PROGMEM
char* GetBuffer_P(const int StringIndex, char* pBuffer, int bufSize) { 
  strncpy_P(pBuffer, (char*)pgm_read_word(&(WT_string_table[StringIndex])), bufSize);  
  return pBuffer; 
}

// Reconnects to a wifi network.
// DHCP is enabled explicitly.
// You may need to add the MAC address to your MAC filter list.
// Static IP settings available if needed.
boolean Reconnect() {
  wifi.SendCommand(GetBuffer_P(IDX_WT_SETUP_01,bufTemp,TEMP_BUFFER_SIZE), ">",bufRequest, REQUEST_BUFFER_SIZE);
  wifi.setDHCPMode(WIFLY_DHCP_CACHE);
  wifi.SendCommand(GetBuffer_P(IDX_WT_SETUP_02,bufTemp,TEMP_BUFFER_SIZE),">",bufRequest, REQUEST_BUFFER_SIZE);
  
  Serial << F("Leaving current wifi ...") << wifi.leave() << endl;
  
  wifi.setPassphrase(passphrase);    
  
  Serial << GetBuffer_P(IDX_WT_MSG_JOIN,bufTemp,TEMP_BUFFER_SIZE) << ssid << endl;
  
  wifi.join(ssid);
  // Set NTP server, update frequency, 
  wifi.setNTP(ntp_server); 
  wifi.setNTP_Update_Frequency(" 15");
  
  // don't send *HELLO* on http traffic
  // close idle connections after n seconds
  // give enough time for packet data to arrive
  // make data packet size sufficiently large
  // send data packet when a \t appears in stream
  //  force time resync.

  // Configure application-specific settings
  //Serial << GetBuffer_P(IDX_WT_MSG_APP_SETTINGS, bufTemp, TEMP_BUFFER_SIZE) << endl;
  
  for (int i = 0; i< 7 ; i++) {
    wifi.SendCommand(GetBuffer_P(IDX_WT_SETUP_01 + i,bufTemp,TEMP_BUFFER_SIZE),">",bufRequest, REQUEST_BUFFER_SIZE);
  }
  
  wifi.getDeviceStatus();
  
  setTime( wifi.getTime() );
  
  delay(1000);
  
  setSyncProvider( GetSyncTime );

  // reboot if not working right yet.
  iTrack++;
  if ( iTrack > 5 ) {
    wifi.reboot();
    iTrack = 0;
  }
}


/**
 * WifiController Setup
 */
void setupWifiController() {
  Serial.println("> NOTICE: Activating Wifi Controller...");
  
  Serial << GetBuffer_P(IDX_WT_MSG_START_WEBCLIENT,bufTemp,TEMP_BUFFER_SIZE) << endl << GetBuffer_P(IDX_WT_MSG_RAM,bufTemp,TEMP_BUFFER_SIZE) << freeMemory() << endl
    << GetBuffer_P(IDX_WT_MSG_WIRE_RX,bufTemp,TEMP_BUFFER_SIZE) << WIFI_RX_PIN << endl << GetBuffer_P(IDX_WT_MSG_WIRE_TX,bufTemp,TEMP_BUFFER_SIZE) << WIFI_TX_PIN << endl;

  wifi.begin();
  
  Serial << F("Starting WebClientGetPost...") <<  wifi.getLibraryVersion(bufRequest, REQUEST_BUFFER_SIZE) << "  RAM:" << freeMemory() << endl;
  Serial << F("MAC: ") << wifi.getMAC(bufRequest, REQUEST_BUFFER_SIZE) << endl;

  Reconnect();
  
  // Set timezone adjustment: PST is -8h.  Adjust to your local timezone.
  adjustTime( (long) (-8 * 60 * 60) );
  //Serial << F("DateTime:") << year() << "-" << month() << "-" << day() << " " << hour() << ":" << minute() << ":" << second() << endl;

  //Serial << GetBuffer_P(IDX_WT_MSG_WIFI,bufTemp,TEMP_BUFFER_SIZE) << endl  
  //  << F("IP: ") << wifi.getIP(bufRequest, REQUEST_BUFFER_SIZE) << endl
  //  << F("Netmask: ") << wifi.getNetMask(bufRequest, REQUEST_BUFFER_SIZE) << endl
  //  << F("Gateway: ") << wifi.getGateway(bufRequest, REQUEST_BUFFER_SIZE) << endl
  //  << F("DNS: ") << wifi.getDNS(bufRequest, REQUEST_BUFFER_SIZE) << endl 
  //  << F("RSSI: ") << wifi.getRSSI(bufRequest, REQUEST_BUFFER_SIZE) << endl
  //  << F("battery: ") <<  wifi.getBattery(bufRequest, REQUEST_BUFFER_SIZE) << endl;
  
  memset (bufRequest,'\0',REQUEST_BUFFER_SIZE);

  // close any open connections
  wifi.closeConnection();
  //Serial << F("After Setup RAM:") << freeMemory() << endl ;
}


int logSystemData() {
  char bufRequest[REQUEST_BUFFER_SIZE];
  char bufTemp[TEMP_BUFFER_SIZE];
  
  PString strRequest(bufRequest, REQUEST_BUFFER_SIZE);
  
  // Build GET expression
  int fanStatus = 0;
  if(getFansActiveState() == true) fanStatus = 1;
  
  int lightStatus = 0;
  if(getLightsActiveState() == true) lightStatus = 1;
  
  strRequest << F("GET ") << MY_SERVER_GET_URL << F("?temp=") << CURRENT_TEMP << F("&humidity=") << CURRENT_HUMIDITY << F("&fans=") << fanStatus << F("&lights=") << lightStatus
     << F(" HTTP/1.1") << "\n"
     << F("Host: ") << MY_SERVER_GET << "\n"
     << F("Connection: close") << "\n"
     << "\n\n";
  
  //Serial << F("GET request:")  << strRequest <<  endl << F("RAM: ") << freeMemory() << endl;

  // Open connection, then sent GET Request, and display response.
  if (wifi.openConnection( MY_SERVER_GET ) ) {
    wifi <<  (const char*) strRequest << endl; 
    
    // Show server response
    unsigned long TimeOut = millis() + 4000;
    
    /*
    while (  TimeOut > millis() && wifi.isConnectionOpen() ) {
      if (  wifi.available() > 0 ) {
        Serial << (char) wifi.read();
      }
    }
    */
    
    // Force-close connection
    wifi.closeConnection();
  } else {
    // Failed to open connection
    //Serial << GetBuffer_P(IDX_WT_MSG_FAIL_OPEN,bufTemp,TEMP_BUFFER_SIZE) << MY_SERVER_GET << endl;
  }
  
  wifi.setDebugChannel( NULL );
}
