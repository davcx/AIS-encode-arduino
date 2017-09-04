/*
target is to get a valid AIS sentence
For example: a AVIDM sentence may look like this:one sentence is 82 char max.
!AIVDM,1,1,,B,177KQJ5000G?tO`K>RA1wUbN0TKH,0*5C

so there are 7 fields separated by  , :
field 1:!AIVDM
field 2:1        count of fragments
field 3:1        fragment Nr
field 4: empty            sequential message ID for multi-sentence messages.
field 5: B        channel B
field 6: 177KQJ5000G?tO`K>RA1wUbN0TKH  payload
field 7: 0*5C     XOR check sum after ! until end of payload


the out come of this messge is : 
!AIVDM,1,1,,B,13u?etPP2;Pn:dDPwUM1U1C@2D7k,0*12

I put it into a online decoder: http://www.aggsoft.com/ais-decoder.htm

thr result of ID, SOG,COG,headingtime stamp are correct.
radio has be detailed into sync state, slot time out, hours, minutes tested good

/*
information fix:
mmsi=123456789
statu=0
type=1
repeat=0
turn=?
accuracy=1
maneuver=0;
spare=0;
raim=0;
sync_state=0;// UTC direct
slot_time_out=1;// sub message is UTC hours and minutes
rest=0;// bit 1~0 of radio(bit 166 and 167)  
heading=41;//0-359, 511 means not available
===============info to be got from GPS==================================

long10kmin=lon_to_long10kmin(11.8329766);
lat10kmin=lat_to_lat10kmin(57.6603516);
COG10=404;// in unit of 1/10 degree
SOG=139;// in unit of 1/10 degree, x10
hours=18;
minutes=5;
sec=40;

*/












//===========declair for payload assembly======================
unsigned int type,repeat,statu,SOG,COG10,heading;
unsigned long mmsi;
byte accuracy,maneuver,spare,raim,sec,turn;
byte sync_state, slot_time_out, hours,minutes,rest;
unsigned long long10kmin,lat10kmin,radio;
byte sixbit_payload[28];
char ASCII_payload[28];
String str_payload="";
//================declair for final message=======================
String header ="!AIVDM,";
String count="1,";
String frag_nr="1,";
String fourth=",";
String channel="B,";

String star=",0*";

String message="";
String message_no_chk="";


void setup() {
  Serial.begin(9600);
  while (!Serial) ;
 //----------------some fix values----------------------------
init_values();
//------print init value in binary-----------
 // print_data_bin();
//------put init value in to 6bit, then 6bits to 8 bits and form a string-------------
raw_to_6bits();
 for (int i=0; i < 28; i++){
 ASCII_payload[i] = sixbit_to_8bit(sixbit_payload[i]);
// Serial.print( ASCII_payload[i]);
 str_payload += ASCII_payload[i];
 }// end of for i 




  
//Serial.println(header);
//Serial.println(count);
//Serial.println(header+count+frag_nr+fourth+channel+payloadstr+star+checksum);  
//message=header+count+frag_nr+fourth+channel+payloadstr+star+checksum;
message_no_chk=header+count+frag_nr+fourth+channel+str_payload+star;
//message=header+count+frag_nr+fourth+channel+str_payload+star+checksum;
//Serial.println(message_no_chk);
message=header+count+frag_nr+fourth+channel+str_payload+star+ getCheckSumstring(message_no_chk);
Serial.println(message);
}

void loop() {
  // put your main code here, to run repeatedly:

}
