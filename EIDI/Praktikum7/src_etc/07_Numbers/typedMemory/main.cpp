//  main.cpp
//  typedMemory

#include <iostream>
#include <iomanip>
#include "typedMemory.hpp"





int main() {
  TypedMemory mem(0xcc); // default memory value
  
  mem.write_char(0,'A');
  mem.write_char(1,'a');
  mem.write_char(2,'0');
  mem.write_char(3,'9');
  mem.write_str_c(4,"hello");
  mem.write_str_pas(10,"hello");
  mem.write_uint32(0x20, 0x41312111);
  mem.write_uint64(0x30, 0x8171615141312111);
  mem.write_sint32(0x40, -2);

  //mem.write_uint32_little(0x40, 0x41312111);
  //mem.write_uint64_little(0x50, 0x41312111);


  //mem.write_double(0x60, 1.0 /*355.0/113.0*/);
  //mem.write_double(0x70, 355.0/113.0);
 
  
  std::cout << mem.hexDump() << std::endl;
  
  return 0;
}




/* this illustrates that what the compiler needs to do
 to store local variables in the stack frame. Compare
 this to the code in main().*/
/*void foobar(){
  unsigned int x  = 0x04030201;
  char c1         = 'C';
  char c2         = '+';
  char c3         = '+';
  char c4         = '!';
  double d1       = 16.0;
  compund k1      = {0x04030201, 16.0};
  compund k2      = {0, 0.0};
}*/


  /*


struct compund {
  int theInt;
  double theDouble;
};

  compund a = {0x48382818, 16.0};
  mem.write_anything(0x50, &a, sizeof(compund));
  compund b = {0, 0.0};
  mem.getAnything(0x20, &b, sizeof(compund));
  std::cout << "a = (0x" << a.theInt << ", " << a.theDouble << ")" << std::endl;
  std::cout << "b = (0x" << b.theInt << ", " << b.theDouble << ")" << std::endl;
  std::cout << std::setbase(10);
  */
  

  /*
  std::cout << std::setbase(16);
  std::cout << "0x" << mem.getUInt(0) << std::endl;
  std::cout << mem.getChar(4)
            << mem.getChar(5)
            << mem.getChar(6)
            << mem.getChar(7) << std::endl;
  std::cout << "0x" << mem.getUInt(4) << std::endl;
  std::cout << mem.getDouble(0x30) << " (" << sizeof(double) << " bytes)" << std::endl;
  */
  

/*
struct RGB {
  uint8_t r;
  uint8_t g;
  uint8_t b;
};


  RGB rgb = {0x33, 0x44, 0x55};
  mem.write_anything(0x60, &rgb, sizeof(rgb));


*/



