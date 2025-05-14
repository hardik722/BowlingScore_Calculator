#include "Bowling.h"

/**
 * Method to add the result of a roll (pins knocked down) to the game
 */
void BowlingGame::addRoll(uint16_t pins)
{
    pinsDown.push_back(pins);
}

/**
 * Method to calculate the total score for the game
 * Handles strikes, spares, and open frames following standard bowling rules
 */
uint16_t BowlingGame::getTotalScore() const
{
    return score;
}

/**
 * Method to print cumulative scores after each frame
 * This is helpful for interactive display the each frame score
 */
void BowlingGame::calculateFrameScores()
{
    score = MIN_PINS;
    uint16_t idx = START_IDX, size = pinsDown.size();

    for (uint16_t frame = 1; frame <= TOTAL_FRAMES; ++frame)
    {
        if (idx >= size)
            break;

        if (pinsDown[idx] == MAX_PINS)
        {
            if (idx + 2 < size)
            {
                score += MAX_PINS + pinsDown[idx + 1] + pinsDown[idx + 2];
                std::cout << "Frame " << frame << " (Strike): " << score << "\n";
            }
            ++idx;
        }
        else if (idx + 1 < size && pinsDown[idx] + pinsDown[idx + 1] == MAX_PINS)
        {
            if (idx + 2 < size)
            {
                score += MAX_PINS + pinsDown[idx + 2];
                std::cout << "Frame " << frame << " (Spare): " << score << "\n";
            }
            idx += 2;
        }
        else
        {
            if (idx + 1 < size)
            {
                score += pinsDown[idx] + pinsDown[idx + 1];
                std::cout << "Frame " << frame << " (Open): " << score << "\n";
            }
            idx += 2;
        }
    }
}
