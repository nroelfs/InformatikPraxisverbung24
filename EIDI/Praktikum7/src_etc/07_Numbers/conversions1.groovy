// file src_etc/07_Numbers/conversions1.groovy

// convert ASCII char to corresponding int 
// (hence "c2i"; c to i; char to int)
// e.g. '0' to 0
def c2i (char digit_char){
  return Character.getNumericValue(digit_char)
}

String s ="48879";
chars    = s.toCharArray();
int result = 0;
int factor = 1;
int base = 10;
for (int i = chars.length-1; i >=0 ; i--){
  char c = chars[i];
  int v  = c2i(c);
  result = result + factor * v;
  println("i=" + i + "   char c=" + c + "   int v=" + v + "   factor=" + factor  + "  result=" + result); 
  factor *= base;
}
println(" converted s=>" + s + "< to >" + result + "<");
