
#include "TMatrix.h"
template class TMatrix<int>;

template <class ValType>
TMatrix<ValType>::TMatrix(int s) : TVector<TVector<ValType>>(s) {
  int i;
  for (i = 0; i < s; ++i)
    (*this).pVector[i] = TVector<ValType>(s-i, i); 
}

template <class ValType>
TMatrix<ValType>::TMatrix(const TMatrix &mt) : TVector<TVector<ValType>>(mt) {}

template <class ValType>
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> > &mt) :
  TVector<TVector<ValType>>(mt) {}

template <class ValType>
bool TMatrix<ValType>::operator==(const TMatrix<ValType> &mt) {
  bool res = false;
  int i;
  if (this->size != mt.size || this->startIndex != mt.startIndex)
    return res;
  for (i = 0; i < mt.size; ++i)
    if (!(this->pVector[i] == mt.pVector[i]))
      return res;
  res = true;
  return res;
}

template <class ValType>
TMatrix<ValType>& TMatrix<ValType>::operator= (const TMatrix<ValType> &mt) {
  if (!(*this == mt)) {
    int i;
    if (!(this->size == mt.size)) {
      (*this).size = mt.size;
      (*this).startIndex = mt.startIndex;
    }
    for (i = 0; i < this->size; ++i)
      (*this).pVector[i] = mt.pVector[i];
  }
  return *this;
}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator+ (const TMatrix &mt) {
  TMatrix<ValType> tmp(*this);
  int i;
  for (i = 0; i < tmp.size; ++i)
    tmp[i] = this->pVector[i] + mt.pVector[i];
  return tmp;
}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator- (const TMatrix &mt) {
  TMatrix<ValType> tmp(*this);
  int i;
  for (i = 0; i < tmp.size; ++i)
    tmp[i] = this->pVector[i] - mt.pVector[i];
  return tmp;
}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator* (const TMatrix &mt) {
  TMatrix<ValType> tmp(this->GetSize());
  int i, j, k;
  for (i = 0; i < tmp.size; ++i)
    for (j = i; j < tmp.size; ++j)
      for (k = i; k < j + 1; ++k)
        tmp[i][j] += this->pVector[i][k] * mt.pVector[k][j];
  return tmp;
}

