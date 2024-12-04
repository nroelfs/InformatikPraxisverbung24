// file float_int_pitfalls.groovy

def polynom1(x) {
  return  ( x - 1.0 ) * ( x - 3.0 ) * ( x - 5.0 ) // returns 0.0 on x = 1.0, 3.0, 5.0
}

def comp(float x_start, float x_end, float x_delta){
    x = x_start
    while ( x != x_end ) {
      println("x=" + x + "  y=" +  polynom1(x));
      x += x_delta
    }
}


def int tax1(int gross){
  int prod = gross * 19
  return prod / 100
}

def int tax2(int gross){
  // return gross / 100 * 19
  int deci = gross / 100
  return  deci * 19
}


comp(0.0, 10.0, 1.0)
//comp(0.0, 10.0, 0.1)

println(tax1(10) + " " + tax2(10))
println(tax1(100) + " " + tax2(100))
println(tax1(1000000000) + " " + tax2(1000000000))
println(tax1(2000000000) + " " + tax2(2000000000))



def double tax1_fixed(double gross){
  double prod = gross * 19.0
  return prod / 100.0
}

def double tax2_fixed(double gross){
  // return gross / 100 * 19
  double deci = gross / 100.0
  return  deci * 19.0
}

println("\n-----------------------\nTax_fixed\n")
println(tax1_fixed(10) + " " + tax2_fixed(10))
println(tax1_fixed(120) + " " + tax2_fixed(120))
println(tax1_fixed(1000000000) + " " + tax2_fixed(1000000000))
println(tax1_fixed(2000000000) + " " + tax2_fixed(2000000000))


