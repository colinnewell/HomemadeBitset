
#include "catch.hpp"

#include "../Bitset.h"

using namespace CPPLondonUni;

TEST_CASE("Can Create and test a bitfield") {
  Bitset b{static_cast<char>(0b10001111)};
  CHECK((b.test(0) && b.test(1) && b.test(2) && b.test(3) && b.test(7)));
  CHECK(!b.test(6));
}

TEST_CASE("Can check if all bits are set") {
  Bitset b1{static_cast<char>(0b11111111)};
  Bitset b2{static_cast<char>(0b11011111)};
  Bitset b3{static_cast<char>(0b0)};
  CHECK(b1.all());
  CHECK(!b2.all());
  CHECK(!b3.all());
}

TEST_CASE("Can check if any bit is set") {
  Bitset b1{static_cast<char>(0b10101010)};
  Bitset b2{static_cast<char>(0b0)};
  CHECK(b1.any());
  CHECK(!b2.any());
}

TEST_CASE("Can check if no bits are set") {
  Bitset b1{static_cast<char>(0b10101010)};
  Bitset b2{static_cast<char>(0b0)};
  CHECK(!b1.none());
  CHECK(b2.none());
}

TEST_CASE("Can check the count of set bits") {
  Bitset b1{static_cast<char>(0b10101010)};
  Bitset b2{static_cast<char>(0b0)};
  Bitset b3{static_cast<char>(0b11111111)};
  CHECK(b1.count() == 4);
  CHECK(b2.count() == 0);
  CHECK(b3.count() == 8);
}

TEST_CASE("Can check the size of its member") {
  Bitset b{static_cast<char>(0b0)};
  CHECK(b.size() == 8);
}

TEST_CASE("Can set bits in the buildfield") {
  Bitset b{static_cast<char>(0b0)};
  CHECK(b.none());
  b.set(4);
  CHECK(b.count() == 1);
  CHECK((b.test(4) && b.any()));
  CHECK(!b.test(3));
}

TEST_CASE("Can check if it can reset set bit") {
  Bitset b{static_cast<char>(0b0)};
  CHECK(b.none());
  b.set(4);
  CHECK(b.count() == 1);
  CHECK((b.test(4) && b.any()));
  CHECK(!b.test(3));
  b.reset(4);
  CHECK(b.none());
}

TEST_CASE("A Bitfield can be flipped") {
  Bitset b{static_cast<char>(0b11111011)};
  int count = b.count();
  b.flip();
  CHECK(b.count() == (8 - count));
  CHECK(b.test(2));
}
