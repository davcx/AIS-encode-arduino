unsigned long lat_to_lat10kmin(float la){
// need to convert27 bits signed data
// lo is longtitude in degree, float
 // Serial.println (la,6);
  unsigned long temp2;
  long temp = la * 600000;// degree convert to min, with unit of 1/10000min
   //Serial.println("float input *600000=");
  // Serial.println (temp);
  // Serial.println (temp,BIN);
  // Serial.println (temp,HEX);
   if (temp < 0)
   { 
    temp=abs(temp);
    temp2=temp & 0x07ffffff;// take 28 bits
    temp2 = ~temp2;
    temp2=temp2+1;
    temp2=temp2 & 0x07ffffff;
  //  Serial.println("neagtive float="); 
 //  Serial.println (temp2);
 //  Serial.println (temp2,BIN);
 //  Serial.println (temp2,HEX);
   return temp2;
    }// end of if
    else
    {
       temp2=temp & 0x07ffffff;// take 28 bits
      //  Serial.println("positive float=");
 //  Serial.println (temp2);
 //  Serial.println (temp2,BIN);
  // Serial.println (temp2,HEX);
   return temp2;
      }// end of else
  
  
  }// end of lon_to_long10kmin

  //==================================================================================================
  unsigned long lon_to_long10kmin(float lo){
// need to convert 28 bits signed data
// lo is longtitude in degree, float
// Serial.println (lo,6);
  unsigned long temp2;
  long temp = lo * 600000;// degree convert to min, with unit of 1/10000min
   //Serial.println("float input *600000=");
  // Serial.println (temp);
  // Serial.println (temp,BIN);
  // Serial.println (temp,HEX);
   if (temp < 0)
   { 
    temp=abs(temp);
    temp2=temp & 0x0fffffff;// take 28 bits
    temp2 = ~temp2;
    temp2=temp2+1;
    temp2=temp2 & 0x0fffffff;
  //  Serial.println("neagtive float="); 
 //  Serial.println (temp2);
 //  Serial.println (temp2,BIN);
 //  Serial.println (temp2,HEX);
   return temp2;
    }// end of if
    else
    {
       temp2=temp & 0x0fffffff;// take 28 bits
      //  Serial.println("positive float=");
 //  Serial.println (temp2);
 //  Serial.println (temp2,BIN);
  // Serial.println (temp2,HEX);
   return temp2;
      }// end of else
  
  
  }// end of lon_to_long10kmin
