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
	tttBoard.placePiece(2, 0); //O's turn
	tttBoard.placePiece(1, 2); //X's turn
	tttBoard.placePiece(2, 1); //O's turn; O wins
	ASSERT_EQ(tttBoard.placePiece(0, 1), O); //X's turn but return O b/c O won
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
	ASSERT_EQ(tttBoard.getPiece(-1, 0), Invalid);
	ASSERT_EQ(tttBoard.getPiece(3,1), Invalid);
}

TEST(TicTacToeBoardTest, getWinnerFirstRowTest){
	TicTacToeBoard tttBoard;
	tttBoard.placePiece(0, 0); //X
	tttBoard.placePiece(2, 2); //O
	tttBoard.placePiece(0, 1); //X
	tttBoard.placePiece(2, 1); //O
	tttBoard.placePiece(0, 2); //X wins
	ASSERT_EQ(tttBoard.getWinner(), X);
}

TEST(TicTacToeBoardTest, getWinnerSecondRowTest){
	TicTacToeBoard tttBoard;
	tttBoard.placePiece(1, 0); //X
	tttBoard.placePiece(2, 2); //O
	tttBoard.placePiece(1, 1); //X
	tttBoard.placePiece(2, 1); //O
	tttBoard.placePiece(1, 2); //X wins
	ASSERT_EQ(tttBoard.getWinner(), X);
}

TEST(TicTacToeBoardTest, getWinnerThirdRowTest){
	TicTacToeBoard tttBoard;
	tttBoard.placePiece(2, 0); //X
	tttBoard.placePiece(1, 2); //O
	tttBoard.placePiece(2, 1); //X
	tttBoard.placePiece(0, 1); //O
	tttBoard.placePiece(2, 2); //X wins
	ASSERT_EQ(tttBoard.getWinner(), X);
}

TEST(TicTacToeBoardTest, getWinnerFirstColumnTest){
	TicTacToeBoard tttBoard;
	tttBoard.placePiece(2, 0); //X
	tttBoard.placePiece(0, 0); //O
	tttBoard.placePiece(2, 1); //X
	tttBoard.placePiece(0, 1); //O
	tttBoard.placePiece(1, 2); //X
	tttBoard.placePiece(O, 2); // O wins
	ASSERT_EQ(tttBoard.getWinner(), O);
}

TEST(TicTacToeBoardTest, getWinnerSecondColumnTest){
	TicTacToeBoard tttBoard;
	tttBoard.placePiece(2, 0); //X
	tttBoard.placePiece(0, 1); //O
	tttBoard.placePiece(2, 1); //X
	tttBoard.placePiece(1, 1); //O
	tttBoard.placePiece(0, 2); //X
	tttBoard.placePiece(2, 1); // O wins
	ASSERT_EQ(tttBoard.getWinner(), O);
}

TEST(TicTacToeBoardTest, getWinnerThirdColumnTest){
	TicTacToeBoard tttBoard;
	tttBoard.placePiece(0, 0); //X
	tttBoard.placePiece(0, 2); //O
	tttBoard.placePiece(1, 1); //X
	tttBoard.placePiece(1, 2); //O
	tttBoard.placePiece(1, 0); //X
	tttBoard.placePiece(2, 2); // O wins
	ASSERT_EQ(tttBoard.getWinner(), O);
}

TEST(TicTacToeBoardTest, getWinnerFrontSlashTest){
	TicTacToeBoard tttBoard;
	tttBoard.placePiece(0, 2); //X
	tttBoard.placePiece(0, 1); //O
	tttBoard.placePiece(1, 1); //X
	tttBoard.placePiece(1, 2); //O
	tttBoard.placePiece(2, 0); //X
	ASSERT_EQ(tttBoard.getWinner(), X);
}

TEST(TicTacToeBoardTest, getWinnerBackSlashTest){
	TicTacToeBoard tttBoard;
	tttBoard.placePiece(0, 0); //X
	tttBoard.placePiece(0, 1); //O
	tttBoard.placePiece(1, 1); //X
	tttBoard.placePiece(1, 2); //O
	tttBoard.placePiece(2, 2); //X
	ASSERT_EQ(tttBoard.getWinner(), X);
}
