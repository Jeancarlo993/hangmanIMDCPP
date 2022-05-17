#include <string>
#include <vector>
using namespace std;


/***********************************************************************!
 * Essa classe lê as palavras do jogo e sorteia qual a da vez, possui o 
 * método que exibe e atualiza a forca. 
 ************************************************************************/

class Hangman{
private:
  string m_play_word;
  int round_point; //
  vector<int> word_number_played;
public:
  Hangman();
  int get_round_point();
  string m_select_word();
  string m_get_play_word();
  int find_Out();
  void print(int);
};