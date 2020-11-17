
#include "TVector.h"

template class TVector<int>;
template class TVector <TVector<int>>;

template <class ValType>
TVector<ValType>::TVector(int s, int si) {
  pVector = new ValType[s];
  for (int i = 0; i < s; ++i)
    pVector[i] = 0;
  startIndex = si;
  size = s;
}

template <class ValType>
TVector<ValType>::TVector(const TVector &v) {
  int i;
  pVector = new ValType[v.size];
  size = v.size;
  startIndex = v.startIndex;
  for (i = 0; i < size; ++i)
    pVector[i] = v.pVector[i];
}

template <class ValType>
TVector<ValType>::~TVector() {
  delete[] pVector;
}

template <class ValType>
ValType& TVector<ValType>::GetValue(int pos) {
  if (pos < 0) 
    throw logic_error("Input error: index cannot be negative value.");
  if (startIndex > pos)
    throw out_of_range("Input error: index is out of range, less then start index.");
  if (pos >= size + startIndex)
    throw out_of_range("Input error: index is out of range, more then size.");
  return pVector[pos - startIndex];
}

template <class ValType>
ValType& TVector<ValType>::operator[](int pos) {
  return pVector[pos - startIndex];
}

template <class ValType>
bool TVector<ValType>::operator==(const TVector &v) {
  bool res = false;
  int i;
  if (size != v.size || startIndex != v.startIndex)
    return res;
  for (i = 0; i < size; ++i)
    if (!(pVector[i] == v.pVector[i]))
      return res;
  res = true;
  return res;
}

template <class ValType>
TVector<ValType>& TVector<ValType>::operator=(const TVector &v) {
  if (this != &v) {
    int i;
    if (size != v.size) {
      delete pVector;
      pVector = new ValType[v.size];
      size = v.size;
    }
    startIndex = v.startIndex;
    for (i = 0; i < size; ++i)
      pVector[i] = v.pVector[i];
  }
  return *this;
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator+(const ValType &val) {
  TVector<ValType> tmp(size, startIndex);
  int i;
  for (i = 0; i < size; ++i)
    tmp.pVector[i] = pVector[i] + val;
  return tmp;
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator-(const ValType &val) {
  TVector<ValType> tmp(size, startIndex);
  int i;
  for (i = 0; i < size; ++i)
    tmp.pVector[i] = pVector[i] - val;
  return tmp;
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator*(const ValType &val) {
  TVector<ValType> tmp(size, startIndex);
  int i;
  for (i = 0; i < size; ++i)
    tmp.pVector[i] = pVector[i] * val;
  return tmp;
}


template <class ValType>
TVector<ValType> TVector<ValType>::operator+(const TVector &v) {
  TVector<ValType> tmp(size, startIndex);
  int i;
  for (i = 0; i < size; ++i)
    tmp.pVector[i] = pVector[i] + v.pVector[i];
  return tmp;
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator-(const TVector &v) {
  TVector<ValType> tmp(size, startIndex);
  int i;
  for (i = 0; i < size; ++i)
    tmp.pVector[i] = pVector[i] - v.pVector[i];
  return tmp;
}

template <class ValType>
ValType TVector<ValType>::operator*(const TVector &v) {
  ValType tmp = 0;
  int i;
  for (i = 0; i < size; ++i)
    tmp = tmp + pVector[i] * v.pVector[i];
  return tmp;
}
