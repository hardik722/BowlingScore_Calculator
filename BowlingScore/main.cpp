#include "src/Bowling.h"
#include <memory>
#include <limits>

/**
 * Function to get the first valid roll from user input
 * @param prompt The prompt message to display to the user
 * @return The valid roll entered by the user
 */
uint16_t getfirstValidRoll(const std::string &prompt)
{
    uint16_t roll{MIN_PINS};
    std::cout << "Valid numeric input [0 - 10]" << std::endl;
    while (true)
    {
        std::cout << prompt;
        std::cin >> roll;

        // Validate the input
        if (std::cin.fail() || roll < MIN_PINS || roll > MAX_PINS)
        {
            std::cin.clear();                                                   // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Not allowed, Please enter a numeric input between 0 and 10.\n";
            roll = 0;
        }
        else
        {
            break; // Valid input, exit the loop
        }
    }
    return roll;
}

/**
 * Function to get the first valid roll from user input
 * @param prompt The prompt message to display to the user
 * @return The valid roll entered by the user
 */
uint16_t getsecondValidRoll(uint16_t maxRoll)
{
    uint16_t roll{MIN_PINS};
    std::cout << "Valid numeric input [0 - " << maxRoll << "]" << std::endl;
    while (true)
    {
        std::cout << "Enter second roll: ";
        std::cin >> roll;

        // Validate the input
        if (std::cin.fail() || roll < MIN_PINS || roll > maxRoll)
        {
            std::cin.clear();                                                   // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Not allowed, please Enter valid numeric input from [0 - " << static_cast<int>(maxRoll) << "]" << std::endl;
            roll = 0;
        }
        else
        {
            break; // Valid input, exit the loop
        }
    }
    return roll;
}

int main()
{
    // Using unique_ptr for memory management, ensuring automatic cleanup of the game object when it goes out of scope
    std::unique_ptr<BowlingGame> game = std::make_unique<BowlingGame>();

    uint16_t firstRoll{MIN_PINS}, secondRoll{MIN_PINS};

    // Iterate over the 10 frames of the bowling game
    for (uint16_t frame{1}; frame <= TOTAL_FRAMES; ++frame)
    {
        std::cout << "\n--- Frame " << frame << " ---\n";
        firstRoll = getfirstValidRoll("Enter first roll: ");
        game->addRoll(firstRoll);

        // If it's not the last frame and the first roll is not a strike, ask for the second roll
        if (frame < TOTAL_FRAMES && firstRoll != MAX_PINS)
        {
            game->addRoll(getsecondValidRoll(MAX_PINS - firstRoll));
        }
        // For the 10th frame
        else if (frame == TOTAL_FRAMES)
        {
            if (firstRoll == MAX_PINS)
            {
                // Add bonus rolls if the first roll is a strike
                game->addRoll(getfirstValidRoll("Enter bonus roll 1: "));
                game->addRoll(getfirstValidRoll("Enter bonus roll 2: "));
            }
            else
            {
                secondRoll = getsecondValidRoll(MAX_PINS - firstRoll);
                game->addRoll(secondRoll);

                // If the second roll is a spare, ask for a bonus roll
                if (firstRoll + secondRoll == MAX_PINS)
                {
                    game->addRoll(getfirstValidRoll("Enter bonus roll: "));
                }
            }
        }

        // Downcast to access printFrameScores
        std::cout << "===========================" << std::endl;
        game->calculateFrameScores();
        std::cout << "===========================" << std::endl;
    }

    std::cout << "\nFinal Total Score: " << game->getTotalScore() << "\n";
    std::cout << "Thank you for playing!" << std::endl;

    return 0;
}
