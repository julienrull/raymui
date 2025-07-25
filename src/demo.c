#include <stdlib.h>
#include <stdio.h>

#include "raylib.h"
#include "raymui.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);
    mu_Context *ctx = malloc(sizeof(mu_Context));
    raymui_init(ctx);
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            raymui_begin(ctx);
            if (mu_begin_window(ctx, "My Window", mu_rect(10, 10, 140, 86))) {
              mu_layout_row(ctx, 2, (int[]) { 60, -1 }, 0);
            
              mu_label(ctx, "First:");
              if (mu_button(ctx, "Button1")) {
                printf("Button1 pressed\n");
              }
            
              mu_label(ctx, "Second:");
              if (mu_button(ctx, "Button2")) {
                mu_open_popup(ctx, "My Popup");
              }
            
              if (mu_begin_popup(ctx, "My Popup")) {
                mu_label(ctx, "Hello world!");
                mu_end_popup(ctx);
              }
            
              mu_end_window(ctx);
            }
            raymui_end(ctx);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
