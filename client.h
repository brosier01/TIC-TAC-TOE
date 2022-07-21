#ifndef SERVER_H
#define SERVER_H

#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <time.h>

int turn;
char game[9];

void init_grid(void);
void print_end_game(GtkButton* widget, gpointer data);
void button_clicked(GtkButton* widget, gpointer data);
int check_end_game(void);

#endif