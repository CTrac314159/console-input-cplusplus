#include <iostream>
#include "constants.h"

// This program calculates the height of a ball falling from a tower with a user-specified height in
// meters. The height is calculated every second.

class TowerFall
{
private:
    double ball_height{}; // Private variable for the ball height

public:

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
        double ballHeight{ height - fall_distance };

        if (ballHeight < 0.0) // Check to see if the ball has reached the ground (height of zero)
            return 0.0;
        else
            return ballHeight;
    }

    void calculateHeights(double tower_height, int second) // Member function that outputs the ball height at a time, takes tower height
                                                           // and the second to start at (second 0 = ball at the tower height)
    {
        do
        {
            ball_height = ballHeight(tower_height, static_cast<double>(second)); // Call the ballHeight member function, assign to ball_height
            
            if (ball_height > 0.0) // If the ball is not on the ground, print the height
                std::cout << "At " << second << " seconds, the height of the ball is " << ball_height << " meters." << '\n';
            else
                std::cout << "At " << second << " seconds, the ball is on the ground." << '\n'; // ball_height = 0.0

            ++second;
        }
        while (ball_height > 0.0); // Ball-on-ground Boolean
    }
};

int main()
{
    TowerFall tower_fall;
    const double tower_height{ tower_fall.towerHeight() }; // Get input tower height from the user
    int second{ 0 }; // Initialize the time increment
    tower_fall.calculateHeights(tower_height, second);

    return 0;
}
