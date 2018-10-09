#include "pch.h"
#include "Token.h"
#include "Token.cpp"

TEST(Token, TestClassInit) { 
	string name = "Token Name";
	string description = "Token Description";
	Token::Type type = Token::Type::Jinx;

	Token token(name, description, type);
	EXPECT_EQ(token.getName(), name);
	EXPECT_EQ(token.getDescription(), description);
	EXPECT_EQ(token.getType(), type);
}