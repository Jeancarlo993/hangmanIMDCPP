#include <iostream>
#include <fstream>
#include <string>
#include "GameController.h"
#include "dice.h"
#include "hangman.h"
#define YEL "\e[0;33m"
#define RED "\e[0;31m"
#define BLU "\e[0;34m"


using namespace std;

/// tela inicial do jogo
void GameController::m_tela_inicial(){
  std::cout<<"-------------------------------------------------------------"<<std::endl;
  std::cout<<"             ---> Welcome to Hangman, v. 1.0 <---"<<std::endl;
  std::cout<<"                  -copyright IMD/UFRN 2022.1-"<<std::endl;
  std::cout<<"-------------------------------------------------------------"<<std::endl;
  std::cout << "Please, enter your name > ";
  player1.m_set_name();
  estado = 1; // pronto para entrar no game loop
};

/// entrada principal das opções
void GameController::m_option_in(){
  std::cout<<RED<< "=-------[ Main Menu ]-------=" << std::endl;
  std::cout << "Please choose an option: \n";
  std::cout << " 1 - Start a new challenge.\n";
  std::cout << " 2 - Show the game rules.\n";
  std::cout << " 3 - Show scoreboard.\n";
  std::cout << " 4 - Quit the game.\n";
  std::cout << ">>> ";
  std::cin.clear();
  std::cin>>m_option;
};
///
void GameController::eval_option(){
 /// Inicia um novo desafio
  if(m_option==1){
    // todo o jogo tem que ir pra um novo método que vai precisar um novo loop
    estado = 2; // estado em que o jogo foi inciado
    Hangman hang;
    hang.find_Out();
  }
  /// Mostra as regras do jogo
  else if(m_option==2){
    system("clear");
    m_show_rules();
  }
  /// Mostra o scoreboard
  else if(m_option==3){
    
  }
  /// sai do jogo1
  else if(m_option==4){
    m_quit();
  }
};
/// Regras do jogo
void GameController::m_show_rules(){
  std::cout << "=----------------------------[ Gameplay ]----------------------------=\n";
  std::cout << "Hi, "<<BLU << player1.m_get_name()<<RED <<" here are the game rules: " << std::endl;
  std::ifstream rules("gamerules.txt");
  std::string rule_l;
  
  if (rules.is_open()){
    while(!rules.eof()){
      getline (rules,rule_l);
      std::cout<<YEL<<rule_l<< std::endl;
    }
    rules.close();
  }
  // falta implementar que ele só saia dessa tela depois do enter
};
/// quit 
void GameController::m_quit(){
  estado = 0;
};