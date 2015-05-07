#include "exponent_quiz.h"
#include "gtest/gtest.h"
#include <cstdlib>
#include <ctime>

TEST(Quiz, GENERATE_EXPONENTS_1) {
  int min = 40;
  int max = 49;
  int size = max-min+1+2;
  int *exponents = new int [size];
  int *check = new int [size];
  int i,j,k;
  int lower_tag = -111;
  int upper_tag = -222;
  exponents[0] = lower_tag;
  exponents[size-1] = upper_tag;

  generate_exponents(min, max, &exponents[1]);

  for(i = 0; i < size; i++)
    {
      check[i] = 0;
    }
  // check that array bounds have been obeyed
  EXPECT_EQ(exponents[0], lower_tag);
  EXPECT_EQ(exponents[size-1], upper_tag);

  // check that each required value was generated once
  for(i = 1; i < size-1; i++)
    {
      j = exponents[i];
      k = j - min + 1;
      if(k > 0 && k < size-1)
        {
          check[k] ++;
        }
    }

  for(i = 1; i < size-1; i++)
    {
      EXPECT_EQ(check[i], 1);
    }

  delete [] exponents;
  delete [] check;
}


TEST(Quiz, GENERATE_EXPONENTS_2) {
  int min = 20;
  int max = 40;
  int size = max-min+1+2;
  int *exponents = new int [size];
  int *check = new int [size];
  int i,j,k;
  int lower_tag = -111;
  int upper_tag = -222;
  exponents[0] = lower_tag;
  exponents[size-1] = upper_tag;

  generate_exponents(min, max, &exponents[1]);

  for(i = 0; i < size; i++)
    {
      check[i] = 0;
    }
  // check that array bounds have been obeyed
  EXPECT_EQ(exponents[0], lower_tag);
  EXPECT_EQ(exponents[size-1], upper_tag);

  // check that each required value was generated once
  for(i = 1; i < size-1; i++)
    {
      j = exponents[i];
      k = j - min + 1;
      if(k > 0 && k < size-1)
        {
          check[k] ++;
        }
    }

  for(i = 1; i < size-1; i++)
    {
      EXPECT_EQ(check[i], 1);
    }
  delete [] exponents;
  delete [] check;
}

TEST(Quiz, GENERATE_EXPONENTS_3) {
  int min = 0;
  int max = 9;
  int size = max-min+1+2;
  int *exponents = new int [size];
  int *check = new int [size];
  int i,j,k;
  int lower_tag = -111;
  int upper_tag = -222;
  exponents[0] = lower_tag;
  exponents[size-1] = upper_tag;

  generate_exponents(min, max, &exponents[1]);

  for(i = 0; i < size; i++)
    {
      check[i] = 0;
    }
  // check that array bounds have been obeyed
  EXPECT_EQ(exponents[0], lower_tag);
  EXPECT_EQ(exponents[size-1], upper_tag);

  // check that each required value was generated once
  for(i = 1; i < size-1; i++)
    {
      j = exponents[i];
      k = j - min + 1;
      if(k > 0 && k < size-1)
        {
          check[k] ++;
        }
    }

  for(i = 1; i < size-1; i++)
    {
      EXPECT_EQ(check[i], 1);
    }
  delete [] exponents;
  delete [] check;
}

TEST(Quiz, GENERATE_EXPONENTS_4) {
  int min = 0;
  int max = 100;
  int size = max-min+1+2;
  int *exponents = new int [size];
  int *check = new int [size];
  int i,j,k;
  int lower_tag = -111;
  int upper_tag = -222;
  exponents[0] = lower_tag;
  exponents[size-1] = upper_tag;

  generate_exponents(min, max, &exponents[1]);

  for(i = 0; i < size; i++)
    {
      check[i] = 0;
    }
  // check that array bounds have been obeyed
  EXPECT_EQ(exponents[0], lower_tag);
  EXPECT_EQ(exponents[size-1], upper_tag);

  // check that each required value was generated once
  for(i = 1; i < size-1; i++)
    {
      j = exponents[i];
      k = j - min + 1;
      if(k > 0 && k < size-1)
        {
          check[k] ++;
        }
    }

  for(i = 1; i < size-1; i++)
    {
      EXPECT_EQ(check[i], 1);
    }

  // check that the elements are shuffled
  int in_place = 0;
  for(i = 1; i < size-1; i++)
    {
      j = exponents[i];
      if(exponents[i] == min + i - 1)
        {
          in_place++;
        }
    }
  EXPECT_LT(in_place, (max-min)/5); // no more than 20%


  delete [] exponents;
  delete [] check;
}

TEST(Quiz, GENERATE_EXPONENTS_5) {
  int min = 0;
  int max = 49;
  int size = max-min+1+2;
  int *exponents = new int [size];
  int *check = new int [size];
  int i,j,k;
  int lower_tag = -111;
  int upper_tag = -222;
  exponents[0] = lower_tag;
  exponents[size-1] = upper_tag;

  generate_exponents(min, max, &exponents[1]);

  for(i = 0; i < size; i++)
    {
      check[i] = 0;
    }
  // check that array bounds have been obeyed
  EXPECT_EQ(exponents[0], lower_tag);
  EXPECT_EQ(exponents[size-1], upper_tag);

  // check that each required value was generated once
  for(i = 1; i < size-1; i++)
    {
      j = exponents[i];
      k = j - min + 1;
      if(k > 0 && k < size-1)
        {
          check[k] ++;
        }
    }

  for(i = 1; i < size-1; i++)
    {
      EXPECT_EQ(check[i], 1);
    }
  delete [] exponents;
  delete [] check;
}
