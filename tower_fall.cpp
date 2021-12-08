#include <iostream>
#include "constants.h"

// This program calculates the height of a ball falling from a tower with a user-specified height in
// meters. The height is calculated every second.

double towerHeight() // Get tower height from the user
{
    std::cout << "Enter the height of the tower in meters: ";
    double height{};
    std::cin >> height;

    return height;
}

double ballHeight(double height, double seconds) // Calculate fall distance at a particular second given 
                                                 // a tower height and second count
{
    // Using formula: [ fall_distance = u_0 * time + (g * time^2) / 2 ], assuming initial velocity (u_0) = 0
    double fall_distance{ (constants::g * (seconds * seconds)) / 2.0 };
    double ball_height{ height - fall_distance };

    if (ball_height < 0.0) // Check to see if the ball has reached the ground (height of zero)
        return 0.0;
    else
        return ball_height;
}

bool calculatePrint(double tower_height, int seconds)
{
    double ball_height{ ballHeight(tower_height, static_cast<double>(seconds)) }; // Call the ballHeight function

    if (ball_height > 0.0) // If the ball is not on the ground, print the height
        std::cout << "At " << seconds << " seconds, the height of the ball is " << ball_height << " meters." << '\n';
    else
        std::cout << "At " << seconds << " seconds, the ball is on the ground." << '\n';

    return (ball_height == 0.0); // Return the ball-on-ground Boolean
}

int main()
{
    const double tower_height{ towerHeight() }; // Get input tower height from the user
    int seconds{ 0 }; // Initialize the time increment
    bool onGround{ false }; // Initialize Boolean ball-on-ground variable

    do
    {
        onGround = calculatePrint(tower_height, seconds++);
    }

    while (!onGround); // Continue calculating the height until the ball reaches the ground

    return 0;
}
