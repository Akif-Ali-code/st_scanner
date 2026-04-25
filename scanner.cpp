#include <iostream>
#include <filesystem>
#include <vector>
#include <ncurses.h>
namespace fs = std::filesystem;
int main(){
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);
    // all initiallizations above
    std::vector<std::string> choices = {"scan document and clean it", "convert into a word document file", "convert into a plain .txt", "exit"};;

    int highlight = 0;
    int choice = -1;
    while(true){
        clear();
        mvprintw(0, 0, "Select an option");
        for (int i = 0; i < choices.size(); i++){
            if (i == highlight) attron(A_REVERSE);
            mvprrintw(i + 1, 0 , choices[i].c_str());
            attroff(A_REVERSE);
        }

        int c = getch();
        switch(c){
            case KEY_UP:
            if (highlight > 0) highlight--;
            break;
            case KEY_DOWN:
            if (highlight < 3) highlight++;
            break;
            case 10:
            choice = highlight;
            break;
        }
        if (choice != -1) break;
    }
    endwin();
    if (choice == 3) return 0;





    return 0;
}

