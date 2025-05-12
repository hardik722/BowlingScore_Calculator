#include "src/Bowling.h"
#include <memory>
#include <limits>
int getValidRoll(const std::string &prompt)
{
    int roll;
    while (true)
    {
        std::cout << prompt;
        std::cin >> roll;

        // Validate the input
        if (std::cin.fail() || roll < 0 || roll > 10)
        {
            std::cin.clear();                                                   // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a number between 0 and 10.\n";
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

    int firstRoll = 0, secondRoll = 0;

    // Iterate over the 10 frames of the bowling game
    for (int frame = 1; frame <= 10; ++frame)
    {
        std::cout << "\n--- Frame " << frame << " ---\n";
        firstRoll = getValidRoll("Enter first roll: ");
        game->addRoll(firstRoll);

        // If it's not the last frame and the first roll is not a strike, ask for the second roll
        if (frame < 10 && firstRoll != 10)
        {
            secondRoll = getValidRoll("Enter second roll: "); // Get the second roll from user input
            if (firstRoll + secondRoll > 10)
            {
                std::cout << "Invalid input. The total of the first and second rolls cannot exceed 10.\n";
                game->removeLastRoll(); // Remove the last roll (second roll)
                --frame;                // Decrement frame to repeat this frame
                continue;               // Skip to the next iteration of the loop
            }
            game->addRoll(secondRoll);
        }
        // For the 10th frame, the second roll is always taken, and if a strike or spare, a bonus roll may be given
        else if (frame == 10)
        {

            if (firstRoll == 10)
            {
                int bonus1 = getValidRoll("Enter bonus roll 1: ");
                game->addRoll(bonus1);

                int bonus2 = getValidRoll("Enter bonus roll 2: ");
                game->addRoll(bonus2);
            }
            else
            {
                secondRoll = getValidRoll("Enter second roll (Frame 10): ");

                // Validate total ≤ 10 if not a strike
                if (firstRoll + secondRoll > 10)
                {
                    std::cout << "Invalid input. The total of the first and second rolls cannot exceed 10.\n";
                    game->removeLastRoll();         // Remove firstRoll
                    frame--;
                    continue; // Retry frame 10
                }
                game->addRoll(secondRoll);
                if (firstRoll + secondRoll == 10)
                {
                    int bonus = getValidRoll("Enter bonus roll: ");
                    game->addRoll(bonus);
                }
            }
        }

        // Downcast to access printFrameScores
        game->printFrameScores();
    }

    std::cout << "\nFinal Total Score: " << game->calculateScore() << "\n";
    std::cout << "Thank you for playing!" << std::endl;

    return 0;
}
