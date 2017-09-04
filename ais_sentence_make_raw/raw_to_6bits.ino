void raw_to_6bits(void){
  // here is a little bit tricky, since init values are stored in LSB, so need to carefully arrange them....
 sixbit_payload[0]=type & B00111111;
 // take lower 2 bits of repeat and put them into bit 5,4 then taker bit 29,28,27,26 in mmsi and put them in lower 4 bits
 sixbit_payload[1]=((repeat & B00000011)<<4)+((mmsi & 0x3c000000)>>26);
 //take bit 25~20 form mmsi
 sixbit_payload[2]= ((mmsi & 0x03f00000)>>20);
 //take 19~14 from mmsi
  sixbit_payload[3]= ((mmsi & 0x000fc000)>>14);
//taking 13~8 from mmsi
  sixbit_payload[4]= ((mmsi & 0x3f00)>>8); 
  //taking 7~2 from mmsi
  sixbit_payload[5]= ((mmsi & 0xfc)>>2); 
// taking bit 1~0 from mmsi for bit 5~4, get 3~0 bits from status as bit 3~0
 sixbit_payload[6]=((mmsi & B00000011)<<4)+((statu & B00001111));
//taking bit 7~2 from turn
  sixbit_payload[7]= (turn & B11111100)>>2; 
//taking bit 1~0 from turn as bit 5~4,bit 9~6 from SOG as bit 3~0
   sixbit_payload[8]= ((turn & B00000011)<<4)+((SOG & 0x03c0)>>6); 
// take SOG 5~0
 sixbit_payload[9]= (SOG & 0B00111111); 
//take bit 0 of accuracy as bit 5, and bit 27-23 of lon as bit 4-0
 sixbit_payload[10]= ((accuracy & B00000001)<<5)+((long10kmin & 0x0f800000)>>23); 
// take bit 22~17 form lon
 sixbit_payload[11]= ((long10kmin & 0x7E0000)>>17); 
 // take bit 16~11 form lon
 sixbit_payload[12]= ((long10kmin & 0x01F800)>>11);   
 // take bit 10-5 form lon
 sixbit_payload[13]= ((long10kmin & 0x07E0)>>5);   
// take bit 4-0 form lon as 5-1 and bit26 of lat for bit 0
 sixbit_payload[14]= ((long10kmin & B00011111)<<1)+((lat10kmin & 0x04000000)>>26);   
 //bit25-20 form lat
 sixbit_payload[15]= ((lat10kmin & 0x03F00000)>>20);    
 //bit19-14 form lat
 sixbit_payload[16]= ((lat10kmin & 0x0FC000)>>14);    
//bit13-8 form lat
 sixbit_payload[17]= ((lat10kmin & 0x3F00)>>8);    
 //bit7-2 form lat
 sixbit_payload[18]= ((lat10kmin & 0xFC)>>2);    
// taking bit 1-0 from lat as 5-4 and COG10 11-8 as 3-0
 sixbit_payload[19]= ((lat10kmin & B00000011)<<4)+((COG10 & 0x0F00)>>8);   
//bit7-2 form COG10
 sixbit_payload[20]= ((COG10 & 0xFC)>>2);  
 // taking bit 1-0 from COG10 as 5-4 and heading 8-5 as 3-0
 sixbit_payload[21]= ((COG10 & B00000011)<<4)+((heading & 0x01E0)>>5);   
 // taking bit 4-0 from heading as bit 5-1 and bit 5 of second as bit 0
  sixbit_payload[22]= ((heading & B00011111)<<1)+((sec & B00100000)>>5); 
// taking 4-0 from sec and bit 1 from Maneuver
  sixbit_payload[23]= ((sec & B00011111)<<1)+((maneuver & B00000010)>>1); 
// taking bit 0 from maneuver as bit 5, spare bit 2-0 as bit 4-2, raim bit 0 as bit 1 and sync_state bit 1 as bit 0
  sixbit_payload[24]= (((maneuver & B00000001)<<5)+((spare & B00000111)<<2)+((raim &B00000001)<<1)+((sync_state & B00000010)>>1)) ; 
//take sync_state bit 0 as bit5,slot time_out bit 2~0 as as bit4~2, and bit 4~3 from hours as bit 1~0
 sixbit_payload[25]= (((sync_state & B00000001)<<5)+((slot_time_out & B00000111)<<2)+((hours & B00011000)>>3));
 //take bit 2~0 from hours+6-4 from minutes
 sixbit_payload[26]= (((hours & B00000111)<<3)+((minutes & B01110000)>>4));  
 //bit 3~0 of minutes + 2 bits of rest
 sixbit_payload[27]= (((minutes & B00001111)<<2)+(rest & B00000011));   
  
  }// end of raw to 6 bits
