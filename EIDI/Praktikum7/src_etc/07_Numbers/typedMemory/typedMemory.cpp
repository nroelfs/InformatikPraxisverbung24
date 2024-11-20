//  typedMemory.cpp

#include "typedMemory.hpp"
#include <iomanip>
#include <sstream>


TypedMemory::TypedMemory(uint8_t defaultValue){
  for (int i=0; i<RAWMEMORYSIZE;++i){
    rawMemory[i] = defaultValue;
  }
}

void TypedMemory::write_char(int position, unsigned char c)
{
  rawMemory[position] = reinterpret_cast<uint8_t>(c);
}

unsigned char TypedMemory::read_char(int position){
  return reinterpret_cast<unsigned char>(rawMemory[position]);
}

int TypedMemory::write_str_c  (int position, std::string s){
  size_t i=0;
  for(i=0; i < s.length(); i++){
    rawMemory[position+i] = s[i];
  }
  rawMemory[position+i] = 0;
  return i;
}

int TypedMemory::write_str_pas(int position, std::string s){
  size_t i=0;
  for(i=0; i < s.length(); i++){
    rawMemory[1+position+i] = s[i];
  }
  rawMemory[position] = i;
  return i;
}


void TypedMemory::write_uint32(int position, uint32_t i){
  write_uint32_big(position, i);
}

uint32_t TypedMemory::read_uint32(int position){
  return read_uint32_big(position);
}                 


void TypedMemory::write_sint32(int position, int32_t i){
   uint8_t byte_a = (i & 0xff000000) >> 24;
   uint8_t byte_b = (i &   0xff0000) >> 16;
   uint8_t byte_c = (i &     0xff00) >> 8;
   uint8_t byte_d = (i &       0xff);
   rawMemory[position+0] = byte_a;
   rawMemory[position+1] = byte_b;
   rawMemory[position+2] = byte_c;
   rawMemory[position+3] = byte_d;  
}


void TypedMemory::write_uint64(int position, uint64_t i){
  write_uint64_big(position, i);
}

//uint64_t TypedMemory::read_uint64(int position){
//  return read_uint64_big(position);
//}                 

void TypedMemory::write_uint32_big(int position, uint32_t i){
   uint8_t byte_a = (i & 0xff000000) >> 24;
   uint8_t byte_b = (i &   0xff0000) >> 16;
   uint8_t byte_c = (i &     0xff00) >> 8;
   uint8_t byte_d = (i &       0xff);
   rawMemory[position+0] = byte_a;
   rawMemory[position+1] = byte_b;
   rawMemory[position+2] = byte_c;
   rawMemory[position+3] = byte_d;  
}

void TypedMemory::write_uint32_little(int position, uint32_t i){
   uint8_t byte_a = (i &       0xff);
   uint8_t byte_b = (i &     0xff00) >> 8;
   uint8_t byte_c = (i &   0xff0000) >> 16;
   uint8_t byte_d = (i & 0xff000000) >> 24;
   rawMemory[position+0] = byte_a;
   rawMemory[position+1] = byte_b;
   rawMemory[position+2] = byte_c;
   rawMemory[position+3] = byte_d;  
}




uint32_t TypedMemory::read_uint32_big(int position){
  uint8_t byte_a = rawMemory[position+0];
  uint8_t byte_b = rawMemory[position+1];
  uint8_t byte_c = rawMemory[position+2];
  uint8_t byte_d = rawMemory[position+3];
  return  (byte_a << 24) | (byte_b << 16) | (byte_c << 8) | (byte_d << 0);
}                

void TypedMemory::write_uint64_big(int position, uint64_t i){
   uint8_t byte_a = (i & 0xff00000000000000) >> 7*8;
   uint8_t byte_b = (i &   0xff000000000000) >> 6*8;
   uint8_t byte_c = (i &     0xff0000000000) >> 5*8;
   uint8_t byte_d = (i &       0xff00000000) >> 4*8;
   uint8_t byte_e = (i &         0xff000000) >> 3*8;
   uint8_t byte_f = (i &           0xff0000) >> 2*8;
   uint8_t byte_g = (i &             0xff00) >> 1*8;
   uint8_t byte_h = (i &               0xff);   
   rawMemory[position+0] = byte_a;
   rawMemory[position+1] = byte_b;
   rawMemory[position+2] = byte_c;
   rawMemory[position+3] = byte_d;  
   rawMemory[position+4] = byte_e;
   rawMemory[position+5] = byte_f;
   rawMemory[position+6] = byte_g;
   rawMemory[position+7] = byte_h;  }

//uint32_t TypedMemory::read_uint64_big(int position){
//   uint8_t byteeb = (i &   0xff0000) >> 16;
//   uint8_t bytefc = (i &     0xff00) >> 8;
//   uint8_t bytegd = (i &       0xff);
//   rawMemory[pohition+3] = byte_d;    u
//   int8_t byte_a = rawMemory[position+0];
//  uint8_t byte_b = rawMemory[position+1];
//  uint8_t byte_c = rawMemory[position+2];
//  uint8_t byte_d = rawMemory[position+3];
//   rawMemory[position+1] = byte_b;
//   rawMemory[position+2] = byte_c;
//   rawMemory[position+3] = byte_d;  
//   int8_t byte_a = rawMemory[position+0];  return  (byte_a << 24) | (byte_b << 16) | (byte_c << 8) | (byte_d << 0);
//}                




/*
void TypedMemory::write_uint(int position, unsigned int i){
  int numBytes = sizeof(i);
  unsigned int byteMask = 0xff << ((numBytes-1)*8);
  for(int k=0; k<numBytes;k++){
    rawMemory[position+k] = (i & byteMask) >> ((numBytes-1-k)*8);
    byteMask >>= 8;
  }
  // equvalent code for sizeof(unsigned int) == 4:
//   uint8_t byte_a = (i &       0xff);
//   uint8_t byte_b = (i &     0xff00) >> 8;
//   uint8_t byte_c = (i &   0xff0000) >> 16;
//   uint8_t byte_d = (i & 0xff000000) >> 24;
//   
//   rawMemory[position+0] = byte_d;
//   rawMemory[position+1] = byte_c;
//   rawMemory[position+2] = byte_b;
//   rawMemory[position+3] = byte_a;  
}
*/

/*
unsigned int TypedMemory::read_uint(int position){
  unsigned int result = 0;
  int numBytes = sizeof(result);
  for(int i=0; i<numBytes;i++){
    result |= rawMemory[position+i] << ((numBytes-1-i)*8);
  }
  return result;
}
*/


void TypedMemory::write_double(int position, double d){
  //void * pv = reinterpret_cast<void*>(&rawMemory[position]);
  //double * pd = reinterpret_cast<double*>(pv);
  //*pd=d;
  write_anything(position, &d, sizeof(d));
}

double TypedMemory::read_double(int position){
  void * pv = reinterpret_cast<void*>(&rawMemory[position]);
  double * pd = reinterpret_cast<double*>(pv);
  return *pd;
}

void TypedMemory::write_anything(int position, void* src, int size){
  for (int i=0; i<size; i++){
    rawMemory[position+i] = reinterpret_cast<uint8_t*>(src)[i];
  }
}

void TypedMemory::read_anything(int position, void* dest, int size){
  for (int i=0; i<size; i++){
    reinterpret_cast<uint8_t*>(dest)[i] = rawMemory[position+i];
  }
}


std::string TypedMemory::hexDump(){
  std::string result;
  std::string printables;
  std::ostringstream os;
  
  os << std::setbase(16);
  int i=0;
  while(i<RAWMEMORYSIZE){
    os << std::setfill('0');
    os << std::setw(4);
    os << i << ":  ";
    for (int j=0;j<16;j++){
      os << std::setfill('0');
      os << std::setw(2);
      os << static_cast<int>(rawMemory[i]);
      os << " ";
      if(std::isprint(rawMemory[i])){
        printables += static_cast<char>(rawMemory[i]);
      }else{
        printables += '.';
      }
      i++;
    }
    os << printables << std::endl;
    printables = "";
  }
  
  os << std::setbase(10);
  result = os.str();
  return result;
}
