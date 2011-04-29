#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include "tcpclient_main.c"
#include "button_controll.c"
/*Author Michal Musialik*/


GtkWidget *window;
GtkWidget *fixed;
GtkWidget *button_quit;
GtkWidget *button_connect;
GtkWidget *button_up;
GtkWidget *button_down;
GtkWidget *button_left;
GtkWidget *button_right;
GtkWidget *button_hover;
GtkWidget *button_camera;
GtkWidget *button_auto;
GtkWidget *button_alt_up;
GtkWidget *button_alt_down;



int menu_panel_x = 330;


void info_frame(){

   label = gtk_label_new("Data info");
  gtk_fixed_put(GTK_FIXED(fixed), label, 150, 250);
 
}  

void button_altitide_up(){


  button_alt_up = gtk_button_new_with_label("alt_up");

  gtk_fixed_put(GTK_FIXED(fixed), button_alt_up, menu_panel_x, 120);
  gtk_widget_set_size_request(button_alt_up, 70, 30);

  g_signal_connect(G_OBJECT(button_alt_up), "clicked", 
		   G_CALLBACK(alt_up), G_OBJECT(window));

}


void button_altitide_down(){


  button_alt_down = gtk_button_new_with_label("alt_down");

  gtk_fixed_put(GTK_FIXED(fixed), button_alt_down, menu_panel_x, 150);
  gtk_widget_set_size_request(button_alt_down, 70, 30);

  g_signal_connect(G_OBJECT(button_alt_down), "clicked", 
		   G_CALLBACK(alt_down), G_OBJECT(window));

}

void button_hover_command(){


  button_hover = gtk_button_new_with_label("hover");

  gtk_fixed_put(GTK_FIXED(fixed), button_hover, menu_panel_x, 210);
  gtk_widget_set_size_request(button_hover, 70, 30);

  g_signal_connect(G_OBJECT(button_hover), "clicked", 
		   G_CALLBACK(hover), G_OBJECT(window));

}



void button_exit(){
  
  

  button_quit = gtk_button_new_with_label("Exit");

  gtk_fixed_put(GTK_FIXED(fixed), button_quit, menu_panel_x, 270);
  gtk_widget_set_size_request(button_quit, 70, 30);

  g_signal_connect(G_OBJECT(button_quit), "clicked", 
		   G_CALLBACK(command_quit), G_OBJECT(window));

}

void button_connect_to_server(){

  button_connect = gtk_button_new_with_label("Connect");

  gtk_fixed_put(GTK_FIXED(fixed),button_connect , menu_panel_x, 240);
  gtk_widget_set_size_request(button_connect, 70, 30);

  g_signal_connect(G_OBJECT(button_connect), "clicked", 
		   G_CALLBACK(drone_connect), G_OBJECT(window));

}




void button_camera_controll(){

  button_camera = gtk_button_new_with_label("camera");

  gtk_fixed_put(GTK_FIXED(fixed),button_camera , 140, 150);
  gtk_widget_set_size_request(button_camera, 70, 70);

  g_signal_connect(G_OBJECT(button_camera), "clicked", 
		   G_CALLBACK(camera_connect), G_OBJECT(window));

}


void button_down_controll(){

  button_down = gtk_button_new_with_label("down");

  gtk_fixed_put(GTK_FIXED(fixed),button_down , 140, 90);
  gtk_widget_set_size_request(button_down, 70, 30);

  g_signal_connect(G_OBJECT(button_down), "clicked", 
		   G_CALLBACK(down_controll), G_OBJECT(window));

}


void button_left_controll(){

  button_left = gtk_button_new_with_label("left");

  gtk_fixed_put(GTK_FIXED(fixed),button_left , 70, 60);
  gtk_widget_set_size_request(button_left, 70, 30);

  g_signal_connect(G_OBJECT(button_left), "clicked", 
		   G_CALLBACK(left_controll), G_OBJECT(window));

}


void button_right_controll(){

  button_right = gtk_button_new_with_label("right");

  gtk_fixed_put(GTK_FIXED(fixed),button_right , 210, 60);
  gtk_widget_set_size_request(button_right, 70, 30);

  g_signal_connect(G_OBJECT(button_right), "clicked", 
		   G_CALLBACK(right_controll), G_OBJECT(window));

}


void button_up_controll(){

  button_up = gtk_button_new_with_label("up");

  gtk_fixed_put(GTK_FIXED(fixed),button_up , 140, 30);
  gtk_widget_set_size_request(button_up, 70, 30);

  g_signal_connect(G_OBJECT(button_up), "clicked", 
		   G_CALLBACK(up_controll), G_OBJECT(window));

}


void button_auto_controll(){

  button_auto = gtk_button_new_with_label("auto");

  gtk_fixed_put(GTK_FIXED(fixed),button_auto , menu_panel_x, 180);
  gtk_widget_set_size_request(button_auto, 70, 30);

  g_signal_connect(G_OBJECT(button_auto), "clicked", 
		   G_CALLBACK(auto_controll), G_OBJECT(window));

}


void window_creation(){

 window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "connect");
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  fixed = gtk_fixed_new();
  
  
  gtk_container_add(GTK_CONTAINER(window), fixed);

 

}

void destroy_command(){

g_signal_connect_swapped(G_OBJECT(window), "destroy", 
      G_CALLBACK(command_quit), NULL);

}

int main( int argc, char *argv[])
{
 

  gtk_init(&argc, &argv);

  window_creation();

  info_frame();
  button_exit();
 
  button_hover_command();
  button_camera_controll();
  button_auto_controll();
  button_connect_to_server();

  button_up_controll();
  button_down_controll();
  button_left_controll();
  button_right_controll();
  button_altitide_up();
  button_altitide_down();
  
  destroy_command();

  

  gtk_widget_show_all(window);

  gtk_main();
 
  return 0;
}

//gcc frame.c -o frame `pkg-config --cflags --libs gtk+-2.0`

