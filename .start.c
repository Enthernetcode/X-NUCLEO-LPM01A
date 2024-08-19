#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <termios.h>
#endif

// Color Codes
#define RESET   "\x1b[0m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"

// Function to print text with color
void printColored(const char* text, const char* color) {
    printf("%s%s%s", color, text, RESET);
}

// Function to print text slowly for better user interaction
void slowPrint(const char* text, int delay) {
    for (const char* p = text; *p != '\0'; p++) {
        putchar(*p);
        fflush(stdout);
#ifdef _WIN32
        Sleep(delay / 1000);
#else
        usleep(delay);
#endif
    }
}

// Introduction Section
void introduction() {
    printColored("Welcome to the STM32 Power Optimization Tutorial!\n", CYAN);
    slowPrint("In this tutorial, you will learn various techniques to optimize power consumption in STM32 microcontrollers.\n\n", 30000);
}

// Practice Section
void practiceExercises() {
    printColored("\nPractice Exercises:\n", MAGENTA);
    slowPrint("Let's put your knowledge into practice with some coding exercises.\n\n", 30000);

    printColored("1. Implement STOP mode and measure the power consumption difference:\n", GREEN);
    slowPrint("In STOP mode, the CPU halts all activities and only resumes after a wake-up event.\n", 30000);
    slowPrint("Implement the following code to enter STOP mode:\n", 30000);

    printColored("Example Code:\n", BLUE);
    printf(
        "void practiceStopMode() {\n"
        "    __HAL_RCC_PWR_CLK_ENABLE();\n"
        "    HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);\n"
        "    // System resumes here after a wake-up event (e.g., interrupt)\n"
        "}\n"
    );

    printColored("\n2. Experiment with peripheral gating:\n", GREEN);
    slowPrint("Disable clocks to unused peripherals to reduce power consumption.\n", 30000);
    slowPrint("Try the following example:\n", 30000);

    printColored("Example Code:\n", BLUE);
    printf(
        "void practicePeripheralGating() {\n"
        "    __HAL_RCC_GPIOA_CLK_DISABLE();  // Disable GPIOA clock\n"
        "    __HAL_RCC_ADC_CLK_DISABLE();    // Disable ADC clock\n"
        "    // Add more peripherals as needed\n"
        "}\n"
    );

    printColored("\n3. Implement clock scaling and voltage scaling:\n", GREEN);
    slowPrint("Reduce system clock frequency and enable voltage scaling to save power.\n", 30000);
    slowPrint("Here’s an example code:\n", 30000);

    printColored("Example Code:\n", BLUE);
    printf(
        "void optimizePowerConsumption() {\n"
        "    HAL_RCC_DeInit();\n"
        "    RCC_OscInitTypeDef RCC_OscInitStruct = {0};\n"
        "    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};\n\n"
        "    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;\n"
        "    RCC_OscInitStruct.HSIState = RCC_HSI_ON;\n"
        "    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;\n"
        "    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;\n"
        "    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {\n"
        "        while(1);\n"
        "    }\n\n"
        "    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK;\n"
        "    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;\n"
        "    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;\n"
        "    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;\n"
        "    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK) {\n"
        "        while(1);\n"
        "    }\n\n"
        "    HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE2);\n"
        "}\n"
    );
}

// Quiz Section
void finalQuiz() {
    int answer;

    printColored("\nFinal Quiz:\n", YELLOW);

    // Question 1
    slowPrint("1. What is the primary benefit of using low-power modes in STM32 microcontrollers?\n", 30000);
    slowPrint("   1) To reduce CPU clock speed.\n", 30000);
    slowPrint("   2) To reduce power consumption.\n", 30000);
    slowPrint("   3) To increase processing power.\n", 30000);
    slowPrint("Your answer: ", 30000);
    scanf("%d", &answer);
    if (answer == 2) {
        printColored("Correct! Low-power modes are designed to reduce power consumption.\n", GREEN);
    } else {
        printColored("Incorrect. The correct answer is 2) To reduce power consumption.\n", RED);
    }

    // Question 2
    slowPrint("\n2. Which STM32 low-power mode allows the system to wake up from an external interrupt?\n", 30000);
    slowPrint("   1) STOP mode\n", 30000);
    slowPrint("   2) SLEEP mode\n", 30000);
    slowPrint("   3) RUN mode\n", 30000);
    slowPrint("Your answer: ", 30000);
    scanf("%d", &answer);
    if (answer == 1) {
        printColored("Correct! STOP mode allows the system to wake up from an external interrupt.\n", GREEN);
    } else {
        printColored("Incorrect. The correct answer is 1) STOP mode.\n", RED);
    }

    // Question 3
    slowPrint("\n3. How can peripheral gating help in reducing power consumption?\n", 30000);
    slowPrint("   1) By increasing the clock speed of the peripheral.\n", 30000);
    slowPrint("   2) By disabling the clock to unused peripherals.\n", 30000);
    slowPrint("   3) By enabling the clock to all peripherals.\n", 30000);
    slowPrint("Your answer: ", 30000);
    scanf("%d", &answer);
    if (answer == 2) {
        printColored("Correct! Peripheral gating helps reduce power consumption by disabling the clocks to unused peripherals.\n", GREEN);
    } else {
        printColored("Incorrect. The correct answer is 2) By disabling the clock to unused peripherals.\n", RED);
    }

    // Question 4
    slowPrint("\n4. What happens when you scale down the system clock frequency in an STM32 microcontroller?\n", 30000);
    slowPrint("   1) The power consumption increases.\n", 30000);
    slowPrint("   2) The power consumption decreases.\n", 30000);
    slowPrint("   3) The performance improves.\n", 30000);
    slowPrint("Your answer: ", 30000);
    scanf("%d", &answer);
    if (answer == 2) {
        printColored("Correct! Scaling down the system clock frequency generally reduces power consumption.\n", GREEN);
    } else {
        printColored("Incorrect. The correct answer is 2) The power consumption decreases.\n", RED);
    }

    // Question 5
    slowPrint("\n5. Which mode should you use if you need the lowest possible power consumption but still want to wake up on an event?\n", 30000);
    slowPrint("   1) SLEEP mode\n", 30000);
    slowPrint("   2) STOP mode\n", 30000);
    slowPrint("   3) STANDBY mode\n", 30000);
    slowPrint("Your answer: ", 30000);
    scanf("%d", &answer);
    if (answer == 3) {
        printColored("Correct! STANDBY mode is the lowest power mode that can wake up on an event.\n", GREEN);
    } else {
        printColored("Incorrect. The correct answer is 3) STANDBY mode.\n", RED);
    }
}

// Main function
int main() {
    introduction();  // Introduction to the tutorial
    practiceExercises();  // Practice exercises for hands-on learning
    finalQuiz();  // Test your knowledge with the final quiz

    printColored("\nCongratulations! You've completed the STM32 Power Optimization Tutorial.\n", CYAN);
    slowPrint("Keep practicing these techniques to master power optimization on STM32 microcontrollers.\n", 30000);
    slowPrint("Don't forget to explore advanced topics and additional resources to enhance your skills!\n", 30000);

    return 0;
}
