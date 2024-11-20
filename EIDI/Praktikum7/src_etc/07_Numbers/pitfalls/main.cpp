//  main.cpp
//  typedMemory

#include <iostream>
#include <iomanip>

using namespace std;

void arithmetic_pitfalls_demo(){
  // 79 percent of 4711
  // bc -le "79/100*4711" gives 3721.69000000000000000000

  int a = 4711;
  int aTimes096 = 79 / 100 * a;
  cout << "a= " << a << " |  79 / 100 * a = " << aTimes096 << endl;


  int b = 4711;
  double bTimes096 = 79 / 100 * b; 
  cout << "b= " << b << " |  79 / 100 * b = " << bTimes096 << endl;
  
  int c = 4711;
  double cTimes096 = 79.0 / 100.0 * c;
  cout << "c = " << c << " |  79.0 / 100.0 * c = " << cTimes096 << endl;
  
  int d = 4711;
  int dTimes096 = d * 79 / 100; 
  cout << "d= " << b << " |  d * 79 / 100 = " << dTimes096 << endl;
    
  
  double e = 10.0;
  while (e >= 0.0){ // e>=0.0,
    cout << "e= " << e << endl;
    e = e - 1.0/3.0;
  }
  

  float s = 123456789.0;
  cout << s << endl;
  cout << (bool)(s==(s+0.0000000001)) << endl;

// round(a+b+c) != round(a) + round(b) + round(c)



}



int main() {
  
  arithmetic_pitfalls_demo();
  
  return 0;
}

