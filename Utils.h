#pragma once

void move_cursor(int row, int col);

int get_utf8_char_length(const char* str);

void print_wrapped_text(const char* text, int maxWidth, int startRow, int startCol);

void print_story(const char* text);