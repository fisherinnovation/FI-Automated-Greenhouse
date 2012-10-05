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
 * Reads the DS1307 Clock Module.
 */
void readDS1307() {
  DateTime now = RTC.now();
  
  CURRENT_DATE[0] = now.year();
  CURRENT_DATE[1] = now.month();
  CURRENT_DATE[2] = now.day();
  
  CURRENT_TIME[0] = now.hour();
  CURRENT_TIME[1] = now.minute();
  CURRENT_TIME[2] = now.second();
}
