/**
 * @file Bowling_scoretest.cpp
 * @brief Unit tests for the BowlingGame class.
 */

#include "src/Bowling.h"
#include <gtest/gtest.h>

class BowlingTest : public ::testing::Test
{
protected:
    BowlingGame game;

    void rollMany(int rolls, int pins)
    {
        for (int i = 0; i < rolls; ++i)
        {
            game.addRoll(pins);
        }
    }

    void rollSpare()
    {
        game.addRoll(5);
        game.addRoll(5);
    }

    void rollStrike()
    {
        game.addRoll(10);
    }
};

TEST_F(BowlingTest, GutterGame)
{
    rollMany(20, 0);
    game.printFrameScores();
    EXPECT_EQ(game.calculateScore(), 0);
}

TEST_F(BowlingTest, AllOnes)
{
    rollMany(20, 1);
    game.printFrameScores();
    EXPECT_EQ(game.calculateScore(), 20);
}

TEST_F(BowlingTest, OneSpare)
{
    rollSpare(); // 10 + 3
    game.addRoll(3);
    rollMany(17, 0);
    game.printFrameScores();
    EXPECT_EQ(game.calculateScore(), 16);
}

TEST_F(BowlingTest, OneStrike)
{
    rollStrike(); // 10 + 3 + 4
    game.addRoll(3);
    game.addRoll(4);
    rollMany(16, 0);
    game.printFrameScores();
    EXPECT_EQ(game.calculateScore(), 24);
}

TEST_F(BowlingTest, PerfectGame)
{
    rollMany(12, 10); // 12 strikes
    game.printFrameScores();
    EXPECT_EQ(game.calculateScore(), 300);
}

TEST_F(BowlingTest, TenthFrameSpare)
{
    rollMany(18, 0);
    game.addRoll(5);
    game.addRoll(5); // spare in 10th
    game.addRoll(7); // bonus
    game.printFrameScores();
    EXPECT_EQ(game.calculateScore(), 17);
}

TEST_F(BowlingTest, TenthFrameStrike)
{
    rollMany(18, 0);
    game.addRoll(10); // strike
    game.addRoll(5);
    game.addRoll(3);
    game.printFrameScores();
    EXPECT_EQ(game.calculateScore(), 18);
}
