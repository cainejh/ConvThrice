// Caine Hoffman | ITT-310 | DATE DOES NOT MATTER

// THIS IS A CONVERTER MAINLY.
// I ADDED A LORENZ ATTRACTOR BECAUSE IT IS SOMETHING THAT IS VERY INTERESTING TO ME. IF YOU ARE INTERESTED I RECOMMEND YOUTUBE.


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void asciiToBinary(int asciiValue);
void asciiToHex(int asciiValue);
void binaryToHex(char* binary);
void hexToBinary(char* hex);
void binaryToAscii(char* binary);
void hexToAscii(char* hex);
void removeNewline(char* str);

void processConverter();
void processLorenzAttractor();

void clearScreen();
void loginScreen();

int main() {
    loginScreen();
    int choice;

    printf("Welcome to the Main Program\n");

    while (1) {
        printf("+------------------------+\n");
        printf("|        Main Menu       |\n");
        printf("+------------------------+\n");
        printf("| 1. Converter           |\n");
        printf("| 2. Lorenz Attractor    |\n");
        printf("| 3. Exit                |\n");
        printf("+------------------------+\n");
        printf("Enter choice: ");
        scanf_s("%d", &choice);
        clearScreen(); // Clear the screen before each menu selection

        switch (choice) {
        case 1:
            processConverter();
            break;
        case 2:
            processLorenzAttractor();
            break;
        case 3:
            printf("Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void processConverter() {
    int choice;
    char inputChar;
    char binaryInput[9]; // Assuming 8-bit binary input
    char hexInput[3];    // Assuming 1-byte hexadecimal input

    while (1) {
        printf("+-------------------------+\n");
        printf("|      Converter Menu     |\n");
        printf("+-------------------------+\n");
        printf("| 1. ASCII to Binary      |\n");
        printf("| 2. ASCII to Hexadecimal |\n");
        printf("| 3. Binary to Hexadecimal|\n");
        printf("| 4. Hexadecimal to Binary|\n");
        printf("| 5. Binary to ASCII      |\n");
        printf("| 6. Hexadecimal to ASCII |\n");
        printf("| 7. Back to Main Menu    |\n");
        printf("+-------------------------+\n");
        printf("Enter choice: ");
        scanf_s("%d", &choice);

        clearScreen(); // Clear the screen before each menu selection

        switch (choice) {
        case 1:
            printf("Enter an ASCII character: ");
            scanf_s(" %c", &inputChar, 1);
            asciiToBinary(inputChar);
            break;
        case 2:
            printf("Enter an ASCII character: ");
            scanf_s(" %c", &inputChar, 1);
            asciiToHex(inputChar);
            break;
        case 3:
            printf("Enter an 8-bit binary number: ");
            scanf_s("%8s", binaryInput, (unsigned)_countof(binaryInput));
            binaryToHex(binaryInput);
            break;
        case 4:
            printf("Enter a 2-digit hexadecimal number: ");
            scanf_s("%2s", hexInput, (unsigned)_countof(hexInput));
            hexToBinary(hexInput);
            break;
        case 5:
            printf("Enter an 8-bit binary number: ");
            scanf_s("%8s", binaryInput, (unsigned)_countof(binaryInput));
            binaryToAscii(binaryInput);
            break;
        case 6:
            printf("Enter a 2-digit hexadecimal number: ");
            scanf_s("%2s", hexInput, (unsigned)_countof(hexInput));
            hexToAscii(hexInput);
            break;
        case 7:
            return; // Go back to the main menu
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void processLorenzAttractor() {
    printf("Lorenz Attractor\n");

    // Constants for the Lorenz attractor equations
    double sigma = 10.0;
    double beta = 8.0 / 3.0;
    double rho = 28.0;

    // Initial conditions
    double x = 1.0;
    double y = 1.0;
    double z = 1.0;

    // Parameters for the attractor simulation
    double dt = 0.01; // Time step
    int numSteps = 1000;

    // Simulate and print the Lorenz attractor points
    for (int i = 0; i < numSteps; i++) {
        // Lorenz attractor equations
        double dx = sigma * (y - x) * dt;
        double dy = (x * (rho - z) - y) * dt;
        double dz = (x * y - beta * z) * dt;

        // Update coordinates
        x += dx;
        y += dy;
        z += dz;

        // Scale and translate the attractor for better visualization
        int scaledX = (int)(10 * x) + 50; // Scale x and shift
        int scaledY = (int)(2 * y) + 25;   // Scale y and shift

        // Print the point in the console
        printf("\033[%d;%dH*", scaledY, scaledX);
        fflush(stdout);

        // Pause briefly to observe the attractor
        for (int j = 0; j < 10000; j++)
            ;
    }

    // Wait for user input to return to the menu
    printf("\nPress Enter to return to the menu...");
    while (getchar() != '\n')
        ;
}

void asciiToBinary(int asciiValue) {
    // Convert ASCII to binary
    printf("Binary: ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (asciiValue >> i) & 1);
    }
    printf("\n");
}

void asciiToHex(int asciiValue) {
    // Convert ASCII to hexadecimal
    printf("Hex: 0x%X\n", asciiValue);
}

void binaryToHex(char* binary) {
    // Convert binary to hexadecimal
    printf("Hex: 0x%X\n", strtol(binary, NULL, 2));
}

void hexToBinary(char* hex) {
    // Convert hexadecimal to binary
    printf("Binary: ");
    for (int i = 0; i < 2; i++) {
        switch (hex[i]) {
        case '0':
            printf("0000");
            break;
        case '1':
            printf("0001");
            break;
        case '2':
            printf("0010");
            break;
        case '3':
            printf("0011");
            break;
        case '4':
            printf("0100");
            break;
        case '5':
            printf("0101");
            break;
        case '6':
            printf("0110");
            break;
        case '7':
            printf("0111");
            break;
        case '8':
            printf("1000");
            break;
        case '9':
            printf("1001");
            break;
        case 'A':
        case 'a':
            printf("1010");
            break;
        case 'B':
        case 'b':
            printf("1011");
            break;
        case 'C':
        case 'c':
            printf("1100");
            break;
        case 'D':
        case 'd':
            printf("1101");
            break;
        case 'E':
        case 'e':
            printf("1110");
            break;
        case 'F':
        case 'f':
            printf("1111");
            break;
        default:
            printf("Invalid hexadecimal digit\n");
            return;
        }
    }
    printf("\n");
}

void binaryToAscii(char* binary) {
    // Convert binary to ASCII
    printf("ASCII: %c\n", strtol(binary, NULL, 2));
}

void hexToAscii(char* hex) {
    // Convert hexadecimal to ASCII
    printf("ASCII: %c\n", strtol(hex, NULL, 16));
}

void removeNewline(char* str) {
    // Remove newline character from the end of the string
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }
}

void clearScreen() {
    // Clear the screen in a platform-independent way
#ifdef _WIN32
    system("cls");
#else
    printf("\033c");
#endif
}

void loginScreen() {
    char username[50];

    printf("===== Login Screen =====\n");
    printf("Enter username: ");
    scanf_s("%s", username, (unsigned)_countof(username));

    if (strcmp(username, "Caine") != 0) {
        printf("Invalid username. Exiting...\n");
        exit(1);
    }
}
