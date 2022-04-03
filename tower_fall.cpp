#include <iostream>
#include "constants.h"

// This program calculates the height of a ball falling from a tower with a user-specified height in
// meters. The height is calculated every second.

class TowerFall
{
private:
    double m_ballheight{}; // Private variable for the ball height
    double m_towerheight{}; // Private variable for the tower height
    double m_second{}; // Private variable for the time (make seconds a double type for consistency and to avoid overflow)

public:
    TowerFall(double towerheight = 0.0, int second = 0) : m_towerheight{towerheight}, m_second{static_cast<double>(second)}
    {
        // Constructor to initialize tower height and start time (defaults of 0)
    }

    double findBallHeight() // Calculate fall distance at a particular second given a tower height and second count
    {
        // Using formula: [ fall_distance = u_0 * time + (g * time^2) / 2 ], assuming initial velocity (u_0) = 0
        double fall_distance{ (constants::g * (m_second * m_second)) / 2.0 };
        double ballHeight{ m_towerheight - fall_distance };

        if (ballHeight < 0.0) // Check to see if the ball has reached the ground (height of zero)
            return 0.0;
        else
            return ballHeight;
    }

    void calculateHeights() // Member function that outputs the ball height at a time, takes tower height
                            // and the second to start at (second 0 = ball at the tower height)
    {
        do
        {
            m_ballheight = findBallHeight(); // Call the ballHeight member function, assign to ball_height
            
            if (m_ballheight > 0.0) // If the ball is not on the ground, print the height
                std::cout << "At " << m_second << " seconds, the height of the ball is " << m_ballheight << " meters." << '\n';
            else
                std::cout << "At " << m_second << " seconds, the ball is on the ground." << '\n'; // ball_height = 0.0

            ++m_second;
        }
        while (m_ballheight > 0.0); // Ball-on-ground Boolean
    }
};

int main()
{
    std::cout << "Enter the height of the tower in meters: "; // Get tower height from the user
    double tower_height{};
    std::cin >> tower_height;
    
    int second{ 0 }; // Initialize the time increment
    TowerFall tower_fall{tower_height, second}; // Initialize class object
    tower_fall.calculateHeights();

    return 0;
}
