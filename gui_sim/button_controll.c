GtkLabel *label;
void right_controll(){

   gtk_label_set_text(label,"Going right");
  send_right();
 }
 
void down_controll(){

  gtk_label_set_text(label,"Going down");
  send_down();
}

void up_controll(){

  gtk_label_set_text(label,"Going up");
  send_up();
}

void left_controll(){

  gtk_label_set_text(label,"Going left");
  send_left();
}


void  command_quit()

{
  send_exit();
    gtk_main_quit ();
   
}

void auto_controll(){

  gtk_label_set_text(label,"Auto enabled");

}

void info_pressed(){

  printf("Pressing dirrection button\n");

}

void hover(){

  gtk_label_set_text(label,"Hovering");

}


void alt_up(){

  gtk_label_set_text(label,"Alt up");

}


void alt_down(){

  gtk_label_set_text(label,"Alt down");

}

void drone_connect(){

  gtk_label_set_text(label,"Connecting");
  setup();
 
}




void camera_connect(){

   gtk_label_set_text(label,"Starting camera");
}

