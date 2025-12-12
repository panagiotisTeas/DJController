#include "raylib/raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raylib/raygui.h"

#include "ui/panels/browser_panel.h"

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
    
    UIBrowserPanelData* data = (UIBrowserPanelData*)malloc(sizeof(UIBrowserPanelData)); 
    data->color = GRAY;
    data->bounds = (Rectangle){0, 0, 100, 100};
    UIComponent* browser_panel = createBrowserPanel(data);

    UIBrowserPanelData* data_ = (UIBrowserPanelData*)malloc(sizeof(UIBrowserPanelData)); 
    data_->color = RED;
    data_->bounds = (Rectangle){10, 10, 100, 100};
    UIComponent* browser_panel_ = createBrowserPanel(data_);

    addUIComponent(browser_panel, browser_panel_);

    while(!WindowShouldClose())
    {

        //* --- Update ---

        browser_panel->update(browser_panel);

        //* --------------

        BeginDrawing();
        {
            //* --- Render ---

            browser_panel->draw(browser_panel);

            //* --------------
        }
        EndDrawing();
    }

    destroyUIComponent(browser_panel);
    CloseWindow();
}