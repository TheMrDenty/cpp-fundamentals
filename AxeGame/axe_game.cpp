#include "raylib.h"

int main()
{
    /* // debugging variables
    float root_beer = 1.99;

    double cheese_burger{5.99};

    bool shouldHaveLunch{};

    // comparison operators
    // false
    bool equal{4 == 9};
    // true
    bool notEqual{4 != 9};
    // true
    bool less{4 < 9};
    // false
    bool greater{4 > 9};
    // true
    bool lessEqual{4 <= 9};
    // false
    bool greaterEqual{4 >= 9}; */

    // window dimensions
    int width{800};
    int length{450};
    InitWindow(width, length, "Axe Game");

    // circle coordinates
    int circle_x{175};
    int circle_y{100};

    // axe coordinates
    int axe_x{400};
    int axe_y{0};

    int direction{10};

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // Game logic begins

        DrawCircle(circle_x, circle_y, 25, BLUE);

        DrawRectangle(axe_x, axe_y, 50, 50, RED);

        // moves the axe
        axe_y += direction;
        if (axe_y > 450 || axe_y < 0)
        {
            direction = -direction;
        }

        // moves the circle
        if (IsKeyDown(KEY_D) && circle_x < 800)
        {
            circle_x += 10;
        }

        if (IsKeyDown(KEY_A) && circle_x > 0)
        {
            circle_x -= 10;
        }

        // Game logic ends
        EndDrawing();
    }
}