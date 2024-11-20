// file src_etc/07_Numbers/conversions2.groovy

// convert int to corresponding ASCII char 
// (hence "i2c"; i to c; int to char)
// e.g. 0 to '0'
def i2c (int digit_value){
  return Character.forDigit(digit_value, 10)
}

int n = 48879;
int k = n;
int Base = 10;
String result = "";
while (k>0) {
  int digit = k % Base;
  println(k + " " + digit);
  result = "" + i2c(digit) + result;
  k /= Base;
}
println("converted n= >" + n + "<   to   >" + result + "<");
