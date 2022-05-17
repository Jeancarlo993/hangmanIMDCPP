#include <string>
#include <vector>

/***********************************************************************!
 * Essa classe representa um jogador humano que tem um nome.
 * Além disso, o jogador também tem seus pontos conquistados no
 * round e no jogo como um todo e um dado para sortear uma palavra.
 ************************************************************************/

class Player{
	private:
		std::string m_name;						    //!< nome do jogador
		int m_total_points;						    //!< pontos do jogo
		int m_round_points;						    //!< pontos do turno

	public:
		Player();				                  //!< construtor
		std::string m_get_name();					//!< retorna nome
		void m_set_name();				        //!< ajusta o nome
		void m_set_total_points(int);			//!< modifica pontuação total
		int m_get_total_points();					//!< retorna pontuação total
		void m_set_round_points(int);			//!< modifica pontuação do turno
    void m_sum_round_points(int);     //!< recebe os pontos e soma com os que já tem
		int m_get_round_points();					//!< retorna pontuação do turno
};
