#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <glib.h>
#include <dbus/dbus.h>
#include <dbus/dbus-glib.h>
#include <stdlib.h>
#include "xgrabkey.h"
#include "debug.h"

#include "splashbox.xpm"

DBusGConnection *connection;
DBusGProxy *proxy;
GError *error = NULL;
gchar *res = NULL;

static void entry_activated_cb(GtkEntry *entry, gpointer user_data)
{
/*
	GtkWidget **array_widget = user_data;
	GtkWidget *window =  array_widget[0];
	GtkWidget *label = array_widget[1];
*/
	GtkWidget *label = GTK_WIDGET(user_data);
	const static gchar *text;
	char input[32] = {0};

	text = gtk_entry_get_text(entry);
	g_strlcpy(input, text, 32);
	INFO("Activated %s!\n", input);
	if ( !dbus_g_proxy_call(proxy, "say", &error, G_TYPE_STRING, &input, G_TYPE_INVALID, G_TYPE_STRING, &res, G_TYPE_INVALID))
	{
		if (error->domain == DBUS_GERROR && error->code == DBUS_GERROR_REMOTE_EXCEPTION)
			DEBUG ("Caught remote method exception %s: %s", dbus_g_error_get_name (error), error->message);
		else
			DEBUG ("Error: %s\n", error->message);
		g_error_free (error);
		exit(1);
	}
	gtk_label_set_text(GTK_LABEL(label), res);
	INFO("Result is: %s\n", res);
	g_free(res);
	gtk_entry_set_text(entry, "");
}

int main( int argc, char *argv[] )
{
	GtkWidget *window = NULL;
	GtkWidget *vbox;
	GtkWidget *entry;
	GtkWidget *label;
	GtkStatusIcon *tray_icon;
	GdkPixbuf *main_icon;
	GtkWidget* array_widget[2];

	g_type_init ();

	connection = dbus_g_bus_get (DBUS_BUS_SESSION, &error);
	if (connection == NULL) {
		DEBUG ("Failed to make connection to session bus: %s", error->message);
		g_error_free (error);
		exit(1);
	}

	proxy = dbus_g_proxy_new_for_name (	connection, 
						"org.opensplash.bot",
						"/org/opensplash/bot/language/Parser",
						"org.opensplash.bot.language" );
	



	gtk_init (&argc, &argv);
	x_grab_key_init();

	main_icon = gdk_pixbuf_new_from_xpm_data((const char**)splashbox_xpm);
	
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_wmclass (GTK_WINDOW(window), "splashbox-bot-frontend-gtk", "splashbox-bot-frontend-gtk");
	//gtk_window_set_modal(GTK_WINDOW(window), TRUE);
	gtk_widget_set_size_request( window, 300, -1);
	gtk_window_set_has_frame(GTK_WINDOW(window), FALSE);
	gtk_window_set_resizable (GTK_WINDOW(window), FALSE);
	gtk_window_set_position  (GTK_WINDOW(window),GTK_WIN_POS_CENTER_ALWAYS);
	gtk_window_set_keep_above(GTK_WINDOW(window), TRUE);


	vbox = gtk_vbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(window), vbox);
	gtk_widget_show(vbox);

	entry = gtk_entry_new();
	gtk_box_pack_start(GTK_BOX(vbox), entry, TRUE, TRUE, 0);
//	gtk_entry_set_activates_default (GTK_ENTRY(entry), TRUE);
	gtk_widget_show(entry);

	label = gtk_label_new("Hi Master, what can I do for you?");
	gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);
	gtk_widget_show(label);


	tray_icon = gtk_status_icon_new ();
	gtk_status_icon_set_from_pixbuf(tray_icon, main_icon);

	/*
	array_widget[0] = window;
	array_widget[1] = label;
	*/
	g_signal_connect(G_OBJECT(entry), "activate", G_CALLBACK (entry_activated_cb), label);


	
	gtk_widget_hide  (window);
	g_idle_add(grab_key, (gpointer)window);
	gtk_main ();
	
	return 0;
}
