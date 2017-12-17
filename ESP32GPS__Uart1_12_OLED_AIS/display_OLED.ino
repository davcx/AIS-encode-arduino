void display_OLED(byte page){
  
  switch(page) {
    case 0:
       // clear the display
       display.clear();
       display.setFont(ArialMT_Plain_10);
        //display.setTextAlignment(TEXT_ALIGN_CENTER);
        display.setTextAlignment(TEXT_ALIGN_LEFT);
        display.drawStringMaxWidth(0, 0, 128, "No GPS detected: check wiring.");    
        display.display();
    break;
    case 1:
    
     Serial.println("status_display_1");
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 0, "Hello world");
    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 10, "Hello world");
    display.setFont(ArialMT_Plain_24);
    display.drawString(0, 26, "Hello world");
    display.display();
    break;
    case 2:
    break;
    case 3:
    break;    
 
    }// end of switch
  
  
  
  
  
  }// end of display
