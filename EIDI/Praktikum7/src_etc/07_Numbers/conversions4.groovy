// file src_etc/07_Numbers/conversions4.groovy

// convert int to corresponding ASCII char
// (hence "i2c"; i to c; int to char)
// e.g. 0 to '0'
def i2c (int digit_value){
  return Character.forDigit(digit_value, 10)
}

def i2hc (int digit_value){
  return Character.forDigit(digit_value, 16)
}

def intToHex(int decimal) {
    return Integer.toHexString(decimal)
}
int n = 48879;
int k = n;
int o = n;
String result = "";
String resHex = "";

while (k>0) {
  int digit = k % 10;
  println(k + " " + digit);
  result = "" + i2c(digit) + result;
  k /= 10;
}

while (o > 0) {
  int dig = o % 16;
  println(o + " " + dig);
  resHex = "" + i2hc(dig) + resHex;
  o /= 16;
}


println("converted n= >" + n + "<   to   >" + result + "<");
println("Hex: ${n} -> Decimal: ${intToHex(n)}"); // ez way to convert to hex
println("converted n= >" + n + "<   to   > " + resHex + " <");