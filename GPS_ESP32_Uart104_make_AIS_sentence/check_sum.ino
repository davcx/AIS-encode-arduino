String getCheckSumstring(String s) {
// Checksum berechnen und als int ausgeben
// wird als HEX benötigt im NMEA Datensatz
// Matthias Busse 23.11.2014 Version 1.1
int i, XOR, c;
String checksum;
  for (XOR = 0, i = 0; i < s.length(); i++) {
    c = (unsigned char)s.charAt(i);
    if (c == '*') break;
    if ((c != '!') && (c != '$')) XOR ^= c;
  }
  //return XOR; 
  checksum=String(XOR,HEX);
  return checksum;
}
