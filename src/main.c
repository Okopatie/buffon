#include "buffon.h"

void DrawButton(Rectangle rect, const char* text, Color fill_color, Color text_color, int font_size) {
    DrawRectangleRec(rect, fill_color);
    DrawText(text, rect.x + 10, rect.y + 10, font_size, text_color);
}


int main () {
    srand((unsigned)time(NULL));
    StickList *sl = CreateStickList();
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Buffon");
    int board_start_x = (SCREEN_WIDTH - BOARD_WIDTH) / 2;
    int board_start_y = (SCREEN_HEIGHT - BOARD_HEIGHT) / 2;
    int num_lines = BOARD_HEIGHT / STICK_LENGTH;
    double pi_approx;

    char pi_string[15];
    Rectangle drop_button_rect = {
	SCREEN_WIDTH / 4, Y_PADDING, 150, 50
    };
    Rectangle reset_button_rect = {
	SCREEN_WIDTH / 2, Y_PADDING, 150, 50
    };

    Vector2 mouse_point;



        while (!WindowShouldClose())
	{
	    mouse_point = GetMousePosition();
	    if (CheckCollisionPointRec(mouse_point, drop_button_rect)) {
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
		    AddToStickList(sl);
		}
	    }
	    if (CheckCollisionPointRec(mouse_point, reset_button_rect)) {
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
		    free(sl->list);
		    free(sl);
		    sl = CreateStickList();
		}
	    }

	    BeginDrawing();
	    ClearBackground(BLACK);
	    for (int i = -1; i < BOARD_HEIGHT; i += STICK_LENGTH) {
		DrawLine(board_start_x, board_start_y + i, board_start_x + BOARD_WIDTH, board_start_y + i, WHITE);
		DrawLine(board_start_x, board_start_y + i+1, board_start_x + BOARD_WIDTH, board_start_y + i + 1, WHITE);
	    }
	    for (int i = 0; i < sl->len; i++) {
		DrawLine((int)sl->list[i].x1 + board_start_x,
			 (int)sl->list[i].y1 + board_start_y,
			 (int)sl->list[i].x2 + board_start_x,
			 (int)sl->list[i].y2 + board_start_y,
			 sl->list[i].crossing ? GREEN : RED);
	    }
	    pi_approx = sl->len > 0 ? 2 / ((double)sl->num_crossing / (double)sl->len) : 0;
	    snprintf(pi_string, 15, "%s%lf", "pi = ", pi_approx);
	    DrawText(pi_string, 20, 20, 30, WHITE);
	    DrawButton(drop_button_rect, "DROP", WHITE, BLACK, 30);
	    DrawButton(reset_button_rect, "RESET", WHITE, BLACK, 30);


	    EndDrawing();
	}

    // destroy the window and cleanup the OpenGL context
    CloseWindow();
    return 0;
}
