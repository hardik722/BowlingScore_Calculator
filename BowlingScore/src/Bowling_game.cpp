#include "Bowling.h"
#include <iostream>


/**
    * Method to add the result of a roll (pins knocked down) to the game
*/
void BowlingGame::addRoll(int pins)
{
    pinsDown.push_back(pins);
}

/**
    * Method to calculate the total score for the game
    * Handles strikes, spares, and open frames following standard bowling rules
 */
int BowlingGame::calculateScore() const
{
    int score = 0;
    size_t idx = 0;

    for (int frame = 0; frame < 10; ++frame)
    {
        if (idx >= pinsDown.size())
            break;

        if (pinsDown[idx] == 10)
        { // Strike
            score += 10 + (idx + 1 < pinsDown.size() ? pinsDown[idx + 1] : 0) + (idx + 2 < pinsDown.size() ? pinsDown[idx + 2] : 0);
            ++idx;
        }
        else if (idx + 1 < pinsDown.size() && pinsDown[idx] + pinsDown[idx + 1] == 10)
        { // Spare
            score += 10 + (idx + 2 < pinsDown.size() ? pinsDown[idx + 2] : 0);
            idx += 2;
        }
        else
        { // Open
            score += (idx + 1 < pinsDown.size()) ? (pinsDown[idx] + pinsDown[idx + 1]) : pinsDown[idx];
            idx += 2;
        }
    }
    return score;
}

/**
    * Method to print cumulative scores after each frame
    * This is helpful for interactive display the each frame score
 */
void BowlingGame::printFrameScores() const
{
    int score = 0;
    size_t idx = 0;

    for (int frame = 1; frame <= 10; ++frame)
    {
        if (idx >= pinsDown.size())
            break;

        if (pinsDown[idx] == 10)
        {
            if (idx + 2 < pinsDown.size())
            {
                score += 10 + pinsDown[idx + 1] + pinsDown[idx + 2];
                std::cout << "Frame " << frame << " (Strike): " << score << "\n";
            }
            ++idx;
        }
        else if (idx + 1 < pinsDown.size() && pinsDown[idx] + pinsDown[idx + 1] == 10)
        {
            if (idx + 2 < pinsDown.size())
            {
                score += 10 + pinsDown[idx + 2];
                std::cout << "Frame " << frame << " (Spare): " << score << "\n";
            }
            idx += 2;
        }
        else
        {
            if (idx + 1 < pinsDown.size())
            {
                score += pinsDown[idx] + pinsDown[idx + 1];
                std::cout << "Frame " << frame << " (Open): " << score << "\n";
            }
            idx += 2;
        }
    }
}
