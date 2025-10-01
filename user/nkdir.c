#include "kernel/types.h"
#include "user/user.h"
#include "kernel/stat.h"

// Terminal control sequences
#define CLEAR_SCREEN "\033[2J"
#define MOVE_CURSOR_TOP_LEFT "\033[H"

#define SCREEN_WIDTH  80
#define SCREEN_HEIGHT 24

// Closed mouth skull
const char *skull_closed[] = {
  "    .-"      "-.   ",
  "   /           \\  ",
  "  |,  .-.  .-.  ,| ",
  "  | )(_o/  \\o_)( | ",
  "  |/     /\\     \\| ",
  "  (_     ^^     _) ",
  "   \\__|IIIIII|__/  ",
  "    | \\IIIIII/ |   ",
  "    \\          /   ",
  "     `--------`    "

};

// Open mouth skull
const char *skull_open[] = {
  "   .-"      "-.    ",
  "   /           \\  ",
  "  |,  .-.  .-.  ,| ",
  "  | )(_o/  \\o_)( | ",
  "  |/     /\\    \\| ",
  "  (_     ^^     _) ",
  "   \\__|IIIIII|__/  ",
  "    |          |   ",
  "    | \\IIIIII/ |   ",
  "    \\          /   ",
  "     `--------`    "
};

#define SKULL_HEIGHT (sizeof(skull_closed) / sizeof(skull_closed[0]))

void print_centered(const char **art) {
    int vertical_padding = (SCREEN_HEIGHT - SKULL_HEIGHT) / 2;

    printf(CLEAR_SCREEN);
    printf(MOVE_CURSOR_TOP_LEFT);

    for (int i = 0; i < vertical_padding; i++) {
        printf("\n");
    }

    for (int i = 0; i < SKULL_HEIGHT; i++) {
        uint line_length = strlen(art[i]);
        int horizontal_padding = (SCREEN_WIDTH - line_length) / 2;

        for (int j = 0; j < horizontal_padding; j++) {
            printf(" ");
        }
        printf("%s\n", art[i]);
    }
}

int main() {
    print_centered(skull_closed);
    sleep(40);  // 400ms

    print_centered(skull_open);
    sleep(40);  // 400ms

    print_centered(skull_closed);
    sleep(80); // 1 second

    exit(0);
}

