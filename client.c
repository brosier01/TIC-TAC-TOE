#include "client.h"

void print_end_game(GtkButton* widget, gpointer data){
    /* Show the winner of the game */
    if(check_end_game()){
        if(turn){
            GtkWidget* show;
            show=gtk_message_dialog_new(GTK_WINDOW(data),GTK_DIALOG_DESTROY_WITH_PARENT,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"\n'O' WON");
            gtk_dialog_run(GTK_DIALOG(show));
            gtk_widget_destroy(show);
        }
        else{
            GtkWidget* show;
            show=gtk_message_dialog_new(GTK_WINDOW(data),GTK_DIALOG_DESTROY_WITH_PARENT,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"\n'X' WON");
            gtk_dialog_run(GTK_DIALOG(show));
            gtk_widget_destroy(show);
        }


    }    
}

void button_clicked(GtkButton* widget, gpointer data){
    const char* coin0="O";
    const char* coinX="X";

    /* Recovery the case index */
    int* res= (int*)data;

    /* Udapte the case if the game is not done */
    if(!check_end_game()){
        /* Refresh the case with a coin */
        if(turn){
            gtk_button_set_label(widget,coinX);
            game[(*res)-1]='X';

        }
        else{
            gtk_button_set_label(widget,coin0);
            game[(*res)-1]='O';
        }

        /* Switch the player */
        turn=(turn+1)%2; 
    }
    
}


int check_end_game(void){

    /* Horizontally */
    for(int i=0;i<9;i=i+3){
        if(game[i]==game[i+1] && game[i+1]==game[i+2] && game[i]!='?'){
            return 1;
        }
    }

    /* Vertically */
    for(int i=0;i<3;i++){
        if(game[i]==game[i+3] && game[i+3]==game[i+6] && game[i]!='?'){
            return 1;
        }
    }

    /* Diagonally */ 
    if(game[0]==game[4] && game[4]==game[8] && game[0]!='?'){
        return 1;
    }
    if(game[2]==game[4] && game[4]==game[6] && game[2]!='?'){
        return 1;
    }

    /* The game is not finish */
    return 0;

}

void init_grid(void){
    for(int i=0;i<9;i++){
        game[i]='?';
    }
}
