#include <stdio.h>

// ANSI escape codes for text color
#define BLACK "\x1b[30m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"

// ANSI escape codes for background color
#define _BLACK "\x1b[40m"
#define _RED "\x1b[41m"
#define _GREEN "\x1b[42m"
#define _YELLOW "\x1b[43m"
#define _BLUE "\x1b[44m"
#define _MAGENTA "\x1b[45m"
#define _CYAN "\x1b[46m"
#define _WHITE "\x1b[47m"

// Text styles
#define BOLD_ "\x1b[1m"
#define UNDERLINE_ "\x1b[4m"
#define RESET "\x1b[0m"

#define NONE "_"
#define BG_DEFAULT 18

void clearScreen()
{
    printf("\033[2J");  // Clear entire screen
    printf("\033[0;0H"); // Move cursor to the top-left corner
}

void BG_Color(int color)
{
    printf("\033[48;5;%dm", color);
}

void TEXT_BG(const char *color)
{
    printf("%s", color);
}

void TEXT_Color(const char *color)
{
    printf("%s", color);
}

void ColorChar(const char *Text, const char *BG)
{
    if (Text != NONE)
        printf("%s", Text);

    if (BG != NONE)
        printf("%s", BG);
}

void UnderBold(int underline, int bold)
{
    if (underline)
        printf("\x1b[4m");
    if (bold)
        printf("\x1b[1m");
}

void RESET_Color()
{
    printf("\x1b[0m");
}

void text(const char *Title)
{
    BG_Color(BG_DEFAULT);
    clearScreen();

    UnderBold(0, 1);
    ColorChar(RED, _WHITE);
    printf("                                       \n");
    printf("         %s          \n", Title);
    printf("_______________________________________\n");
    printf("                                       \n\n");
    RESET_Color();
}

void MainTitle(const char *Title)
{
    clearScreen();
    text(Title);
    BG_Color(BG_DEFAULT);
    TEXT_Color(RED);
}
