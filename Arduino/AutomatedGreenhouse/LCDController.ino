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
 * LCD Controller
 * 
 * Sparkfun LCD Serial Backpack on a standard 16x2 LCD display.
 *
 * Serial Enabled LCD Backpack - https://www.sparkfun.com/products/258
 * Basic 16x2 Character LCD - RGB Backlight 5V - https://www.sparkfun.com/products/10862
 */

boolean CUSOTOM_MESSAGE_DISPLAYED = false;
int CUSTOM_MESSAGE_TIMER = 0;
int LCD_DISPLAY_INTERVAL = 0;

/**
 * Displays a custom message on the LCD screen.
 *
 * @param  line1: The first line of text (16 chars).
 * @param  line2: The second line of text (16 chars).
 * @param  customMessage: Flag if this is a custom message or not.
 * @param  displayTime: The interval count of display time for the message.
 */
void displayLCDMessage(char* line1, char* line2, boolean customMessage, int displayTime) {
  // Check if custom message params are set.
  if(customMessage == true) {
    CUSOTOM_MESSAGE_DISPLAYED = true;
    CUSTOM_MESSAGE_TIMER = displayTime;
  }
  
  displayLCDMessage(line1, line2);
}

/**
 * Displays a message on the LCD screen.
 *
 * @param  line1: The first line of text (16 chars).
 * @param  line2: The second line of text (16 chars).
 */
void displayLCDMessage(char* line1, char* line2) {
  // Ignore the command if the LCD display is disabled
  if(LCD_ENABLED == false) {
    return; 
  }
  
  // Clear the LCD before adding any new messages.
  clearLCD();
  
  selectLineOne();
  Serial1.print(line1);
  selectLineTwo();
  Serial1.print(line2);
  delay(100);
}

/**
 * Clears the LCD.
 */
void clearLCD() {
  Serial1.write(0xFE);
  Serial1.write(0x01);
  delay(10);

}

/**
 * Selects LCD line one for printing.
 */
void selectLineOne() {
  Serial1.write(0xFE);
  Serial1.write(128);
  delay(10);
}

/**
 * Selects LCD line two for printing.
 */
void selectLineTwo() {
  Serial1.write(0xFE);
  Serial1.write(192);
  delay(10);
}

/**
 * Turns the LCD backlight on.
 */
void turnLCDBacklightOn(){
  Serial1.write(0x7C);      // Command flag for backlight stuff
  Serial1.write(157);       // Light level.
  delay(10);
}

/**
 * Turns the LCD backlight off.
 */
void turnLCDBacklightOff(){
  Serial1.write(0x7C);       // Command flag for backlight stuff
  Serial1.write(128);        // Light level for off.
  delay(10);
}

/**
 * Called on system loop to update the LCD display with current
 * system data.
 */
void updateLCDDisplay() {
  // Skip if custom message set, skip this process.
  if(CUSOTOM_MESSAGE_DISPLAYED == true) {
    if(CUSTOM_MESSAGE_TIMER > 0) {
      CUSTOM_MESSAGE_TIMER--;
      return;
    } else {
      CUSOTOM_MESSAGE_DISPLAYED = false;
    }
  }
  
  switch(LCD_DISPLAY_INTERVAL) {
    case 0: 
    {
      // Temperature
      char n[16];
      sprintf(n, "Temp: %d\337C", CURRENT_TEMP);
      
      // Humidity
      char m[16];
      sprintf(m, "Humididy: %d%s", CURRENT_HUMIDITY, "%");
      
      displayLCDMessage(n, m);
    }
    break;
    
    case 4:
    {
      // Fans & Lighting Systems
      char* fanInfo;
      if(getFansActiveState() == true) {
        fanInfo = "Fans: Active";
      } else {
        fanInfo = "Fans: Deactive";
      }
   
      // Lights
      char* lightInfo;
      if(getLightsActiveState() == true) {
        lightInfo = "Lights: Active";
      } else {
        lightInfo = "Lights: Deactive";
      }
      
      displayLCDMessage(lightInfo, fanInfo);
    }
    break;
    
    case 8:
    {
      // Current time & date
      char date[16];
      sprintf(date, "Date: %d/%d/%d", CURRENT_DATE[0], CURRENT_DATE[1], CURRENT_DATE[2]);
      
      char time[16];
      sprintf(time, "Time: %d:%d:%d", CURRENT_TIME[0], CURRENT_TIME[1], CURRENT_TIME[2]);
      
      displayLCDMessage(date, time);
    }
    break;
  }
  
  delay(10);
  
  LCD_DISPLAY_INTERVAL++;
  
  if(LCD_DISPLAY_INTERVAL == 12) LCD_DISPLAY_INTERVAL = 0;
}
