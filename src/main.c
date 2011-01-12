#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <string.h>
#define DATADIR_XPM DATADIR

#include "splashbox.xpm"

int main( int argc, char *argv[] )
{
	GtkWidget *window;
	GtkWidget *vbox;
	GtkWidget *entry;
	GtkStatusIcon *tray_icon;
	GdkPixbuf *main_icon;
	
	gtk_init (&argc, &argv);

	main_icon = gdk_pixbuf_new_from_xpm_data((const char**)splashbox_xpm);
	
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

	tray_icon = gtk_status_icon_new ();
	gtk_status_icon_set_from_pixbuf(tray_icon, main_icon);


	
	gtk_widget_hide_all  (window);
	gtk_main ();
	
	return 0;
}
