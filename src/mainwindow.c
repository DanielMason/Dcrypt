#include <gtk/gtk.h>

int main(int argc, char** argv) {
  GtkWidget *window;
  GtkWidget *frame;

  GtkWidget *select_file_label;
  GtkWidget *select_file_button;
  GtkWidget *select_encrypt_pass_label;
  GtkWidget *select_encrypt_pass;
  GtkWidget *confirm_encrypt_pass_label;
  GtkWidget *confirm_encrypt_pass;

                GtkImage *preview;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 480, 320);
  gtk_window_set_title(GTK_WINDOW(window), "Dcrypt v0.01");

  frame = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(window), frame);

  select_file_label = gtk_label_new("");
  gtk_label_set_markup(GTK_LABEL(select_file_label), "<b>Step 1.</b> Select file to Encrypt:");
  gtk_fixed_put(GTK_FIXED(frame), select_file_label, 10, 10);

  select_file_button = gtk_button_new_with_label("Select File");
  gtk_fixed_put(GTK_FIXED(frame), select_file_button, 10, 30);

  select_encrypt_pass_label = gtk_label_new("");
  gtk_label_set_markup(GTK_LABEL(select_encrypt_pass_label), "<b>Step 2.</b> Select Encryption Password:");
  gtk_fixed_put(GTK_FIXED(frame), select_encrypt_pass_label, 10, 70);


  select_encrypt_pass = gtk_entry_new ();
  gtk_entry_set_visibility (GTK_ENTRY (select_encrypt_pass), 0);
  gtk_entry_set_input_purpose (GTK_ENTRY (select_encrypt_pass), GTK_INPUT_PURPOSE_PASSWORD);
  gtk_entry_set_max_length (GTK_ENTRY (select_encrypt_pass), 256);
  gtk_entry_set_width_chars (GTK_ENTRY (select_encrypt_pass), 32);
  gtk_fixed_put(GTK_FIXED(frame), select_encrypt_pass, 10, 90);

  confirm_encrypt_pass_label = gtk_label_new("");
  gtk_label_set_markup(GTK_LABEL(confirm_encrypt_pass_label), "<b>Step 3.</b> Confirm Encryption Password:");
  gtk_fixed_put(GTK_FIXED(frame), confirm_encrypt_pass_label, 10, 120);
  
  confirm_encrypt_pass = gtk_entry_new ();
  gtk_entry_set_visibility (GTK_ENTRY (confirm_encrypt_pass), 0);
  gtk_entry_set_input_purpose (GTK_ENTRY (confirm_encrypt_pass), GTK_INPUT_PURPOSE_PASSWORD);
  gtk_entry_set_max_length (GTK_ENTRY (confirm_encrypt_pass), 256);
  gtk_entry_set_width_chars (GTK_ENTRY (confirm_encrypt_pass), 32);
  gtk_fixed_put(GTK_FIXED(frame), confirm_encrypt_pass, 10, 140);


          preview = gtk_image_new ();

          gtk_file_chooser_set_preview_widget (my_file_chooser, preview);
          g_signal_connect (my_file_chooser, "update-preview",
                    G_CALLBACK (update_preview_cb), preview);



  gtk_widget_show_all(window);

  g_signal_connect(window, "destroy",
      G_CALLBACK (gtk_main_quit), NULL);

  gtk_main();

  return 0;
}
static void
update_preview_cb (GtkFileChooser *file_chooser, gpointer data)
{
  GtkWidget *preview;
  char *filename;
  GdkPixbuf *pixbuf;
  gboolean have_preview;

  preview = GTK_WIDGET (data);
  filename = gtk_file_chooser_get_preview_filename (file_chooser);

  pixbuf = gdk_pixbuf_new_from_file_at_size (filename, 128, 128, NULL);
  have_preview = (pixbuf != NULL);
  g_free (filename);

  gtk_image_set_from_pixbuf (GTK_IMAGE (preview), pixbuf);
  if (pixbuf)
    g_object_unref (pixbuf);

  gtk_file_chooser_set_preview_widget_active (file_chooser, have_preview);
}