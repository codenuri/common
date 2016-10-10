// module      : codenuri.c

#include <windows.h>

void cn_set_cursor_pos(int x, int y)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void cn_get_cursor_pos(int *px, int *py)
{
    CONSOLE_SCREEN_BUFFER_INFO cur_info;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur_info);

    *px = cur_info.dwCursorPosition.X;
    *py = cur_info.dwCursorPosition.Y;
}

void cn_hide_cursor()
{
    CONSOLE_CURSOR_INFO cur_info;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur_info);
    cur_info.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur_info);
}

void cn_show_cursor()
{
    CONSOLE_CURSOR_INFO cur_info;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur_info);
    cur_info.bVisible = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur_info);
}

void cn_sleep(int ms) { Sleep(ms); }
void cn_clrscr() { system("cls"); }
