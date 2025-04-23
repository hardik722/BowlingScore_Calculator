#ifndef BOWLING_H
#define BOWLING_H

#include <vector>
#include <iostream>
using namespace std;
/**
 * Interface for a Bowling Game.
 */
class IBowlingGame
{
public:
    /**
     * Pure virtual method to add the result of a roll.
     * @param pins Number of pins knocked down in a roll.
     */
    virtual void addRoll(int pins) = 0;

    /**
     * Pure virtual method to calculate the total score of the game.
     * @return Total score.
     */
    virtual int calculateScore() const = 0;

    // Virtual destructor for proper cleanup of derived classes
    virtual ~IBowlingGame() = default;
};

class BowlingGame : public IBowlingGame
{
private:
    // Vector to store the number of pins knocked down in each roll
    std::vector<int> pinsDown;

public:
    // Default constructor
    BowlingGame() = default;

    /**
     * Add the result of a single roll to the game.
     * @param pins Number of pins knocked down.
     */
    void addRoll(int pins) override;

    /**
     * Calculate the total score for the game using bowling rules.
     * Handles strikes, spares, and open frames.
     * @return Total score.
     */
    int calculateScore() const override;

    /**
     * Print cumulative scores after each frame.
     * Helpful for interactive display or debugging.
     */
    void printFrameScores() const;

    // Destructor
    ~BowlingGame() override = default;
};

#endif
