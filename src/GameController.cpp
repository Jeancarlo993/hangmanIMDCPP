#include <iostream>
#include <fstream>
#include <string>
#include "GameController.h"
#include "dice.h"
#include "hangman.h"


#define YEL "\e[0;33m"
#define RED "\e[0;31m"
#define BLU "\e[0;34m"
#define GRE "\e[0;33m"



using namespace std;

/// tela inicial do jogo
void GameController::m_tela_inicial(){
  std::cout<<"-------------------------------------------------------------"<<std::endl;
  std::cout<<"             ---> Welcome to Hangman, v. 1.0 <---"<<std::endl;
  std::cout<<"                  -copyright IMD/UFRN 2022.1-"<<std::endl;
  std::cout<<"-------------------------------------------------------------"<<std::endl;
  std::cout << "Please, enter your name > ";
  player1.m_set_name();
  estado = 1;                                /// pronto para entrar no game loop
};

/// entrada principal das opções
void GameController::m_option_in(){
  std::cout<<std::endl;
   
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
  Hangman hang;
  switch(m_option){
    case '1':
      estado = 2;                           /// estado em que o jogo foi inciado
      hang.make_word_line();
      system("clear");
      while(estado ==2){
        hang.print();                       ///imprime a forca com o life
        estado = hang.eval_hang_status();   ///avalia o estado do jogo
        if(estado==1){break;}               ///se estado mudou encerra o laço 
        hang.wrong_letter();                ///imprime as letras erradas
        hang.print_word();                  ///impresse como está o palpite
        hang.point_now();
        hang.guess_in();                    ///recebe novo palpite

      }
      player1.m_set_total_points(hang.point_now()); ///armazena a pontuação da partida
      break;
    case '2':
      system("clear");
      m_show_rules();
      break;
    case '3':
      player1.print_line_up();
      player1.print_medium_line();
      player1.print_score();
      player1.print_line_down();
      break;
    case '4':
      m_quit();
      break;
    default:
      std::cout << "invalid option\n";
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
};

/// quit 
void GameController::m_quit(){
//limpa a tela
  system("clear");
  estado = 0;

 std::cout<<" =-------[ Farewell ]-------="<<std::endl;

 std::cout<<"Thanks for playing. See you next time!"<<std::endl;
};