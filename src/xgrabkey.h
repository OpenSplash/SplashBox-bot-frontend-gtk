#ifndef _INCLUDE_XGRABKEY_H_
#define _INCLUDE_XGRABKEY_H_

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <gtk/gtk.h>
#include <glib.h>
#include <stdio.h>
#include <unistd.h>

gboolean grab_key(gpointer);
void x_grab_key_init();

#endif /* _INCLUDE_XGRABKEY_H_ */
