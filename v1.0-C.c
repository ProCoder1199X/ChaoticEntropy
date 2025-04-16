#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double generate_entropy(int temp, int userRand) {
    // Step 1: Non-linear transformations 
    int mix1 = (temp * userRand) + (userRand * userRand) - (temp / 2);
    double sqrt_part = sqrt((double)(temp + userRand + 1));
    double entropySeed = mix1 * sqrt_part;

    // Step 2: Generate latitudes and longitudes  from entropy
    double lat = fmod(entropySeed, 180.0) - 90.0;  // Range -90 to +90
    double lon = fmod(entropySeed * 3.14159, 360.0) - 180.0;  // Range -180 to +180

    printf("\n📍 Random Coordinates Generated:\n");
    printf("Latitude: %.6f\n", lat);
    printf("Longitude: %.6f\n", lon);

    // Step 3: THE FINAL random num
    double finalRand = fabs(sin(entropySeed) * 10000.0);
    return fmod(finalRand, 99999); // Keep it within 5-digit range
}

int main() {
    int temperature, userRand;

    printf("===== DEG-C v1 - Dheeraj's Entropy Generator (C Version) =====\n");

    // Manual  temperature input by user,
    printf("Enter a temperature value (manual/random): ");
    scanf("%d", &temperature);

    // Manual user input random number
    printf("Enter a random number (1–99): ");
    scanf("%d", &userRand);

    if (userRand < 1 || userRand > 99) {
        printf("Invalid input. Must be between 1 and 99.\n");
        return 1;
    }

    // Generating entropy-based value
    double result = generate_entropy(temperature, userRand);

    printf("\n🔐 Final Entropic Random Number: %.0f\n", result);
    printf("=============================================================\n");

    return 0;
}
