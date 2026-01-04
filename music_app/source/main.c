#include <raylib.h>

#define RAYGUI_IMPLEMENTATION

#include "external/raygui.h"

int main() {

    InitWindow(400, 200, "raygui - control");

    SetTargetFPS(60);

    bool showMessageBox = false;

    while (!WindowShouldClose()) {
        BeginDrawing();
            
            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

            if (GuiButton((Rectangle){24, 24, 120, 30}, "#191#Show Message"))
                showMessageBox = true;

            if (showMessageBox) {
                int result = GuiMessageBox((Rectangle){85, 70, 250, 100},
                                            "#191#MessageBox", "Hi! This is a message!", "Nice;Cool");

                if (result >= 0) showMessageBox = false;
            }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}