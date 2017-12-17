char sixbit_to_8bit(byte s){
  s += 48;
  if (s > 87){s += 8;}
  return s ;
  }// end of six
