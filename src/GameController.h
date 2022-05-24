#include "player.h"

class GameController{
  private:
    char m_option;				    //! variável que recebe opção
    Player player1;           //! jogador
 
  public:
    int estado;               //! Estado do jogo
    int m_state;              //! se 1 o jogo segue, se 0 o jogo chegao ao fim
    void m_play_game();       //! Método que executa o jogo inteiro
    void m_show_rules();      //! Método que imprime as regras do jogo
    void m_game_over();		    //! Fim no jogo
    void m_tela_inicial();	  //! Exibe a tela inicial
    void m_option_in();       //! Método que processa a entrada
    void eval_option();       //! Avalia a opção do Game controller e executa um dos métodos
    void m_quit();            //! muda o estado do jogo pro 0
    
};