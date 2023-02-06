//
// Created by Stefano on 2/6/2023.
//

#include "hashing_test.h"

namespace hashing_test {
TEST(HashingTest, Expect_CorrectHashing) {
  std::string value_before_hashing = "valuebeforehasing";
  auto result = hashing::ToHash(value_before_hashing);
  std::string expected = "3394324239491002170";

  EXPECT_EQ(expected, result);
}
}