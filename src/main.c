#include "raylib/raylib.h"

//* Suppress known leaks | Linux and GCC
#if defined(__linux__) && defined(__GNUC__) && defined(ENABLE_ASAN) && defined(ENABLE_UBSAN)
const char* __lsan_default_suppressions() 
{
  return "leak:_XimOpenIM";
}
#endif

#define WINDOW_WIDTH    1200
#define WINDOW_HEIGHT   900
#define WINDOW_TITLE    "DJ Console"

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    while(!WindowShouldClose())
    {

        //* --- Update ---

        //* ...

        //* --------------

        BeginDrawing();
        {
            //* --- Render ---

            //* ...

            //* --------------
        }
        EndDrawing();
    }

    CloseWindow();
}