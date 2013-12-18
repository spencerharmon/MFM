#ifndef BITFIELD_H
#define BITFIELD_H

#include "SDL/SDL.h"
#include <stdio.h>

/* 
 * Try to make this a multiple of 32. Otherwise
 * there will be some wasted space.
 */
template <int bitLength>
class BitField
{
private:
  Uint32 m_bits[bitLength >> 5];

  Uint32 MakeMask(int pos, int len);

  void WriteBit(int idx, bool bit);

  bool ReadBit(int idx);
public:

  BitField();

  BitField(Uint32* values);

  Uint32 Read(int startIdx, int length);

  void Write(int startIdx, int length, Uint32 value);

  void Print(FILE* ostream);
			   
};

#include "bitfield.tcc"

#endif /*BITFIELD_H*/
