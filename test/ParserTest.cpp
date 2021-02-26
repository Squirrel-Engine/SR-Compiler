#include <gtest/gtest.h>

#include "../SRCompiler/include/HeaderCompiler.h"


class ParserTest : public ::testing::Test
{
public:
	HEADER_COMPILER_DESC hd = {};
	HeaderCompiler* hc = new HeaderCompiler(&hd);
};

TEST_F(ParserTest, GetDataFromJSON)
{
	ASSERT_EQ(this->hc->x, 0);
}

