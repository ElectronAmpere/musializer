// Pre compiled headers
#include <stdio.h>
#include <raylib.h>

// Source headers
#include "plugins/plugins.h"

typedef struct {
  int posX;
  int posY;
  int width;
  int height;
  Color color_background;
  Color color_progress;
  Color color_outline;
} ProgressBar;

void AppDrawProgressBar(ProgressBar *progressbar, float progress)
{
  DrawRectangle(progressbar->posX,
		progressbar->posY,
		progressbar->width,
		progressbar->height,
		progressbar->color_background);

  progress = (progress * (float) progressbar->width);
  DrawRectangle(progressbar->posX,
		progressbar->posY,
	        (int)progress,
		progressbar->height,
		progressbar->color_progress);
  
  DrawRectangleLines(progressbar->posX,
		     progressbar->posY,
		     progressbar->width,
		     progressbar->height,
		     progressbar->color_outline);
}

int main()
{
  char *window_title = "Music App";
  char *music_file = "music/SalaarFinalPunch.ogg";
  int pause = 0;
  float master_volume = 1.0f;
  float time_played = 0.0f;
  ProgressBar progress_bar = {0};

  pluginsHelloMessage();
  return (0); //Temporary

#if 0
  InitWindow(800, 450, window_title);
  SetTargetFPS(60);
  InitAudioDevice();
  Music music = LoadMusicStream(music_file);
  PlayMusicStream(music);
  SetMasterVolume(master_volume);

  progress_bar.posX = 200;
  progress_bar.posY = 200;
  progress_bar.width = 400;
  progress_bar.height = 12;
  progress_bar.color_background = BLACK;
  progress_bar.color_progress = WHITE;
  progress_bar.color_outline = WHITE;

  while(!WindowShouldClose())
  {
    UpdateMusicStream(music);
    
    if (IsKeyPressed(KEY_SPACE)){

      pause = !pause;
      
      if (pause) PauseMusicStream(music);
      else ResumeMusicStream(music);
    }

    time_played = GetMusicTimePlayed(music)/GetMusicTimeLength(music);

    if (time_played > 1.0f) time_played = 1.0f;

    BeginDrawing();

       ClearBackground(BLACK);
       DrawText("Music Is Playing...", 200, 150, 20, LIGHTGRAY);
       AppDrawProgressBar(&progress_bar, time_played);
       DrawText("Press Space to Play/Pause", 200, 250, 20, MAGENTA);
       
    EndDrawing();
  }

  UnloadMusicStream(music);
  CloseAudioDevice();
  CloseWindow();
  
  return (0);

#endif
}
