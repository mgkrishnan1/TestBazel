#include <iostream>
#include "gtest/gtest.h"
#include "src/gtest.cc"
#include "src/gtest-death-test.cc"
#include "src/gtest-filepath.cc"
#include "src/gtest-port.cc"
#include "src/gtest-printers.cc"
#include "src/gtest-test-part.cc"
#include "src/gtest-typed-test.cc"

using namespace std;

class Check 
{
	int val;
	public:
		Check()
		{
			val = 0;
		}

		void setVal(int newVal) 
		{ 
			val = newVal; 
		}

		int getVal() 
		{ 
			return val; 
		}
};


struct TF : public testing::Test 
{
	Check* c1 = new Check();
	void SetUp() 
	{ 
		cout << "SETUP" << endl; 
	}

	void TearDown() 
	{ 
		cout << "TEARDOWN" << endl; 
		delete c1; 
	}
};


TEST_F(TF, TestName1) 
{
	c1->setVal(100);
	ASSERT_EQ(c1->getVal(), 1001) << "Value Mismatch!";
	cout << "Test Fixture completed!" << endl;
}


int main(int argc, char** argv)
{

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}