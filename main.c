#include "client.h"

int main(int argc, char** argv){

	/* Create the GUI elements */
	GtkWidget* MainWindow=NULL;
	GtkWidget* Grid=NULL;
	static int box[9]={1,2,3,4,5,6,7,8,9}; 

	/* Randomly define the first player */
	srand(time(NULL));
	turn=rand()%2;

	init_grid();
	
	/* GTK+ initialisation */
	gtk_init(&argc,&argv);

	//Window creation
	MainWindow=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	
	gtk_window_set_position(GTK_WINDOW(MainWindow),GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(MainWindow),400,400);
	gtk_window_set_title(GTK_WINDOW(MainWindow),"TIC TAC TOE");

	Grid = gtk_grid_new();	

	/* Smooth display */
	gtk_grid_set_column_homogeneous(GTK_GRID(Grid),TRUE);
	gtk_grid_set_row_homogeneous(GTK_GRID(Grid),TRUE);


	/* Create the grid in the GUI */
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			GtkWidget* Button=gtk_button_new_with_label("?");
			g_signal_connect(G_OBJECT(Button),"clicked",G_CALLBACK(button_clicked),&box[i*3 +j]);
			g_signal_connect(G_OBJECT(Button),"clicked",G_CALLBACK(print_end_game),(gpointer) MainWindow);
			gtk_grid_attach(GTK_GRID(Grid),Button, j, i, 1,1);
		}
	}
	
	/* Encapsulate the Grid */
	gtk_container_add(GTK_CONTAINER(MainWindow),Grid);

	/* Exit when close button is clicked */
	g_signal_connect(MainWindow,"destroy",G_CALLBACK(gtk_main_quit),NULL);

	/* Show the application */
	gtk_widget_show_all(MainWindow);
	gtk_main();

	return EXIT_SUCCESS;
}