/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, toggleTurnTest){
	TicTacToeBoard tttBoard;
	ASSERT_EQ(tttBoard.toggleTurn(), O);
	ASSERT_EQ(tttBoard.toggleTurn(), X);
}

TEST(TicTacToeBoardTest, placePieceTest){
	TicTacToeBoard tttBoard;
	ASSERT_EQ(tttBoard.placePiece(0, 0), X);
	ASSERT_EQ(tttBoard.placePiece(2, 2), O);
	ASSERT_EQ(tttBoard.placePiece(1, 1), X);
	ASSERT_EQ(tttBoard.placePiece(2, 3), Invalid);
	ASSERT_EQ(tttBoard.placePiece(3, 2), Invalid);
	ASSERT_EQ(tttBoard.placePiece(0, 0), X);
}

TEST(TicTacToeBoardTest, getPieceTest){
	TicTacToeBoard tttBoard;
	tttBoard.placePiece(1, 2);
	tttBoard.placePiece(0, 0);
	ASSERT_EQ(tttBoard.getPiece(1, 2), X);
	ASSERT_EQ(tttBoard.getPiece(0, 0), O);
	ASSERT_EQ(tttBoard.getPiece(1, 1), Blank);
	ASSERT_EQ(tttBoard.getPiece(0, 2), Blank);
	ASSERT_EQ(tttBoard.getPiece(0, -1), Invalid);
	ASSERT_EQ(tttBoard.getPiece(2, 3), Invalid);
}
