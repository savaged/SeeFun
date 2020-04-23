/* References:
* https://prognotes.net/2016/12/gtk-glade-get-pointers-to-widgets/
* https://prognotes.net/2016/03/gtk-3-c-code-hello-world-tutorial-using-glade-3/ 
*/

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

/*

void on_button_one_enter_notify_event(GtkButton *button, gpointer user_data)
{
    on_button_enter(button);
}

void on_button_two_enter_notify_event(GtkButton *button, gpointer user_data)
{
    on_button_enter(button);
}

void on_button_one_clicked(GtkButton *button)
{
    on_button_clicked(button);
}

void on_button_two_clicked(GtkButton *button)
{
    on_button_clicked(button);
}

void on_button_clicked(GtkButton *button)
{
}

void on_button_enter(GtkButton *button)
{
    gtk_button_set_label(button, "Yes");
}

*/

