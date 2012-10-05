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

const char *COMMANDS[] = {"help", "test", "lights", "fans"};
const int COMMAND_AMOUNT = 5;
const int SERIAL_BUFFER_SIZE = 100;

char serialBuffer[SERIAL_BUFFER_SIZE];
int serialDataLength = 0;

/**
 * Checks for system input from a serial connection.
 */
void checkSerialInput() {
  // Serial receive buffer (holds 64 bytes)
  if(Serial.available() > 0) {
    serialBuffer[serialDataLength] = Serial.read();
    int serialBytes = serialBuffer[serialDataLength];
    
    // Check for carriage return.
    if(serialBytes == 13) {
      parseSerialInput(serialBuffer); // Parse the input.
    } else {
      serialDataLength++; 
    }
  }
}

/**
 * Parses serial input.
 *
 * @param  serialData: The Serial data submitted.
 */
void parseSerialInput(char serialData[]) {
  char command[serialDataLength];
  
  int i;
  for(i = 0; i < serialDataLength; i++) {
    command[i] = serialData[i];
  }
  command[i] = '\0';
  
  serialDataLength = 0;
  
  runCommand(command);
}

/**
 * Validates a command. Returns a boolean of success.
 *
 * @param  command: The Serial command.
 */
boolean validateCommand(char command[]) {
  int valid = 0;
  
  for(int i = 0; i < COMMAND_AMOUNT; i++) {
    int comp = strcmp(command, COMMANDS[i]);
    
    if(comp == 0) {
      return true; 
    }
  }
  
  return false;
}

/**
 * Runs a validated command.
 *
 * @param  command: The Serial command.
 */
void runCommand(char command[]) {
  Serial.print("> COMMAND: ");
  Serial.println(command);
  
  // Help
  if(String(command) == String("help")) {
    displayHelpInformation();
  }
  
  // Lights on
  if(String(command) == String("lights on")) {
    turnLightsOn();  
  }
  
  // Lights off
  if(String(command) == String("lights off")) {
    turnLightsOff();  
  }
  
  // Fans on
  if(String(command) == String("fans on")) {
    turnFanOn();  
  }
  
  // Fans off
  if(String(command) == String("fans off")) {
    turnFanOff();  
  }
  
  // Get Time
  if(String(command) == String("time")) {
    displayLCDMessage("", "", true, 500);
    readDS1307();
  }
  
  // Get Temperature
  if(String(command) == String("temp")) {
    Serial.print("Temperature: ");
    Serial.println(CURRENT_TEMP, DEC);
  }
  
  // Get Humidity
  if(String(command) == String("humidity")) {
    Serial.print("Humidity: ");
    Serial.println(CURRENT_HUMIDITY, DEC);
  }
}

/**
 * Displays the help information for this controller.
 */
void displayHelpInformation() {
  Serial.println("--------------------------------------------------------");
  Serial.println("Fisher Innovation - Automated Greenhouse");
  Serial.println("Created By: Matt Fisher <fisher.matt@gmail.com>");
  Serial.println("https://github.com/fisherinnovation/Automated-Greenhouse");
  Serial.println("--------------------------------------------------------");
  Serial.println("");
  Serial.println("help = Displays this dialog.");
  Serial.println("fans = Turns the fan system on or off.");
  Serial.println("lights = Turns the light system on or off.");
  Serial.println("time = Displays the current time on the system.");
  Serial.println("date = Displays the current date on the system.");
}
