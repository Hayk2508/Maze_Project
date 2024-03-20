#include <iostream>
#include "../Includes/game.h"
#include "../Includes/labyrinth.h"
#include <string>
#include <windows.h>


void Game::play_music()const {
    PlaySound("undertale_100. MEGALOVANIA.wav", nullptr, SND_FILENAME | SND_ASYNC);
}
void Game::showInfo() const {
   std::cout<<"For this moment game Labyrinth contains only two modes \n"<<
   "1.Welcome to the jungle- the labyrinth is filled with a lot of trees "
   "and it is impossible to regularly solve the labyrinth. "
   "But the player can cut up to 3 trees to get out from the labyrinth.\n\n" <<

   "2.Treeocalypse - After each player’s move, three random empty cells will become 'planted'. "
   "'Planted' cells are cells with a countdown between 1 to 10 and the number goes down after each move. "
   "When the number reaches 0, the cell turns into a tree. "
   "The player can step on the 'planted' cell until it turns into a tree. "
   "Any empty cell can turn into a “planted” cell as long as the game stays winnable. "
   "If it is impossible to add a new 'planted' cell, the 'planting' will be skipped.\n";
}

void Game::Credits() const{
    std::cout<<"This games were created by Hayk Hovhannisyan and Samvel Arabyan\n"<<
    "We hope you enjoy playing them, stay tunned for more!\n";
}
void Game::play() {
}
void Game::start()const {
    std::cout << "\nWelcome, adventurer, to the Labyrinth of Mystery!\n"
                 "Within these twisting corridors lie untold secrets and treasures waiting to be discovered. Are you ready to embark on a journey filled with excitement and peril?\n"
                 "\n"
                 "As you step into the depths of the labyrinth, remember to keep your wits about you. Every turn presents a new challenge, every path a new opportunity.\n"
                 "\n"
                 "But fear not, for you are not alone. Your courage will guide you through the darkness, and your determination will lead you to victory.\n"
                 "\n"
                 "So gather your strength, sharpen your senses, and prepare to uncover the mysteries that lie hidden within these ancient walls.\n"
                 "\n"
                 "May your adventure be legendary!"
                 "\n";
    std::string input;
    std::cout << "If you want to start the game,write PLAY. \n" ;
    std::cout << "If you want to take a look at the rules of the game  write INFO.\n";
    std::cout<<"If you want to see more information about developers of this game, write CREDITS. \n";
    std::cout<<"If you want to  exit the game, write EXIT. \n";
   while(1){
        std::cin >> input;
        if(input == "INFO") {
            showInfo();
        }else if(input =="EXIT") {
            exit(0);
        }else if(input == "CREDITS") {
            Credits();
        }
        else if (input == "PLAY") {
            break;
        }
    }
    Labyrinth lab;
    lab.play();

}
void Game::clearConsole() {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
}
void Game::draw(){}



