# AIS-encode-arduino
to make a sentience of AIS type 1 

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
