//  typedMemory.hpp

#ifndef typedMemory_hpp
#define typedMemory_hpp
#include <iostream>
#include <stdint.h>

struct TypedMemory {
  static const int RAWMEMORYSIZE=128;//1024;
  uint8_t rawMemory[RAWMEMORYSIZE];
  TypedMemory(uint8_t defaultValue);
  
  void          write_char(int position, unsigned char c); // position in bytes starting at 0
  unsigned char  read_char(int position);

  int           write_str_c  (int position, std::string s);
  int           write_str_pas(int position, std::string s);

  // unsigned
  void          write_uint32(int position, uint32_t i); 
  uint32_t       read_uint32(int position);                 

  // unsigned
  void          write_uint64(int position, uint64_t  i); 
  uint64_t       read_uint64(int position);                 

  // signed
  void          write_sint32(int position, int32_t i); 



  // big endian = network byte order
  // stores the most significant byte of an int at the smallest memory address 
  // (and the least significant byte at the largest address)
  void          write_uint32_big(int position, uint32_t i); 
  uint32_t       read_uint32_big(int position);                 
  void          write_uint64_big(int position, uint64_t i); 
  uint64_t       read_uint64_big(int position);                 

  // little endian
  // used by IA-32 and x86-64 instruction set architectures 
  void          write_uint32_little(int position, uint32_t i); 
  uint32_t       read_uint32_little(int position);                 
  void          write_uint64_little(int position, uint64_t i); 
  uint64_t       read_uint64_little(int position);                 


  void          write_double(int position, double d);
  double         read_double(int position);



  void          write_anything(int position, void* src, int size);
  void           read_anything(int position, void* dest, int size);

  std::string   hexDump();
};

#endif
