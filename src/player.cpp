#include <string>
#include <vector>
#include <iostream>
#include "player.h"
#include "hangman.h"
#define GRE "\e[0;33m"
#define RED "\e[0;31m"
#define BLU "\e[0;34m"


/// Construtor de uma máquina
Player::Player(){
	m_name = "Pedron";
	m_total_points = 0;
	m_round_points = 0;
}; 

/// ajusta o nome do jogador
void Player::m_set_name(){
  std::getline(std::cin,m_name);
};

/// retorna o nome do jogador
std::string Player::m_get_name(){
	return m_name;
};

/// Modifica a pontuação total
void Player::m_set_total_points(int total){

	m_total_points = m_total_points + total;
};
/// Retorna a pontuação total
int Player::m_get_total_points(){
	return m_total_points;
};
/// Modifica a pontuação do turno
void Player::m_set_round_points(int round){
	m_round_points = round;
};
/// soma um valor ao round points
void Player::m_sum_round_points(int round){
  m_round_points = m_round_points + round;
}
/// Retorna a pontuação do round
int Player::m_get_round_points(){
	return m_round_points;
};

void Player::print_score(){
  int range=m_name.length();
 

  ///imprime o nome do jogador
  for(int i=0;i<range;i++){
    if(i==2){
       for(int j=0;j<m_name.length();j++){
         std::cout<<m_name[j];
       }
        std::cout<<"  │ ";
      
    } 
    std::cout<<" ";
  } 
    ///imprime apontuação total
    std::cout<<m_get_total_points();
}

void Player::print_medium_line(){
  ///o tamanho da linha foi dobrado a partir do tamanho da palavra e para
  ///dar espaços do lado esquerdo e direito foi adicionado 6 espaços
  int range=(m_name.length()+6)*2;

  ///imprime a estrutura do quadro de pontos
  std::cout<<std::endl;
  for(int i=0;i<range;i++){
    if(i==0){
      std::cout<<"├";
    }else if(i==range/2){
      std::cout<<"┬";
    }else if(i==range-1){
      std::cout<<"┤"<<std::endl;
    }else{
      std::cout<<"─";
    }
  }

  std::cout<<"│ ";  
  
     
}


void Player::print_line_down(){
  ///o tamanho da linha foi dobrado a partir do tamanho da palavra e para
  ///dar espaços do lado esquerdo e direito foi adicionado 6 espaços
  
  int range=(m_name.length()+6)*2;

  std::cout<<"   │";  
  
  for(int j=0;j!=range;j++){
      if(j==(range-1) ){

      }   
      std::cout<<" ";
  }
  ///imprime a estrutura do quadro de pontos

   std::cout<<std::endl;
  for(int i=0;i<range;i++){
    if(i==0){
      std::cout<<"└";
    }else if(i==range/2){
      std::cout<<"┴";
    }else if(i==range-1){
      std::cout<<"┘";
    } else{
      std::cout<<"─";
    }
  }

   ///imprime parte inferior do score board
  

  std::cout<<std::endl;
    ///Para e limpa a tela
    std::cin.get();

    std::cout<<"Press \"Enter\" to continue >"<<std::endl;
    getchar();
    system("clear");

}


void Player::print_line_up(){

  ///o tamanho da linha foi dobrado a partir do tamanho da palavra e para
  ///dar espaços do lado esquerdo e direito foi adicionado 6 espaços
  int range=(m_name.length()+6)*2;

  ///Para e limpa a tela
  system("clear");

  ///imprime parte superior do score Board
  std::cout<<"=-------[ Top Scores ]-------="<<std::endl;
 

  std::cout<<std::endl;

  ///imprime a estrutura do quadro de pontos
  for(int i=0;i<range;i++){
    if(i==0){
      std::cout<<"┌";
    }else if(i==range-1){
      std::cout<<"┐"<<std::endl;
    }else{
      std::cout<<"─";
    }
  }

  std::cout<<"│";  

  for(int i=0;i<range;i++){
    if(i==(range/2)-6){
      std::cout<<"Score Board";
    }
    ///como foi adicionado o nome score board teve que recuar 13 espaçoes para ficar no local correto
    if(i==range-13){
      std::cout<<"│";
    }
    std::cout<<" ";
  }
  
     
}