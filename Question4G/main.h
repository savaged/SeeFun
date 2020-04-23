#ifndef MAIN_H
#define MAIN_H

#include <gtk/gtk.h>

typedef struct 
{
    GtkWidget *label_feedback;
    GtkWidget *button_one;
    GtkWidget *button_two;
} app_widgets;

int main(int argc, char *argv[]);

void on_window_main_destroy();

void on_button_one_enter_notify_event(GtkButton *button, app_widgets *widgets);

void on_button_two_enter_notify_event(GtkButton *button, app_widgets *widgets);

void on_button_one_clicked(GtkButton *button, app_widgets *widgets);

void on_button_two_clicked(GtkButton *button, app_widgets *widgets);

void on_button_clicked(GtkButton *button, app_widgets *widgets);

void on_button_enter(GtkButton *button);

#endif /* MAIN_H */

