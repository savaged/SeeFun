#ifndef MAIN_H
#define MAIN_H

#include <gtk/gtk.h>

int main(int argc, char *argv[]);

void on_window_main_destroy();

void on_button_one_enter_notify_event(GtkButton *button, GtkButton *button_two);

void on_button_two_enter_notify_event(GtkButton *button, GtkButton *button_one);

void on_button_one_clicked(GtkButton *button, GtkLabel *label_feedback);

void on_button_two_clicked(GtkButton *button, GtkLabel *label_feedback);

void on_button_clicked(GtkButton *button, GtkLabel *label_feedback);

void on_button_enter(GtkButton *button);

#endif /* MAIN_H */

