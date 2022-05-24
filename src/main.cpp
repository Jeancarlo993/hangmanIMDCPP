#include <iostream>
#include <unistd.h>
#include "GameController.h"



int main() { 
  GameController play; 
  play.m_tela_inicial();
  
  while(play.estado == 1){
      play.m_option_in(); ///recebe a opção
      play.eval_option(); ///avalia e executa a opção
  }
return 0; 

}