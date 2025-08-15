#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// Utility: Get validated integer input within a range
int get_valid_int(const char *prompt, int min, int max) {
    int val;
    char buf[64];
    while (1) {
        printf("%s", prompt);
        if (fgets(buf, sizeof(buf), stdin) == NULL) continue;
        if (sscanf(buf, "%d", &val) == 1 && val >= min && val <= max) break;
        printf("Invalid input. Enter a value between %d and %d.\n", min, max);
    }
    return val;
}

// Utility: Mix entropy from multiple sources
double mix_entropy(int temp, int userRand, unsigned int sysRand) {
    double t = temp + userRand + sysRand;
    double nonlinear = sin(t) * cos(userRand) * log(t + 1.0);
    double mixed = (temp * userRand) ^ sysRand;
    double sqrt_part = sqrt(fabs(nonlinear * mixed) + 1.0);
    double entropySeed = sqrt_part * (mixed + nonlinear + sysRand);
    return entropySeed;
}

// Generate random coordinates and entropic number
void generate_entropy(int temp, int userRand) {
    unsigned int sysRand = (unsigned int)rand();
    double entropySeed = mix_entropy(temp, userRand, sysRand);

    // Latitude/Longitude
    double lat = fmod(entropySeed, 180.0) - 90.0;
    double lon = fmod(entropySeed * 3.14159, 360.0) - 180.0;

    // Final random number (5 digits)
    double finalRand = fabs(sin(entropySeed + sysRand) * 100000.0 + cos(entropySeed) * 50000.0);
    int entropicNum = (int)fmod(finalRand, 99999);

    printf("\n📍 Random Coordinates Generated:\n");
    printf("Latitude: %.6f\n", lat);
    printf("Longitude: %.6f\n", lon);
    printf("\n🔐 Final Entropic Random Number: %05d\n", entropicNum);
    printf("=============================================================\n");
}

int main() {
    srand((unsigned int)time(NULL));
    printf("===== DEG-C v2 - Dheeraj's Entropy Generator (Improved C Version) =====\n");

    bool again = true;
    while (again) {
        int temperature = get_valid_int("Enter a temperature value (manual/random, -100 to 100): ", -100, 100);
        int userRand = get_valid_int("Enter a random number (1–99): ", 1, 99);

        generate_entropy(temperature, userRand);

        printf("Run again? (y/n): ");
        char choice[8];
        if (fgets(choice, sizeof(choice), stdin) && (choice[0] == 'y' || choice[0] == 'Y')) {
            again = true;
        } else {
            again = false;
        }
    }
    printf("Thank you for using DEG-C v2!\n");
    return 0;
}
