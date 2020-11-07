#pragma once
#include <iostream>


using namespace std;

template <class ValType>
class TVector {
protected:
  ValType *pVector;
  int size; // размер вектора
  int startIndex; // индекс первого элемента вектора
public:
  TVector(int s = 10, int si = 0);
  TVector(const TVector &v); // конструктор копирования
  ~TVector();
  int GetSize() { return size; };// размер вектора
  int GetStartIndex() { return startIndex; }; // индекс первого элемента
  ValType& GetValue(int pos); // доступ с контролем индекса
  ValType& operator[](int pos); // доступ
  bool operator==(const TVector &v); // сравнение
  TVector& operator= (const TVector &v); // присванивание
  // скалярные операции
  TVector operator+ (const ValType &val); // прибавить скаляр
  TVector operator- (const ValType &val); // вычесть скаляр
  TVector operator* (const ValType &val); // умножить на скаляр
  // векторные операции
  TVector operator+ (const TVector &v); // сложение
  TVector operator- (const TVector &v); // вычитание
  ValType operator* (const TVector &v); // скалярное произведение
  // ввод-вывод
  friend istream& operator>>(istream &in, TVector &v) {
    for (int i = 0; i < v.size; ++i)
      in >> v.pVector[i];
    return in;
  }
  friend ostream& operator<<(ostream &out, const TVector &v) {
    for (int i = 0; i < v.size; ++i)
      out << v.pVector[i] << " ";
    return out;
  }
  };