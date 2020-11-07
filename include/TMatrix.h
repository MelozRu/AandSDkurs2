#pragma once

#include "TVector.h"

template <class ValType>
class TMatrix : public TVector<TVector<ValType>>
{
public:
  TMatrix(int s = 10);
  TMatrix(const TMatrix &mt); // копирование
  TMatrix(const TVector<TVector<ValType> > &mt); // преобразование типа
  bool operator==(const TMatrix &mt); // сравнение
  TMatrix& operator= (const TMatrix &mt); // присваивание
  TMatrix operator+ (const TMatrix &mt); // сложение
  TMatrix operator- (const TMatrix &mt); // вычитание
  TMatrix operator* (const TMatrix &mt); // умножение
  // ввод / вывод
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