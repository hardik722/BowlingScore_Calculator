#include "Bowling.h"
#include <memory>

int main()
{
     // Using unique_ptr for memory management, ensuring automatic cleanup of the game object when it goes out of scope
    std::unique_ptr<BowlingGame> game = std::make_unique<BowlingGame>();

    int firstRoll = 0, secondRoll = 0;

    // Iterate over the 10 frames of the bowling game
    for (int frame = 1; frame <= 10; ++frame)
    {
        std::cout << "\n--- Frame " << frame << " ---\n";
        std::cout << "Enter first roll: ";
        std::cin >> firstRoll;  // Get the first roll from user input
        game->addRoll(firstRoll);

         // If it's not the last frame and the first roll is not a strike, ask for the second roll
        if (frame < 10 && firstRoll != 10)  
        {
            std::cout << "Enter second roll: ";
            std::cin >> secondRoll;     // Get the second roll from user input
            game->addRoll(secondRoll);
        }
        // For the 10th frame, the second roll is always taken, and if a strike or spare, a bonus roll may be given
        else if (frame == 10)
        {
            std::cout << "Enter second roll: ";
            std::cin >> secondRoll;     // Get the second roll from user input
            game->addRoll(secondRoll);

            // if the result is strick or spare, ask for a bonus roll
            if (firstRoll == 10 || firstRoll + secondRoll == 10)
            {
                int bonusRoll;
                std::cout << "Enter bonus roll: ";
                std::cin >> bonusRoll;
                game->addRoll(bonusRoll);   // Get the bonus roll
            }
        }

        // Downcast to access printFrameScores
        game->printFrameScores();
    }

    std::cout << "\nFinal Total Score: " << game->calculateScore() << "\n";
    std::cout << "Thank you for playing!" << std::endl;

    return 0;
}
