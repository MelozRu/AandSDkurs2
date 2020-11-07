#define TES
#ifdef TEST
#include <iostream>
#include "TMatrix.h"
using namespace std;

int main() {
  // 1. TVector tests
  {
    cout << "TVector tests:" << endl;
    TVector<int> vec0;
    cout << "Test  1. vec0.GetSize(). Expected: " << 10 << ", actual: " << vec0.GetSize() << endl;
    cout << "Test  2. vec0.GetStartIndex(). Expected: " << 0 << ", actual: " << vec0.GetStartIndex() << endl;
    TVector<int> vec1(5);
    cout << "Test  3. vec1.GetSize(). Expected: " << 5 << ", actual: " << vec1.GetSize() << endl;
    cout << "Test  4. vec1.GetStartIndex(). Expected: " << 0 << ", actual: " << vec1.GetStartIndex() << endl;
    TVector<int> vec2(5, 2);
    cout << "Test  5. vec2.GetSize(). Expected: " << 5 << ", actual: " << vec2.GetSize() << endl;
    cout << "Test  6. vec2.GetStartIndex(). Expected: " << 2 << ", actual: " << vec2.GetStartIndex() << endl;
    for (int i = vec1.GetStartIndex(); i < vec1.GetStartIndex() + vec1.GetSize(); i++) {
      vec1[i] = i - vec1.GetStartIndex();
    }
    for (int i = vec2.GetStartIndex(); i < vec2.GetStartIndex() + vec2.GetSize(); i++) {
      vec2[i] = i - vec2.GetStartIndex();
    }
    cout << "Test  7. vec1 == vec2. Expected: " << false << ", actual: " << (vec1 == vec2) << endl;
    vec1 = vec2;
    cout << "Test  8. vec1 == vec2. Expected: " << true << ", actual: " << (vec1 == vec2) << endl;
    TVector<int> vec3(vec2);
    cout << "Test  9. vec3 == vec2. Expected: " << true << ", actual: " << (vec3 == vec2) << endl;

    bool exception_caught_0 = false;
    try { vec2.GetValue(1); }
    catch (...) { exception_caught_0 = true; }
    cout << "Test 10. vec2.GetValue(1) exception. Expected: " << true << ", actual: " << exception_caught_0 << endl;

    bool exception_caught_1 = false;
    try { vec2.GetValue(2); }
    catch (...) { exception_caught_1 = true; }
    cout << "Test 11. vec2.GetValue(2) exception. Expected: " << false << ", actual: " << exception_caught_1 << endl;

    bool exception_caught_2 = false;
    try { vec2.GetValue(6); }
    catch (...) { exception_caught_2 = true; }
    cout << "Test 12. vec2.GetValue(6) exception. Expected: " << false << ", actual: " << exception_caught_2 << endl;

    bool exception_caught_3 = false;
    try { vec2.GetValue(7); }
    catch (...) { exception_caught_3 = true; }
    cout << "Test 13. vec2.GetValue(7) exception. Expected: " << true << ", actual: " << exception_caught_3 << endl;

    cout << "Test 14. Print vec2." << endl
      << "Expected: 0 1 2 3 4" << endl
      << "Actual:   " << vec2 << endl;

    cout << "Test 15. vec2 + 2." << endl
      << "Expected: 2 3 4 5 6" << endl
      << "Actual:   " << vec2 + 2 << endl;

    cout << "Test 16. vec2 - 2." << endl
      << "Expected: -2 -1 0 1 2" << endl
      << "Actual:   " << vec2 - 2 << endl;

    cout << "Test 17. vec2 * 2." << endl
      << "Expected: 0 2 4 6 8" << endl
      << "Actual:   " << vec2 * 2 << endl;

    cout << "Test 18. vec2 + vec2." << endl
      << "Expected: 0 2 4 6 8" << endl
      << "Actual:   " << vec2 + vec2 << endl;

    cout << "Test 19. vec2 - vec2." << endl
      << "Expected: 0 0 0 0 0" << endl
      << "Actual:   " << vec2 - vec2 << endl;

    cout << "Test 20. vec2 * vec2. Expected: " << 30 << ", actual: " << vec2 * vec2 << endl;
  }

  cout << endl;

  // 2. TMatrix tests
  {
    cout << "TMatrix tests:" << endl;
    TMatrix<int> mat0;
    cout << "Test  1. mat0.GetSize(). Expected: " << 10 << ", actual: " << mat0.GetSize() << endl;
    cout << "Test  2. mat0.GetStartIndex(). Expected: " << 0 << ", actual: " << mat0.GetStartIndex() << endl;
    TMatrix<int> mat1(5);
    cout << "Test  3. mat1.GetSize(). Expected: " << 5 << ", actual: " << mat1.GetSize() << endl;
    cout << "Test  4. mat1.GetStartIndex(). Expected: " << 0 << ", actual: " << mat1.GetStartIndex() << endl;
    for (int i = 0; i < 5; i++)
      for (int j = i; j < 5; j++)
        mat1[i][j] = i * 5 + j;
    cout << "Test  5. mat0 == mat1. Expected: " << false << ", actual: " << (mat0 == mat1) << endl;
    mat0 = mat1;
    cout << "Test  6. mat0 == mat1. Expected: " << true << ", actual: " << (mat0 == mat1) << endl;
    TMatrix<int> mat2(mat1);
    cout << "Test  7. mat2 == mat1. Expected: " << true << ", actual: " << (mat2 == mat1) << endl;

    cout << "Test  8. Print mat1." << endl;
    cout << "Expected:" << endl
      << "0 1 2 3 4" << endl
      << "6 7 8 9" << endl
      << "12 13 14" << endl
      << "18 19" << endl
      << "24" << endl;
    cout << "Actual:" << endl << mat1 << endl;

    cout << "Test  9. mat1 + mat1." << endl;
    cout << "Expected:" << endl
      << "0 2 4 6 8" << endl
      << "12 14 16 18" << endl
      << "24 26 28" << endl
      << "36 38" << endl
      << "48" << endl;
    cout << "Actual:" << endl << mat1 + mat1 << endl;

    cout << "Test 10. mat1 - mat1." << endl;
    cout << "Expected:" << endl
      << "0 0 0 0 0" << endl
      << "0 0 0 0" << endl
      << "0 0 0" << endl
      << "0 0" << endl
      << "0" << endl;
    cout << "Actual:" << endl << mat1 - mat1 << endl;

    cout << "Test 11. mat1 * mat1." << endl;
    cout << "Expected:" << endl
      << "0 6 31 88 190" << endl
      << "36 126 283 520" << endl
      << "144 390 751" << endl
      << "324 798" << endl
      << "576" << endl;
    cout << "Actual:" << endl << mat1 * mat1 << endl;

  }

  return 0;
}

#else
#include <iostream>
#include "TMatrix.h"
using namespace std;

int main()
{
  TMatrix<int> a(5), b(5), c(5);
  int i, j;

  setlocale(LC_ALL, "Russian");
  cout << "������������ �������� ��������� ������������� ����������� ������"
    << endl;
  for (i = 0; i < 5; i++)
    for (j = i; j < 5; j++)
    {
      a[i][j] = i * 10 + j;
      b[i][j] = (i * 10 + j) * 100;
    }
  c = a + b;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << c << endl;
  return 0;
}
#endif
