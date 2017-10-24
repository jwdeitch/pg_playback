#include <stdio.h>
#include <gtk/gtk.h>

#define true 1
#define false 0

static void
activate(GtkApplication *app,
		 gpointer user_data) {
	GtkWidget *window;
	GtkWidget *box;
	GtkWidget *query_slug_selector;

	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "pg_playback");
	box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
	query_slug_selector = gtk_list_box_new();
	gtk_box_pack_start(GTK_BOX(box), query_slug_selector, true, true, 1);
	gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
	GtkApplication *app;
	int status;

	app = gtk_application_new("org.gtk.pg_playback",
							  G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate",
					 G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);
	return (status);
}