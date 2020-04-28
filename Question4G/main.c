/* References:
* https://prognotes.net/2016/12/get-widget-pointer-in-callback-function/
* https://prognotes.net/2016/03/gtk-3-c-code-hello-world-tutorial-using-glade-3/ 
*/

#include <string.h>
//#include <main.h>
#include "main.h"       // use quotes here
#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    GtkBuilder *builder; 
    GtkWidget *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "Question4G.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
        
    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();

    return 0;
}

void on_window_main_destroy()
{
    gtk_main_quit();
}

// Here is where the problem was -- Must pass 3 parameters to this function
// See: https://developer.gnome.org/gtk3/stable/GtkWidget.html#GtkWidget-enter-notify-event
// You were missing the second parameter which should be a GdkEvent pointer, user data must be
//  3rd parameter
//void on_button_one_enter_notify_event(GtkButton *button, GtkButton *button_two)
void on_button_one_enter_notify_event(GtkButton *button, GdkEvent *event, GtkButton *button_two)
{
    const gchar *text = gtk_button_get_label(button);
    gchar *button_one_text;
    button_one_text = strdup(text);
    on_button_enter(button);
    gtk_button_set_label(button_two, button_one_text);
    
    free(button_one_text);  // must free memory
}

// Fixed this one, same as above
void on_button_two_enter_notify_event(GtkButton *button, GdkEvent *event, GtkButton *button_one)
{
    const gchar *text = gtk_button_get_label(button);
    gchar *button_two_text;
    button_two_text = strdup(text);
    on_button_enter(button);
    gtk_button_set_label(button_one, button_two_text);
    
    free(button_two_text);  // must free memory
}

void on_button_one_clicked(GtkButton *button, GtkLabel *label_feedback)
{
    on_button_clicked(button, label_feedback);
}

void on_button_two_clicked(GtkButton *button, GtkLabel *label_feedback)
{
    on_button_clicked(button, label_feedback);
}

void on_button_clicked(GtkButton *button, GtkLabel *label_feedback)
{
    gtk_label_set_text(label_feedback, "Yes Indeed!");
}

void on_button_enter(GtkButton *button)
{
    const gchar *yes = "Yes";
    const gchar *text = gtk_button_get_label(button);
    if (strcmp(text, yes) != 0)
    {
        gtk_button_set_label(button, yes);
    }
}

