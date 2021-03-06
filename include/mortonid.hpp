/**
 * \file mortonid.hpp
 * \author Dhairya Malhotra, dhairya.malhotra88@gmail.com
 * \date 2-11-2011
 * \brief This file contains definition of the class MortonId.
 */

#ifndef _MORTONID_HPP_
#define _MORTONID_HPP_

#include <pvfmm_common.hpp>
#include <iostream>
#include <stdint.h>
#include <vector>
#ifndef MAX_DEPTH
#define MAX_DEPTH 30
#endif

#if MAX_DEPTH < 7
#define UINT_T uint8_t
#define  INT_T  int8_t
#elif MAX_DEPTH < 15
#define UINT_T uint16_t
#define  INT_T  int16_t
#elif MAX_DEPTH < 31
#define UINT_T uint32_t
#define  INT_T  int32_t
#elif MAX_DEPTH < 63
#define UINT_T uint64_t
#define  INT_T  int64_t
#endif

class MortonId{

 public:

  MortonId();

  MortonId(MortonId m, unsigned char depth);

  template <class T>
  MortonId(T x_f,T y_f, T z_f, unsigned char depth=MAX_DEPTH);

  template <class T>
  MortonId(T* coord, unsigned char depth=MAX_DEPTH);

  unsigned int GetDepth() const;

  template <class T>
  void GetCoord(T* coord);

  MortonId NextId() const;

  MortonId getAncestor(unsigned char ancestor_level) const;

  /**
   * \brief Returns the deepest first descendant.
   */
  MortonId getDFD(unsigned char level=MAX_DEPTH) const;

  void NbrList(std::vector<MortonId>& nbrs,unsigned char level, int periodic) const;

  std::vector<MortonId> Children() const;

  int operator<(const MortonId& m) const;

  int operator>(const MortonId& m) const;

  int operator==(const MortonId& m) const;

  int operator!=(const MortonId& m) const;

  int operator<=(const MortonId& m) const;

  int operator>=(const MortonId& m) const;

  int isAncestor(MortonId const & other) const;

  friend std::ostream& operator<<(std::ostream& out, const MortonId & mid);

 private:

  UINT_T x,y,z;
  unsigned char depth;

};

#include <mortonid.txx>

#endif
