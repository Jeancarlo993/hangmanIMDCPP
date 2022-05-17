#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "dice.h"
#include "hangman.h"
#define GRE "\e[0;33m"
#define RED "\e[0;31m"
#define BLU "\e[0;34m"

using namespace std;


/// sorteia a palavra
string Hangman::m_select_word(){
  int num;
  vector<int>::iterator it;  //iterator para percorrer o vector de palavaras jogadas
  Dice sorteio(35);          //um dado com 35 faces
  num = sorteio.roll();      //sorteia o número
  // percorrendo o vector que tem os números já sorteados
  for(it = word_number_played.begin(); it < word_number_played.end(); it++){   
    /* ******************************************************
     * se encontrar o número no vector, sorteia novamente   * 
     * e volta o iterator pro inicio do vector              *
     ********************************************************/
    if(*it == num){
      num = sorteio.roll();
      it = word_number_played.begin();
    }  
  }
  
  //seleciona palavra do arquivo lista de palavras
  std::ifstream words("listaDePalavras.txt");
  if (words.is_open()){
    for(int i = 0; i<=num;i++){
      getline(words,m_play_word);
      if(num==i){
        return m_play_word;
      }
    }
    words.close();
  }
};

/// método construtor
Hangman::Hangman(){
  round_point = 0; 
  m_select_word();  //seleciona a palavra do jogo
};

/// retorna a palavra sorteada do jogo
std::string Hangman::m_get_play_word(){
  return m_play_word;
};

/// retorna a pontuação do round
int Hangman::get_round_point(){
  return round_point;
};

/// método do jogo
int Hangman::find_Out(){
  Hangman hang;
  char palavra[30];
  char letra;
  vector <char>letras_erradas;
  int j=0,i=0,quant_linha=m_play_word.length(),vidas=0;

  //verifica o tamanho da palavra e copia a mesma quantidade por linha
  for(int i=0;i<m_play_word.length();i++){
    if(m_play_word[i]!=' '){
     palavra[i]='_'; 
    }else{
     palavra[i]=' '; 
    }
  }
  
  while(vidas<=6){
     //Para e limpa a tela
    std::cin.get();

    cout<<GRE<<"Press \"Enter\" to continue >"<<BLU;
    getchar();
    system("clear");

    //imprime forca
    hang.print(vidas);
    
    //imprime as linhas
    for(i=0;i<m_play_word.length();i++){
        cout<<palavra[i]<<" ";
    }
    cout<<endl;

    //escolha da letra
    cout<<"choose a letter:";
    cin>>letra;
    
    //verifica se a letra existe na palavra
     for(i=0,j=0;i<m_play_word.length();i++){
      if(tolower(letra)==tolower(m_play_word[i])){
        palavra[i]=letra;

        //conta pontos por acerto
        round_point++;
      }

      if(palavra[i]=='_'){
        j++;
      }
    }

    //condição que indica a quantidade de letras e linhas
   
    if(quant_linha==j){
      vidas++;

      //reduz a pontuação
      round_point--;

      //armazena em um vetor a letra errada
      letras_erradas.push_back(letra);

      if(vidas==6){
         //imprime forca

        system("clear");
        hang.print(vidas);

        //imprime palavra que não conseguiu desvendar
        for(i=0,j=0;i<m_play_word.length();i++){
            if(palavra[i]!='_'){
              cout<<RED<<palavra[i]<<GRE<<" "; 
            }else{
              cout<<GRE<<m_play_word[i]<<RED<<" ";
            }
            
        }
        
        break;
      }
    }else{
      quant_linha=j; 
    }
    if(j==0){

      //imprime a palavra que acertou
      cout<<"word:";
      for(i=0;i<m_play_word.length();i++){
        cout<<BLU<<palavra[i]<<RED<<" ";
      }
      break;
    }

    //imprime letras erradas
    cout<<"Wrong guesses so far:";
    cout<<"<";
    for(i=0;i<letras_erradas.size();i++){
      cout<<" ";
      cout<<letras_erradas[i];
    }
    cout<<" >"<<endl;
    cout<<"Pool of point:"<<round_point<<endl;

  }
  
  //valor da pontuação
  return round_point;
};

///imprime a forca aé chegar em 6 vidas
void Hangman::print(int vidas){
  if(vidas==0){
   cout<<BLU<<" =-------[ Hangman Challenge ]-------="<<RED<<endl;

   cout<<"  ┌──────┐"<<endl;
   cout<<"  │      │"<<endl;
   cout<<"  │       "<<endl;
   cout<<"  │"       <<endl;
   cout<<"  │"       <<endl;
   cout<<"  │"       <<endl;
   cout<<"  │"       <<endl;
   cout<<"──┴──"     <<endl;
  }else if(vidas==1){
     cout<<BLU<<" =-------[ Hangman Challenge ]-------="<<RED<<endl;
    
   cout<<"  ┌──────┐"<<endl;
   cout<<"  │      │"<<endl;
   cout<<"  │ "<<GRE<<"     0"<<RED<<endl;
   cout<<"  │"       <<endl;
   cout<<"  │"       <<endl;
   cout<<"  │"       <<endl;
   cout<<"  │"       <<endl;
   cout<<"──┴──"     <<endl;
  }else if(vidas==2){
       cout<<BLU<<" =-------[ Hangman Challenge ]-------="<<RED<<endl;

   cout<<"  ┌──────┐"<<endl;
   cout<<"  │      │"<<endl;
   cout<<"  │ "<<GRE<<"     0"<<RED<<endl;
   cout<<"  │ "<<GRE<<"     │"<<RED<<endl;
   cout<<"  │"       <<endl;
   cout<<"  │"       <<endl;
   cout<<"  │"       <<endl;
   cout<<"──┴──"     <<endl;
  }else if(vidas==3){
       cout<<BLU<<" =-------[ Hangman Challenge ]-------="<<RED<<endl;

   cout<<"  ┌──────┐"<<endl;
   cout<<"  │      │"<<endl;
   cout<<"  │ "<<GRE<<"     0"<<RED<<endl;
   cout<<"  │ "<<GRE<<"    /│"<<RED<<endl;
   cout<<"  │"       <<endl;
   cout<<"  │"       <<endl;
   cout<<"  │"       <<endl;
   cout<<"──┴──"     <<endl;
  }else if(vidas==4){
     cout<<BLU<<" =-------[ Hangman Challenge ]-------="<<RED<<endl;

   cout<<"  ┌──────┐"<<endl;
   cout<<"  │      │"<<endl;
   cout<<"  │ "<<GRE<<"     0"<<RED<<endl;
   cout<<"  │ "<<GRE<<"    /│\\"<<RED<<endl;
   cout<<"  │"       <<endl;
   cout<<"  │"       <<endl;
   cout<<"  │"       <<endl;
   cout<<"──┴──"     <<endl;
  }else if(vidas==5){
       cout<<BLU<<" =-------[ Hangman Challenge ]-------="<<RED<<endl;

   cout<<"  ┌──────┐"<<endl;
   cout<<"  │      │"<<endl;
   cout<<"  │ "<<GRE<<"     0"<<RED<<endl;
   cout<<"  │ "<<GRE<<"    /│\\"<<RED<<endl;
   cout<<"  │ "<<GRE<<"    /"<<RED<<endl;
   cout<<"  │"       <<endl;
   cout<<"  │"       <<endl;
   cout<<"──┴──"     <<endl;
  }else{
       cout<<BLU<<" =-------[ Hangman Challenge ]-------="<<RED<<endl;

   cout<<"  ┌──────┐"<<endl;
   cout<<"  │      │"<<endl;
   cout<<"  │ "<<GRE<<"     0"<<RED<<endl;
   cout<<"  │ "<<GRE<<"    /│\\"<<RED<<endl;
   cout<<"  │ "<<GRE<<"    / \\"<<RED<<endl;
   cout<<"  │"       <<endl;
   cout<<"  │"       <<endl;
   cout<<"──┴──"     <<endl;
  }
}