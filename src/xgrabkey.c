#include "xgrabkey.h"
#include "debug.h"


Display *x_disp;
int x_screen;
Window x_root;
KeyCode key_code;
XEvent event;

void x_grab_key_init()
{
	x_disp = XOpenDisplay (NULL);
	x_screen = DefaultScreen (x_disp);
	x_root = RootWindow (x_disp, x_screen);
	key_code = XKeysymToKeycode(x_disp , XK_Meta_R);
	XSelectInput(x_disp , x_root , KeyReleaseMask);
	XGrabKey(x_disp , key_code , AnyModifier , x_root, 1 , GrabModeAsync,GrabModeAsync );
}

gboolean grab_key(gpointer user_data)
{
	GtkWidget *window = GTK_WIDGET(user_data);

	while(XCheckTypedEvent(x_disp, KeyRelease, &event));
	switch(event.type)
	{
		case KeyRelease:
			INFO("Got an event %d\n", event.xkey.keycode);
			event.type = 0;
			if (window)
			{
				if (GTK_WIDGET_VISIBLE(window))
				{
					gtk_widget_hide(window);
				}
				else
				{
					gtk_widget_show(window);
				}
			}
			
			break;
		default:
			break;
	} 
	usleep(100000);
	return TRUE;
}

#if 0
int main()
{
	x_grab_key_init();
	grab_key();
}
#endif
