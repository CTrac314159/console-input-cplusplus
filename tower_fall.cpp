#include <iostream>

// This program calculates the height of a ball falling from a tower with a user-specified height in
// meters. The height is calculated every second up to 5 seconds. Function calls past this time can be 
// added in main() to account for height input where the ball does not reach the ground before 5 seconds.

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
    constexpr double g{ 9.81 }; // Define gravity as a constant, cannot be changed

    // Using formula: [ fall_distance = u_0 * time + (g * time^2) / 2 ], assuming initial velocity (u_0) = 0
    double fall_distance{ (g * (seconds * seconds)) / 2.0 };
    double ball_height{ height - fall_distance };

    return ball_height;
}

void print_Height(double ball_height, double seconds) // Output ball height every second until it reaches the ground
                                                      // given a ball height and second count. 
{
    if (ball_height > 0.0)
        std::cout << "At " << static_cast<int>(seconds) << " seconds, the height of the ball is " << ball_height << " meters" << '\n';
    else
        std::cout << "At " << static_cast<int>(seconds) << " seconds, the ball is on the ground" << '\n';
}

void calculatePrint(double tower_height, int seconds)
{
    double ball_height{ ballHeight(tower_height, static_cast<double>(seconds)) }; // Cast the second count to a float for calculations
    print_Height(ball_height, static_cast<double>(seconds));
}

int main()
{
    const double tower_height{ towerHeight() }; // Get input tower height from the user

    calculatePrint(tower_height, 0);
    calculatePrint(tower_height, 1);
    calculatePrint(tower_height, 2);
    calculatePrint(tower_height, 3);
    calculatePrint(tower_height, 4);
    calculatePrint(tower_height, 5);

    return 0;
}