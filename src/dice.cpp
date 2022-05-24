#include <cstdlib>
#include <ctime>
#include "dice.h"

/// Por padrão, o dado tem 6 faces
Dice::Dice(){
	faces = 6;
};
/// mas também pode-se iniciar o dado com outra quantidade de faces
Dice::Dice(int f){
	faces = f;
};
/// método que retorna um valor aleatório de 1 até faces
int Dice::roll(){ 
	unsigned seed = time(0);
	srand(seed);
	return (rand()%faces);
};
/// método para alterar numero de faces do dado
void Dice::set_faces(int f){
  faces = f;
};