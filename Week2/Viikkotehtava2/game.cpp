/*
//OSA1
#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game(int max) {
    maxNumber=max;
    playerGuess=0;
    numOfGuesses=0;
}

Game::~Game()
{

}

void Game::play()
{
    srand(time(NULL));
    randomNumber=(rand() % maxNumber)+1;
    std::cout<<"Arvaa arvottu luku väliltä 1-"<<maxNumber<<std::endl;
    while(playerGuess!=randomNumber){ // Poistuu loopista kun vastaus on oikein.
        std::cin>>playerGuess;
        if(playerGuess<randomNumber){
            std::cout<<"Liian pieni."<<std::endl;
        }else if(playerGuess>randomNumber){
            std::cout<<"Liian suuri."<<std::endl;
        }
        numOfGuesses++;
    }
    std::cout<<"Oikein!"<<std::endl;
    printGameResult();
}

void Game::printGameResult()
{
    std::cout<<"Arvausten lukumäärä: "<<numOfGuesses<<std::endl;
}*/

/*
//OSA2 JA 3
#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game(int max) {
    maxNumber=max;
    playerGuess=0;
    numOfGuesses=0;
    std::cout<<"GAME CONSTRUCTOR: object initialized with "<<maxNumber<<" as a maximum value"<<std::endl;
}

Game::~Game()
{
    std::cout<<"GAME DESTRUCTOR: object cleared from stack memory"<<std::endl;
}

void Game::play()
{
    srand(time(NULL));
    randomNumber=(rand() % maxNumber)+1;
    while(playerGuess!=randomNumber){ // Poistuu loopista kun vastaus on oikein.
        std::cout<<"Arvaa arvottu luku väliltä 1-"<<maxNumber<<std::endl;
        std::cin>>playerGuess;
        if(playerGuess<randomNumber){
            std::cout<<"Liian pieni."<<std::endl;
        }else if(playerGuess>randomNumber){
            std::cout<<"Liian suuri."<<std::endl;
        }
        numOfGuesses++;
    }
    std::cout<<"Oikein!"<<std::endl;
    printGameResult();
}

void Game::printGameResult()
{
    std::cout<<"Arvausten lukumäärä: "<<numOfGuesses<<std::endl;
}*/
