#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
int main() {
char user_input;
char filename[100];
char command[150];
char save[100];
char command1[150];
char foldername[100];
char command2[150];
char command3[150];
char command4[150];
initscr();
start_color();
init_pair(1, COLOR_BLACK, COLOR_RED);
init_pair(2, COLOR_RED, COLOR_BLACK);
attron(COLOR_PAIR(1));
printw("nano-linux 0.1                                       nanoFM                                                      ");
attroff(COLOR_PAIR(1));
refresh();
printw("                                   ");
refresh();
attron(COLOR_PAIR(2));
printw("\nwelcome to nanoFM: ");
refresh();
scanw("%c", &user_input);
if (user_input == 'h' || user_input == 'H'){
   system("cd && cd Desktop && konsole --hold -e nano help.txt > /dev/null 2>&1 && cd && cd fnanoFM");
}else if(user_input == 'n' || user_input == 'N'){
        printw("file name is: ");
        refresh();
        scanw("%s", filename);
        printw("where want to save it: ");
        scanw("%s", save);
        snprintf(command, sizeof(command),"cd && cd %s && touch %s",save, filename);

        system(command);} else if (user_input == 'o' || user_input  == 'O') {
                          printw("file name is: ");
                          refresh();
                          scanw("%s", filename);
                          printw("where the file?: ");
                          refresh();
                          scanw("%s", save);
                          snprintf(command1, sizeof(command1), "cd && cd %s && open %s", save, filename);
                          system(command1);} else if (user_input == 'f' || user_input == 'F'){
                          printw("folder name is: ");
                          refresh();
                          scanw("%s", foldername);
                          printw("where want to save it?: ");
                          refresh();
                          scanw("%s", save);
                          snprintf(command2, sizeof(command2), "cd && cd %s && mkdir %s", save, foldername); 
                          system(command);} else if (user_input == 'z' || user_input  == 'Z') {
                          printw("zip_folder full name is: ");
                          refresh();
                          scanw("%s", filename);
                          printw("where the zip_folder?: ");
                          refresh();
                          scanw("%s", save);
                          snprintf(command3, sizeof(command3), "cd && cd %s && unzip %s", save, foldername); 
                          system(command3);} else if (user_input == 'e' || user_input  == 'E'){ 
                          printw("exe_file full name is: ");
                          refresh();
                          scanw("%s", filename);
                          printw("where the exe_file?: ");
                          refresh();
                          scanw("%s", save);
                          snprintf(command4, sizeof(command4), "cd && cd %s && wine %s", save, filename);
                          system(command4);} else if (user_input == 0) {
 
                                            printw("sorry try agin-if you dont konw what to type just type h: ");
                                             refresh();
                                             scanw("%c", &user_input); 
if (user_input == 'h' || user_input == 'H') {
   system("cd && cd Desktop && konsole --hold -e nano help.txt > /dev/null 2>&1 && cd && cd fnanoFM");}
} else { printw("sorry there a proplem"); 
                                                                               endwin();

                                                                               return 1;}

attroff(COLOR_PAIR(2));

getch();
endwin();
return 0;
}
