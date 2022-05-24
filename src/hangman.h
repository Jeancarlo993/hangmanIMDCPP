#include <string>
#include <vector>
using namespace std;


/***********************************************************************!
 * Essa classe lê as palavras do jogo e sorteia qual a da vez, possui o 
 * método que exibe e atualiza a forca. 
 ************************************************************************/

class Hangman{
private:
  string m_play_word;              //! a palavra sorteada
  int round_point;                 //! pontos obtidos em uma partida
  vector<int> word_number_played;  //! vetor com numeros das palavras sorteadas
  int life;                        //! as vidas do jogador
  char guess;                      //! palpite
  char word_vec[30];               //! vetor que será exibido e modificado em cada palpite
  vector <char>wrong_guess;        //! vector com palpites errados
public:
  Hangman();                       //! método construtor
  void print();                    //! imprime a forca
  void print_word();               //! imprime o vetor da palavra do turno
  void guess_in();                 //! recebe e avalia um palpite
  int eval_hang_status();          //! avalia se o jogo acabou ou segue
  int get_round_point();           //! retorna os pontos obtidos na partida
  void m_select_word();            //! sorteia a palavra da partida
  string m_get_play_word();        //! retorna a palavra da partida
  void game_over(int);             //! game over, 0(perdeu); 1(venceu)
  void wrong_letter();             //! imprime os palpites errados    
  void make_word_line();           //! prepara o word_vec
  int point_now();                 //!imprime a pontuação do turno
};