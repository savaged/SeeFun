/* References:
* https://prognotes.net/2016/12/get-widget-pointer-in-callback-function/
* https://prognotes.net/2016/03/gtk-3-c-code-hello-world-tutorial-using-glade-3/ 
*/

#include <string.h>
#include <main.h>
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

void on_button_one_enter_notify_event(GtkButton *button, GtkButton *button_two)
{
    const gchar *text = gtk_button_get_label(button);
    gchar button_one_text[3];
    strcpy(button_one_text, text);
    on_button_enter(button);
    gtk_button_set_label(button_two, button_one_text);
}

void on_button_two_enter_notify_event(GtkButton *button, GtkButton *button_one)
{
    const gchar *text = gtk_button_get_label(button);
    gchar button_two_text[3];
    strcpy(button_two_text, text);
    on_button_enter(button);
    gtk_button_set_label(button_one, button_two_text);
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

