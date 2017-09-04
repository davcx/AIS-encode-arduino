
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
// 265547250
// statu=0;
//SOG=139;
//Longitude: 11 Grad 49.9786 Minuten=11.8329766
//Latitude: 57 Grad 39.6211 Minuten= 57.6603516
//COG: 40.4
//Heading: 41

void init_values(void){
type=1;
repeat=0;
mmsi=265547250;
statu=0;
turn=128;
SOG=139;// in unit of 1/10 degree, x10
accuracy=1;
// long and lat should be feed in hex form, after convert to 28/27 signed int
long10kmin=lon_to_long10kmin(11.8329766);
lat10kmin=lat_to_lat10kmin(57.6603516);
COG10=404;// in unit of 1/10 degree
heading=41;//0-359, 511 means not available
sec=40;
maneuver=0;
spare=0;
raim=0;
sync_state=0;// UTC direct
slot_time_out=1;// sub message is UTC hours and minutes
hours=18;
minutes=5;
rest=0;// bit 1~0 of radio(bit 166 and 167)   
}// end of init_values
