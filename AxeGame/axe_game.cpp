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
    int cicrle_radius{25};

    // circle edges
    int l_circle_x{circle_x - cicrle_radius};
    int r_circle_x{circle_x + cicrle_radius};
    int u_circle_y{circle_y - cicrle_radius};
    int b_circle_y{circle_y + cicrle_radius};

    // axe coordinates
    int axe_x{400};
    int axe_y{0};
    int axe_length{50};

    // axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};

    int direction{10};

    // collision detection
    bool collision_with_axe =
        (b_axe_y >= u_circle_y) &&
        (u_axe_y <= b_circle_y) &&
        (l_axe_x <= r_circle_x) &&
        (r_axe_x >= l_circle_x);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (collision_with_axe)
        {
            DrawText("Game Over!", 400, 225, 20, RED);
        }
        else
        {
            // Game logic begins

            // update the edges
            // circle
            l_circle_x = circle_x - cicrle_radius;
            r_circle_x = circle_x + cicrle_radius;
            u_circle_y = circle_y - cicrle_radius;
            b_circle_y = circle_y + cicrle_radius;

            // axe
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;

            // update collision with axe
            collision_with_axe =
                (b_axe_y >= u_circle_y) &&
                (u_axe_y <= b_circle_y) &&
                (l_axe_x <= r_circle_x) &&
                (r_axe_x >= l_circle_x);

            DrawCircle(circle_x, circle_y, cicrle_radius, BLUE);

            DrawRectangle(axe_x, axe_y, 50, axe_length, RED);

            // moves the axe
            axe_y += direction;
            if (axe_y > length || axe_y < 0)
            {
                direction = -direction;
            }

            // moves the circle
            if (IsKeyDown(KEY_D) && circle_x < width)
            {
                circle_x += 10;
            }

            if (IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x -= 10;
            }

            // Game logic ends
        }
        EndDrawing();
    }
}