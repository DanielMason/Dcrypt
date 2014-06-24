Dcrypt v0.01
============

Dcrypt - Open-Source, Multi-Platform encryption software.


##Information

Dcrypt is currently built on GTK+3.0 and written in C.

###Compiling on Linux


Make sure libgtk + gcc is installed and up to date.

'gcc -o bin/Dcrypt-v0.01-lin-x86 src/mainwindow.c'


###Compiling on Windows

Windows Tutorial here to install GTK+ 
http://www.gtk.org/download/win32_tutorial.php

GTK+ Bundle 3.6.4 for Win32
http://win32builder.gnome.org/gtk+-bundle_3.6.4-20130921_win32.zip

+

MinGW for Win32 
http://iweb.dl.sourceforge.net/project/mingw/Installer/mingw-get-setup.exe

Run 'pkg-config --cflags --libs gtk+-3.0'
Copy output and paste after normal GCC commands, e.g.

gcc -o bin/Dcrypt-v0.01-win-x86.exe src/mainwindow.c -mms-bitfields -IC:/gtk/include/gtk-3.0 -IC:/gtk/include/cairo -IC:/gtk/include/pango-1.0 -IC:/gtk/include/atk-1.0 -IC:/gtk/include/cairo -IC:/gtk/include/pixman-1 -IC:/gtk/include -IC:/gtk/include/freetype2 -IC:/gtk/include -IC:/gtk/include/libpng15 -IC:/gtk/include/gdk-pixbuf-2.0 -IC:/gtk/include/libpng15 -IC:/gtk/include/glib-2.0 -IC:/gtk/lib/glib-2.0/include -LC:/gtk/lib -lgtk-3 -lgdk-3 -lgdi32 -limm32 -lshell32 -lole32 -Wl,-luuid -lpangocairo-1.0 -lpangoft2-1.0 -lfreetype -lfontconfig -lpangowin32-1.0 -lgdi32 -lpango-1.0 -lm -latk-1.0 -lcairo-gobject -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lgobject-2.0 -lglib-2.0 -lintl

###Compiling on Mac

Follow these instructions
http://www.maclife.com/article/howtos/install_linux_your_mac



