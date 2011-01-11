#include <gtk/gtk.h>

int main( int argc, char *argv[] )
{
	GtkWidget *window;
	GtkWidget *vbox;
	GtkWidget *entry;
	GtkStatusIcon *status_icon;
	
	gtk_init (&argc, &argv);
	
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_wmclass (GTK_WINDOW(window), "splashbox-bot-frontend-gtk", "splashbox-bot-frontend-gtk");
	//gtk_window_set_modal(GTK_WINDOW(window), TRUE);
	gtk_window_set_default_size(GTK_WINDOW(window), 120, 20);
	gtk_window_set_has_frame(GTK_WINDOW(window), FALSE);
	gtk_window_set_resizable (GTK_WINDOW(window), FALSE);
	gtk_window_set_position  (GTK_WINDOW(window),GTK_WIN_POS_CENTER_ALWAYS);
	gtk_window_set_keep_above(GTK_WINDOW(window), TRUE);


	vbox = gtk_vbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	entry = gtk_entry_new();
	gtk_box_pack_start(GTK_BOX(vbox), entry, TRUE, TRUE, 0);

	status_icon = gtk_status_icon_new_from_file ("../data/splashbox.xpm");

	
	gtk_widget_hide_all  (window);
	gtk_main ();
	
	return 0;
}
