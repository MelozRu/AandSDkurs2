#pragma once

#include "TVector.h"

template <class ValType>
class TMatrix : public TVector<TVector<ValType>>
{
public:
  TMatrix(int s = 10);
  TMatrix(const TMatrix &mt); // �����������
  TMatrix(const TVector<TVector<ValType> > &mt); // �������������� ����
  bool operator==(const TMatrix &mt); // ���������
  TMatrix& operator= (const TMatrix &mt); // ������������
  TMatrix operator+ (const TMatrix &mt); // ��������
  TMatrix operator- (const TMatrix &mt); // ���������
  TMatrix operator* (const TMatrix &mt); // ���������
  // ���� / �����
  friend istream& operator>>(istream &in, TMatrix &mt) {
    for (int i = 0; i < mt.size; ++i)
      in >> mt.pVector[i];
    return in;
  }
  friend ostream & operator<<(ostream &out, const TMatrix &mt) {
    for (int i = 0; i < mt.size; i++)
      out << mt.pVector[i] << endl;
    return out;
  }
};