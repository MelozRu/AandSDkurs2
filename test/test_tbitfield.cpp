#include "tbitfield.h"

#include <gtest/gtest.h>

TEST(TBitField, can_get_length)
{
  TBitField bf(3);

  EXPECT_EQ(3, bf.GetLength());
}

TEST(TBitField, can_set_bit)
{
  TBitField bf(10);

  EXPECT_EQ(0, bf.GetBit(3));

  bf.SetBit(3);
  EXPECT_NE(0, bf.GetBit(3));
}

TEST(TBitField, can_clear_bit)
{
  TBitField bf(10);

  int bitIdx = 3;

  bf.SetBit(bitIdx);
  EXPECT_NE(0, bf.GetBit(bitIdx));

  bf.ClrBit(bitIdx);
  EXPECT_EQ(0, bf.GetBit(bitIdx));
}

TEST(TBitField, can_create_bitfield_with_positive_length)
{
  ASSERT_NO_THROW(TBitField bf(3));
}

TEST(TBitField, new_bitfield_is_set_to_zero)
{
  TBitField bf(100);

  int sum = 0;
  for (int i = 0; i < bf.GetLength(); i++)
  {
    sum += bf.GetBit(i);
  }

  EXPECT_EQ(0, sum);
}

TEST(TBitField, throws_when_create_bitfield_with_negative_length)
{
  ASSERT_ANY_THROW(TBitField bf(-5));
}

TEST(TBitField, throws_when_set_bit_with_negative_index)
{
  TBitField bf(10);

  ASSERT_ANY_THROW(bf.SetBit(-5));
}

TEST(TBitField, throws_when_set_bit_with_too_large_index)
{
  TBitField bf(10);

  ASSERT_ANY_THROW(bf.SetBit(11));
}

TEST(TBitField, throws_when_get_bit_with_negative_index)
{
  TBitField bf(10);

  ASSERT_ANY_THROW(bf.GetBit(-5));
}

TEST(TBitField, throws_when_get_bit_with_too_large_index)
{
  TBitField bf(10);

  ASSERT_ANY_THROW(bf.GetBit(11));
}

TEST(TBitField, throws_when_clear_bit_with_negative_index)
{
  TBitField bf(10);

  ASSERT_ANY_THROW(bf.ClrBit(-5));
}

TEST(TBitField, throws_when_clear_bit_with_too_large_index)
{
  TBitField bf(10);

  ASSERT_ANY_THROW(bf.ClrBit(11));
}

TEST(TBitField, can_sign_bitfields_of_equal_size)
{
  const int size = 2;
  TBitField bf1(size), bf2(size);
  for (int i = 0; i < size; i++)
  {
    bf1.SetBit(i);
  }
  bf2 = bf1;

  EXPECT_NE(0, bf2.GetBit(0));
  EXPECT_NE(0, bf2.GetBit(1));
}

TEST(TBitField, sign_operator_changes_bitfield_size)
{
  const int size_1 = 3, size_2 = 7;
  TBitField bf1(size_1), bf2(size_2);
  for (int i = 0; i < size_1; i++)
  {
    bf1.SetBit(i);
  }
  bf2 = bf1;

  EXPECT_EQ(3, bf2.GetLength());
}

TEST(TBitField, can_sign_bitfields_of_non_equal_size)
{
  const int size_1 = 3, size_2 = 7;
  TBitField bf1(size_1), bf2(size_2);
  for (int i = 0; i < size_1; i++)
  {
    bf1.SetBit(i);
  }
  bf2 = bf1;

  EXPECT_NE(0, bf2.GetBit(0));
  EXPECT_NE(0, bf2.GetBit(1));
}

TEST(TBitField, compare_equal_bitfields_of_equal_size)
{
  const int size = 3;
  TBitField bf1(size), bf2(size);
  for (int i = 0; i < size; i++)
  {
    bf1.SetBit(i);
  }
  bf2 = bf1;

  EXPECT_EQ(bf1, bf2);
}

TEST(TBitField, or_operator_to_bitfields_of_equal_size)
{
  const int size = 4;
  TBitField bf1(size), bf2(size), tmpBf(size);
  // bf1 = 0011
  bf1.SetBit(2);
  bf1.SetBit(3);
  // bf2 = 0101
  bf2.SetBit(1);
  bf2.SetBit(3);

  // tmpBf = 0111
  tmpBf.SetBit(1);
  tmpBf.SetBit(2);
  tmpBf.SetBit(3);

  EXPECT_EQ(tmpBf, bf1 | bf2);
}

TEST(TBitField, or_operator_to_bitfields_of_non_equal_size)
{
  const int size1 = 4, size2 = 5;
  TBitField bf1(size1), bf2(size2), tmpBf(size2);
  // bf1 = 0011
  bf1.SetBit(2);
  bf1.SetBit(3);
  // bf2 = 01010
  bf2.SetBit(1);
  bf2.SetBit(3);

  // tmpBf = 01110
  tmpBf.SetBit(1);
  tmpBf.SetBit(2);
  tmpBf.SetBit(3);

  EXPECT_EQ(tmpBf, bf1 | bf2);
}

TEST(TBitField, and_operator_to_bitfields_of_equal_size)
{
  const int size = 4;
  TBitField bf1(size), bf2(size), tmpBf(size);
  // bf1 = 0011
  bf1.SetBit(2);
  bf1.SetBit(3);
  // bf2 = 0101
  bf2.SetBit(1);
  bf2.SetBit(3);

  // tmpBf = 0001
  tmpBf.SetBit(3);

  EXPECT_EQ(tmpBf, bf1 & bf2);
}

TEST(TBitField, and_operator_to_bitfields_of_non_equal_size)
{
  const int size1 = 4, size2 = 5;
  TBitField bf1(size1), bf2(size2), tmpBf(size2);
  // bf1 = 0011
  bf1.SetBit(2);
  bf1.SetBit(3);
  // bf2 = 01010
  bf2.SetBit(1);
  bf2.SetBit(3);

  // tmpBf = 00010
  tmpBf.SetBit(3);

  EXPECT_EQ(tmpBf, bf1 & bf2);
}

TEST(TBitField, can_invert_bitfield)
{
  const int size = 2;
  TBitField bf(size), negBf(size), tmpNegBf(size);
  // bf = 01
  bf.SetBit(1);
  negBf = ~bf;

  // tmpNegBf = 10
  tmpNegBf.SetBit(0);

  EXPECT_EQ(tmpNegBf, negBf);
}

TEST(TBitField, can_invert_large_bitfield)
{
  const int size = 38;
  TBitField bf(size), negBf(size), tmpNegBf(size);
  bf.SetBit(35);
  negBf = ~bf;

  for(int i = 0; i < size; i++)
    tmpNegBf.SetBit(i);
  tmpNegBf.ClrBit(35);

  EXPECT_EQ(tmpNegBf, negBf);
}

TEST(TBitField, invert_plus_and_operator_on_different_size_bitfield)
{
  const int firstSze = 4, secondSize = 8;
  TBitField firstBf(firstSze), negFirstBf(firstSze), secondBf(secondSize), testBf(secondSize);
  // firstBf = 0001
  firstBf.SetBit(0);
  negFirstBf = ~firstBf;
  // negFirstBf = 1110

  // secondBf = 00011000
  secondBf.SetBit(3);
  secondBf.SetBit(4);

  // testBf = 00001000
  testBf.SetBit(3);

  EXPECT_EQ(secondBf & negFirstBf, testBf);
}

TEST(TBitField, can_invert_random_bits_bitfield)
{
  const int size = 40;
  TBitField bf(size), negBf(size), tmpNegBf(size);

  std::vector<int> bits;
  bits.push_back(0);
  bits.push_back(1);
  bits.push_back(13);
  bits.push_back(17);
  bits.push_back(35);
  bits.push_back(38);

  for (unsigned int i = 0; i < bits.size(); i++)
    bf.SetBit(bits[i]);

  negBf = ~bf;

  for(int i = 0; i < size; i++)
    tmpNegBf.SetBit(i);
  for (unsigned int i = 0; i < bits.size(); i++)
    tmpNegBf.ClrBit(bits[i]);

  EXPECT_EQ(tmpNegBf, negBf);
}

TEST(TBitField, bitfields_with_different_bits_are_not_equal)
{
  const int size = 4;
  TBitField bf1(size), bf2(size);

  bf1.SetBit(1);
  bf1.SetBit(2);

  bf2.SetBit(1);
  bf2.SetBit(3);

  EXPECT_NE(bf1, bf2);
}
