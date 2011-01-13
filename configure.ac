#						-*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)
AC_INIT(splashbox-bot-frontend-gtk, 0.0.1, http://www.opensplash-project.org/)
AC_CONFIG_SRCDIR([src])
AC_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AM_PATH_GLIB_2_0([2.4.0], [
	GUI_CFLAGS="$GUI_CFLAGS $GLIB_CFLAGS"
	GUI_LIBS="$GUI_LIBS $GLIB_LIBS"
	], [AC_MSG_ERROR([Cannot find Glib 2.4 (or above version)!])], [gthread])


AM_PATH_GTK_2_0([2.4.0], [
	GUI_CFLAGS="$GUI_CFLAGS $GTK_CFLAGS"
	GUI_LIBS="$GUI_LIBS $GTK_LIBS"
	], [AC_MSG_ERROR([Cannot find GTK+/X11 2.4 (or above version)!])])

PKG_CHECK_MODULES(DBUS,
	dbus-1
	dbus-glib-1)

AC_SUBST(DBUS_CFLAGS)
AC_SUBST(DBUS_LIBS)




# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_SUBST(GUI_LIBS)
AC_CONFIG_FILES([Makefile src/Makefile splashbox-bot-frontend-gtk.desktop])
AC_OUTPUT
