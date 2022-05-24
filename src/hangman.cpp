#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "hangman.h"
#include "dice.h"

#define GRE "\e[0;33m"
#define RED "\e[0;31m"
#define BLU "\e[0;34m"

using namespace std;

/// sorteia a palavra
void Hangman::m_select_word() {
  int num;
  vector<int>::iterator
      it;               /// iterator para percorrer o vector de palavras jogadas
  Dice sorteio(35);     /// um dado com 35 faces
  num = sorteio.roll(); /// sorteia o número
  // percorrendo o vector que tem os números já sorteados
  for (it = word_number_played.begin(); it < word_number_played.end(); it++) {
    /* *******************************************************
     * se encontrar o número no vector, sorteia novamente    *
     * e volta o iterator pro inicio do vector               *
     *********************************************************/
    if (*it == num) {
      num = sorteio.roll();
      it = word_number_played.begin();
    }
  }

  /***********************************************************
   * Abre o arquivo listaDePalavras, se der certo a abertura *
   * percorre o arquivo até a linha do número que foi sortea *
   * do e coloca a palavra da linha em m_play_word.
   ***********************************************************/
  std::ifstream words("listaDePalavras.txt");
  if (words.is_open()) {
    for (int i = 0; i <= num; i++) {
      getline(words, m_play_word);
    }
    words.close();
  }
};

/// método construtor
Hangman::Hangman() {
  life = 0;
  round_point = 0;
  m_select_word(); /// seleciona a palavra do jogo
};

/// retorna a palavra sorteada do jogo
std::string Hangman::m_get_play_word() { return m_play_word; };

/// retorna a pontuação do round
int Hangman::get_round_point() { return round_point; };

/// imprime as linhas e letras acertadas
void Hangman::print_word() {
  for (int i = 0; i < m_play_word.length(); i++) {
    cout << word_vec[i] << " ";
  }
  cout << endl;
};

/// copia a quantidade de caracteres em linhas
void Hangman::make_word_line() {
  for (int i = 0; i < m_play_word.length(); i++) {
    if (m_play_word[i] != ' ') {
      word_vec[i] = '_';
    }
  }
}

/// imprime lista de palpites errados
void Hangman::wrong_letter() {
  cout << "Wrong guesses so far:";
  cout << "<";
  for (int i = 0; i < wrong_guess.size(); i++) {
    cout << " ";
    cout << wrong_guess[i];
  }
  cout << " >" << endl;
}

/// avalia o estado do jogo
int Hangman::eval_hang_status() {
  if (life == 6) {
    game_over(0);
    return 1;
  } else if (life != 6) {
    /// verifica se a palavra foi advinhada ou se perdeu o jogo

    for (int i = 0; i < m_play_word.length(); i++) {
      if (word_vec[i] == '_') {
        return 2;
      }
    }
    game_over(1);
    return 1;
  }
  return 2;
};

/// recebe um palpite e avalia se ta certo ou errado
void Hangman::guess_in() {
  
  int points = 0;

  cout <<"choose a letter:"<<endl;
  
  cin >> guess;
  if(guess=='#'){  ///opção para desistir do jogo
    round_point=0;
    life=6;
  }
  else{
    for (int i = 0; i < m_play_word.length(); i++) {
      /// palpite certo
      if (tolower(guess) == tolower(m_play_word[i])) {
        if(word_vec[i] != guess){
          word_vec[i] = guess;
          points++;
        }
      }
    }
    /// palpite errado
    if (points == 0) {
      life++;
      round_point--;
      wrong_guess.push_back(guess);
    } else {
      round_point += points;
    }

    ///Para e limpa a tela
    std::cin.get();
    cout << BLU << "Press \"Enter\" to continue >";
    
    getchar();
    system("clear");
  }
};

/// imprime a pontuação no momento
int Hangman::point_now() {
  
  cout << GRE "Pool of point:" << round_point << BLU << endl;

  return round_point;

}

/// existem dois tipos de game over, caso desista ou perca, caso vença
void Hangman::game_over(int gameOverType) {
  if (gameOverType == 0) { /// desistiu ou perdeu
    std::cout << GRE << "YOU LOOSE" << std::endl;
    std::cout << RED << "word: ";
    for (int i = 0; i < m_play_word.length(); i++) {

      if (word_vec[i] == '_') {
        std::cout << GRE << m_play_word[i];
      } else {
        std::cout << RED << word_vec[i];
      }
    }
    std::cout << std::endl;
  }
  if (gameOverType == 1) { /// venceu
    std::cout << GRE << "YOU WIN" << std::endl;
    std::cout << RED << "word: ";
    for (int i = 0; i < m_play_word.length(); i++) {
      std::cout << BLU << word_vec[i];
    }
    std::cout << std::endl;
  }
};

/// imprime a forca até chegar em 6 vidas
void Hangman::print() {
  if (life == 0) {
    cout << BLU << " =-------[ Hangman Challenge ]-------=" << RED << endl;

    cout << "  ┌──────┐" << endl;
    cout << "  │      │" << endl;
    cout << "  │       " << endl;
    cout << "  │" << endl;
    cout << "  │" << endl;
    cout << "  │" << endl;
    cout << "  │" << endl;
    cout << "──┴──" << endl;
  } else if (life == 1) {
    cout << BLU << " =-------[ Hangman Challenge ]-------=" << RED << endl;

    cout << "  ┌──────┐" << endl;
    cout << "  │      │" << endl;
    cout << "  │ " << GRE << "     0" << RED << endl;
    cout << "  │" << endl;
    cout << "  │" << endl;
    cout << "  │" << endl;
    cout << "  │" << endl;
    cout << "──┴──" << endl;
  } else if (life == 2) {
    cout << BLU << " =-------[ Hangman Challenge ]-------=" << RED << endl;

    cout << "  ┌──────┐" << endl;
    cout << "  │      │" << endl;
    cout << "  │ " << GRE << "     0" << RED << endl;
    cout << "  │ " << GRE << "     │" << RED << endl;
    cout << "  │" << endl;
    cout << "  │" << endl;
    cout << "  │" << endl;
    cout << "──┴──" << endl;
  } else if (life == 3) {
    cout << BLU << " =-------[ Hangman Challenge ]-------=" << RED << endl;

    cout << "  ┌──────┐" << endl;
    cout << "  │      │" << endl;
    cout << "  │ " << GRE << "     0" << RED << endl;
    cout << "  │ " << GRE << "    /│" << RED << endl;
    cout << "  │" << endl;
    cout << "  │" << endl;
    cout << "  │" << endl;
    cout << "──┴──" << endl;
  } else if (life == 4) {
    cout << BLU << " =-------[ Hangman Challenge ]-------=" << RED << endl;

    cout << "  ┌──────┐" << endl;
    cout << "  │      │" << endl;
    cout << "  │ " << GRE << "     0" << RED << endl;
    cout << "  │ " << GRE << "    /│\\" << RED << endl;
    cout << "  │" << endl;
    cout << "  │" << endl;
    cout << "  │" << endl;
    cout << "──┴──" << endl;
  } else if (life == 5) {
    cout << BLU << " =-------[ Hangman Challenge ]-------=" << RED << endl;

    cout << "  ┌──────┐" << endl;
    cout << "  │      │" << endl;
    cout << "  │ " << GRE << "     0" << RED << endl;
    cout << "  │ " << GRE << "    /│\\" << RED << endl;
    cout << "  │ " << GRE << "    /" << RED << endl;
    cout << "  │" << endl;
    cout << "  │" << endl;
    cout << "──┴──" << endl;
  } else {
    cout << BLU << " =-------[ Hangman Challenge ]-------=" << RED << endl;

    cout << "  ┌──────┐" << endl;
    cout << "  │      │" << endl;
    cout << "  │ " << GRE << "     0" << RED << endl;
    cout << "  │ " << GRE << "    /│\\" << RED << endl;
    cout << "  │ " << GRE << "    / \\" << RED << endl;
    cout << "  │" << endl;
    cout << "  │" << endl;
    cout << "──┴──" << endl;
  }
}
