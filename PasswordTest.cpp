/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(MixedCaseTest, single_letter_password){
	Password my_password;
	bool actual = my_password.has_mixed_case("a");
	ASSERT_EQ(false, actual);
}

TEST(MixedCaseTest, mixed_password){
	Password my_password;
	bool actual = my_password.has_mixed_case("aA");
	ASSERT_EQ(true, actual);
}

TEST(MixedCaseTest, empty_password){
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}

TEST(MixedCaseTest, longer_password){
	Password my_password;
	bool actual = my_password.has_mixed_case("abdfsefevwfgretgA");
	ASSERT_EQ(true, actual);
}

TEST(MixedCaseTest, numbers_password){
	Password my_password;
	bool actual = my_password.has_mixed_case("543654253");
	ASSERT_EQ(false, actual);
}

TEST(MixedCaseTest, numbers_and_lowerletters_password){
	Password my_password;
	bool actual = my_password.has_mixed_case("34fgv5e53g4sf3435");
	ASSERT_EQ(false, actual);
}

TEST(MixedCaseTest, numbers_and_mixed_letters_password){
	Password my_password;
	bool actual = my_password.has_mixed_case("34fgvAFFE5e53gREVE4sf34FEE35");
	ASSERT_EQ(true, actual);
}