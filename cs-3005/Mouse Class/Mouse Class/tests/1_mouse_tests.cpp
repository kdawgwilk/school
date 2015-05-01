#include "mouse_funcs.h"
#include "mouse_funcs.h"  // Did you use #ifndef/#define/#endif?
#include "gtest/gtest.h"

//
TEST(mouse, CLICK_CENTER_1) {
  Mouse m;
  m = click_center(1024, 768);
  EXPECT_EQ(512, m.getX());
  EXPECT_EQ(384, m.getY());
  EXPECT_EQ(1, m.getButton());
}

//
TEST(mouse, CLICK_CENTER_2) {
  Mouse m;
  m = click_center(1000, 500);
  EXPECT_EQ(500, m.getX());
  EXPECT_EQ(250, m.getY());
  EXPECT_EQ(1, m.getButton());
}


//
TEST(mouse, CLICK_MAX_1) {
  Mouse m;
  m = click_max(1024, 768);
  EXPECT_EQ(1023, m.getX());
  EXPECT_EQ(767, m.getY());
  EXPECT_EQ(1, m.getButton());
}

//
TEST(mouse, CLICK_MAX_2) {
  Mouse m;
  m = click_max(1000, 500);
  EXPECT_EQ(999, m.getX());
  EXPECT_EQ(499, m.getY());
  EXPECT_EQ(1, m.getButton());
}



//
TEST(mouse, UNCLICK_CENTER_1) {
  Mouse m;
  m = unclick_center(1024, 768);
  EXPECT_EQ(512, m.getX());
  EXPECT_EQ(384, m.getY());
  EXPECT_EQ(0, m.getButton());
}

//
TEST(mouse, UNCLICK_CENTER_2) {
  Mouse m;
  m = unclick_center(1000, 500);
  EXPECT_EQ(500, m.getX());
  EXPECT_EQ(250, m.getY());
  EXPECT_EQ(0, m.getButton());
}


//
TEST(mouse, UNCLICK_MAX_1) {
  Mouse m;
  m = unclick_max(1024, 768);
  EXPECT_EQ(1023, m.getX());
  EXPECT_EQ(767, m.getY());
  EXPECT_EQ(0, m.getButton());
}

//
TEST(mouse, UNCLICK_MAX_2) {
  Mouse m;
  m = unclick_max(1000, 500);
  EXPECT_EQ(999, m.getX());
  EXPECT_EQ(499, m.getY());
  EXPECT_EQ(0, m.getButton());
}
