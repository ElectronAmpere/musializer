#include <stdio.h>
#include <raylib.h>

int main()
{
  int width = 800;
  int height = 450;
  char *title = "This is raylib window";
  Color backgoround_clr = RAYWHITE;
  Color title_clr = LIGHTGRAY;
  InitWindow(width, height, title);

  while (!WindowShouldClose()){
    BeginDrawing();
       ClearBackground(backgoround_clr);
       DrawText(title,190, 200, 20,title_clr);
    EndDrawing();
  }

  CloseWindow();
  
  return (0);
}
