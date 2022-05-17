#include <ctime>
#include <time.h>

/*! 
 *Essa classe representa um dado que pode ter várias faces.
 *Basseado na quantidade de faces, retorna um número aleatório
 *de 1 até o numero de faces
 */
class Dice{
	private:
		int faces; 	    //!< Quantidade de faces que tem o dado
	public:
		Dice(int);	     //!< Método construtor
		Dice();		//!< Método construtor
		int roll(); //!< Método que gera o número aleatório
    void set_faces(int);
};
