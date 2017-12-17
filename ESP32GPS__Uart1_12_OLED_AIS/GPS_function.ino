void initGPSInfo()
{
 
  if (gps.location.isValid())
  {
    latD = gps.location.lat();
    lonD = gps.location.lng();
    Hdop100=gps.hdop.value();
  }
  else
  {
    latD = 0.;
    lonD = 0.;
    Serial.println("No location info");
    display_OLED(0);
  }
// getting sec,minutes,hours
  if (gps.time.isValid())
  {
    hours= gps.time.hour();
    minutes= gps.time.minute();
    sec= gps.time.second();
 
  }
  else
  {
   hours= 0;
    minutes= 0;
    sec= 0;
  }
//getting SOG10 and COG10
  if (gps.speed.isValid())
  {
    SOG10 = gps.speed.knots()*10;
     }
  else
  {
   SOG10;
  }
    if (gps.course.isValid())
  {
    COG10 = gps.course.deg()*10;
     }
  else
  {
   COG10;
  }

}// end of init info

//check gps
void check_gps(void){
    if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    display_OLED(0);
    while(true);
  }
  
  
  }// end of check GPS
