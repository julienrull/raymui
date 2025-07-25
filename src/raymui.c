#include "raymui.h"

static int raymui_get_text_height(mu_Font font) {
  return 14;
}

static int raymui_get_text_width(mu_Font font, const char *text, int len) {
  return MeasureText(text, raymui_get_text_height(font));
}



static void raymui_draw_rect(mu_Rect rect, mu_Color color) {
    DrawRectangle(rect.x, rect.y, rect.w, rect.h, (Color){ color.r, color.g, color.b, color.a });
}


static void raymui_draw_text(const char *text, mu_Vec2 pos, mu_Color color) {
    DrawText(text, pos.x, pos.y, raymui_get_text_height(NULL), (Color){ color.r, color.g, color.b, color.a });
}


static void raymui_draw_icon(int id, mu_Rect rect, mu_Color color) {
      char *icon = "?";
      switch (id) {
      case MU_ICON_CLOSE: {
        icon = "x";
      } break;
      case MU_ICON_CHECK: {
        icon = "*";
      } break;
      case MU_ICON_COLLAPSED: {
        icon = "+";
      } break;
      case MU_ICON_EXPANDED: {
        icon = "-";
      } break;
      default:
        assert(0 && "unreachable");
      }
      DrawText(icon, rect.x, rect.y, rect.h, (Color){ color.r, color.g, color.b, color.a });
}




static void raymui_set_clip_rect(mu_Rect rect) {
    EndScissorMode();   
    BeginScissorMode(rect.x, rect.y , rect.w, rect.h);
}

static void raymui_inputs(mu_Context *ctx)
{
        Vector2 wheel = GetMouseWheelMoveV();
        int curr_mouse_x = GetMouseX();
        int curr_mouse_y = GetMouseY();
        mu_input_mousemove(ctx, curr_mouse_x, curr_mouse_y);
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            mu_input_mousedown(ctx, curr_mouse_x, curr_mouse_y, MU_MOUSE_LEFT);
        }
        if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        {
            mu_input_mousedown(ctx, curr_mouse_x, curr_mouse_y, MU_MOUSE_RIGHT);
        }
        if(IsMouseButtonDown(MOUSE_BUTTON_MIDDLE))
        {
            mu_input_mousedown(ctx, curr_mouse_x, curr_mouse_y, MU_MOUSE_MIDDLE);
        }
        if(IsMouseButtonUp(MOUSE_BUTTON_LEFT))
        {
            mu_input_mouseup(ctx, curr_mouse_x, curr_mouse_y, MU_MOUSE_LEFT);
        }
        if(IsMouseButtonUp(MOUSE_BUTTON_RIGHT))
        {
            mu_input_mouseup(ctx, curr_mouse_x, curr_mouse_y, MU_MOUSE_RIGHT);
        }
        if(IsMouseButtonUp(MOUSE_BUTTON_MIDDLE))
        {
            mu_input_mouseup(ctx, curr_mouse_x, curr_mouse_y, MU_MOUSE_MIDDLE);
        }
        mu_input_scroll(ctx, wheel.x, wheel.y);


        if(IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT))
        {
            mu_input_keydown(ctx, MU_KEY_SHIFT);
        }
        if(IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL))
        {
            mu_input_keydown(ctx, MU_KEY_CTRL);
        }
        if(IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL))
        {
            mu_input_keydown(ctx, MU_KEY_CTRL);
        }
        if(IsKeyDown(KEY_LEFT_ALT) || IsKeyDown(KEY_RIGHT_ALT))
        {
            mu_input_keydown(ctx, MU_KEY_ALT);
        }
        if(IsKeyDown(KEY_BACKSPACE))
        {
            mu_input_keydown(ctx, MU_KEY_BACKSPACE);
        }
        if(IsKeyDown(KEY_ENTER))
        {
            mu_input_keydown(ctx, MU_KEY_RETURN);
        }


        if(IsKeyUp(KEY_LEFT_SHIFT) || IsKeyUp(KEY_RIGHT_SHIFT))
        {
            mu_input_keyup(ctx, MU_KEY_SHIFT);
        }
        if(IsKeyUp(KEY_LEFT_CONTROL) || IsKeyUp(KEY_RIGHT_CONTROL))
        {
            mu_input_keyup(ctx, MU_KEY_CTRL);
        }
        if(IsKeyUp(KEY_LEFT_CONTROL) || IsKeyUp(KEY_RIGHT_CONTROL))
        {
            mu_input_keyup(ctx, MU_KEY_CTRL);
        }
        if(IsKeyUp(KEY_LEFT_ALT) || IsKeyUp(KEY_RIGHT_ALT))
        {
            mu_input_keyup(ctx, MU_KEY_ALT);
        }
        if(IsKeyUp(KEY_BACKSPACE))
        {
            mu_input_keyup(ctx, MU_KEY_BACKSPACE);
        }
        if(IsKeyUp(KEY_ENTER))
        {
            mu_input_keyup(ctx, MU_KEY_RETURN);
        }

}

int raymui_init(mu_Context *ctx)
{
    if(!ctx) return -1;
    mu_init(ctx);
    ctx->text_width = raymui_get_text_width;
    ctx->text_height = raymui_get_text_height;
    return 0;
}
void raymui_begin(mu_Context *ctx)
{
    raymui_inputs(ctx);
    mu_begin(ctx);
}
void raymui_end(mu_Context *ctx)
{
    mu_end(ctx);
    mu_Command *cmd = NULL;
    while (mu_next_command(ctx, &cmd)) {
        if (cmd->type == MU_COMMAND_TEXT) {
          raymui_draw_text(cmd->text.str, cmd->text.pos, cmd->text.color);
        }
        if (cmd->type == MU_COMMAND_RECT) {
          raymui_draw_rect(cmd->rect.rect, cmd->rect.color);
        }
        if (cmd->type == MU_COMMAND_ICON) {
          raymui_draw_icon(cmd->icon.id, cmd->icon.rect, cmd->icon.color);
        }
        if (cmd->type == MU_COMMAND_CLIP) {
          raymui_set_clip_rect(cmd->clip.rect);
        }
    }
}
