/* References:
* https://prognotes.net/2016/12/gtk-glade-get-pointers-to-widgets/
* https://prognotes.net/2016/03/gtk-3-c-code-hello-world-tutorial-using-glade-3/ 
*/

#include <string.h>
#include <main.h>
#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    GtkBuilder *builder; 
    GtkWidget *window;
    app_widgets *widgets = g_slice_new(app_widgets);

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "Question4G.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    widgets->label_feedback = GTK_WIDGET(gtk_builder_get_object(builder, "label_feedback")); 
    widgets->button_one = GTK_WIDGET(gtk_builder_get_object(builder, "button_one")); 
    widgets->button_two = GTK_WIDGET(gtk_builder_get_object(builder, "button_two")); 
    
    gtk_builder_connect_signals(builder, widgets);

    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();

    return 0;
}

void on_window_main_destroy()
{
    gtk_main_quit();
}

void on_button_one_enter_notify_event(GtkButton *button, app_widgets *widgets)
{
    /* const gchar *text = gtk_button_get_label(button);*/
    on_button_enter(button);
    /* gtk_button_set_label(widgets->button_two, text);*/
}

void on_button_two_enter_notify_event(GtkButton *button, app_widgets *widgets)
{
    /* const gchar *text = gtk_button_get_label(button);*/
    on_button_enter(button);
    /* gtk_button_set_label(widgets->button_one, text);*/
}

void on_button_one_clicked(GtkButton *button, app_widgets *widgets)
{
    on_button_clicked(button, widgets);
}

void on_button_two_clicked(GtkButton *button, app_widgets *widgets)
{
    on_button_clicked(button, widgets);
}

void on_button_clicked(GtkButton *button, app_widgets *widgets)
{
    gtk_label_set_text(GTK_LABEL(widgets->label_feedback), "Yes Indeed!");
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

