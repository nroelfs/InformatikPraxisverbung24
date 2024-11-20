// file src_etc/07_Numbers/conversions0.groovy

String s ="48879";
chars    = s.toCharArray();
int result = 0;
int base = 10;
for (int i = 0; i < chars.length; i++){
  result *= base;
  char c = chars[i];
  int v  = Character.getNumericValue(c);
  result += v;
  println("i=" + i + ":   char c=" + c + "   int v=" + v + "    " + "result=" + result); 
}
println(" converted s=>" + s + "< to >" + result + "<");
