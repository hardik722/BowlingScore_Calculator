#ifndef BOWLING_H
#define BOWLING_H

#include <vector>
#include <iostream>
#include <vector>

constexpr uint16_t TOTAL_FRAMES = 10;
constexpr uint16_t MAX_PINS = 10;
constexpr uint16_t MIN_PINS = 0;
constexpr uint16_t START_IDX = 0;

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
    virtual void addRoll(uint16_t pins) = 0;

    /**
     * Pure virtual method to calculate the total score of the game.
     * @return Total score.
     */
    virtual uint16_t getTotalScore() const = 0;

    // Virtual destructor for proper cleanup of derived classes
    virtual ~IBowlingGame() = default;
};

class BowlingGame : public IBowlingGame
{
public:
    // Default constructor
    BowlingGame() = default;
    ~BowlingGame() override = default;
    void addRoll(uint16_t pins) override;
    void calculateFrameScores();
    uint16_t getTotalScore() const override;

private:
    // Vector to store the number of pins knocked down in each roll
    std::vector<uint16_t> pinsDown;
    uint16_t score{0};
};

#endif // BOWLING_H
