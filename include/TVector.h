#pragma once
#include <iostream>


using namespace std;

template <class ValType>
class TVector {
protected:
  ValType *pVector;
  int size; // ������ �������
  int startIndex; // ������ ������� �������� �������
public:
  TVector(int s = 10, int si = 0);
  TVector(const TVector &v); // ����������� �����������
  ~TVector();
  int GetSize() { return size; };// ������ �������
  int GetStartIndex() { return startIndex; }; // ������ ������� ��������
  ValType& GetValue(int pos); // ������ � ��������� �������
  ValType& operator[](int pos); // ������
  bool operator==(const TVector &v); // ���������
  TVector& operator= (const TVector &v); // �������������
  // ��������� ��������
  TVector operator+ (const ValType &val); // ��������� ������
  TVector operator- (const ValType &val); // ������� ������
  TVector operator* (const ValType &val); // �������� �� ������
  // ��������� ��������
  TVector operator+ (const TVector &v); // ��������
  TVector operator- (const TVector &v); // ���������
  ValType operator* (const TVector &v); // ��������� ������������
  // ����-�����
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