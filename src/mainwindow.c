#include <gtk/gtk.h>

GtkWidget *file_selection_box;
gchar *filename;

int main(int argc, char** argv) {

  GtkWidget *select_file_label;
  GtkWidget *select_file_button;
  GtkWidget *select_encrypt_pass_label;
  GtkWidget *select_encrypt_pass;
  GtkWidget *window;
  GtkWidget *frame;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);
  gtk_window_set_title(GTK_WINDOW(window), "Dcrypt v0.01");

  frame = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(window), frame);

  select_file_label = gtk_label_new("Step 1. Select file to Encrypt:");
  gtk_fixed_put(GTK_FIXED(frame), select_file_label, 10, 10); 

  select_file_button = gtk_button_new_with_label("Select File");
  gtk_fixed_put(GTK_FIXED(frame), select_file_button, 10, 30);

  select_encrypt_pass_label = gtk_label_new("Step 2. Select Encryption Password:");
  gtk_fixed_put(GTK_FIXED(frame), select_encrypt_pass_label, 10, 80); 

  select_encrypt_pass = gtk_button_new_with_label("Select File");
  gtk_fixed_put(GTK_FIXED(frame), select_encrypt_pass, 10, 110);

  gtk_widget_show_all(window);

  g_signal_connect(window, "destroy",
      G_CALLBACK (gtk_main_quit), NULL);

  gtk_main();

  return 0;
}