bin_PROGRAMS = splashbox-bot-frontend-gtk

INCLUDES = $(GTK_CFLAGS) $(DBUS_CFLAGS) -DDATADIR=\"$(datadir)\"

splashbox_bot_frontend_gtk_LDADD = $(GTK_LIBS) $(DBUS_LIBS)
splashbox_bot_frontend_gtk_SOURCES = main.c xgrabkey.c xgrabkey.h debug.h

EXTRA_DIST = splashbox.xpm
