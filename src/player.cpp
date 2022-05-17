#include <string>
#include <vector>
#include <iostream>
#include "player.h"

/// Construtor de uma máquina
Player::Player(){
	m_name = "Pedron";
	m_total_points = 0;
	m_round_points = 0;
}; 
/// ajusta o nome do jogador
void Player::m_set_name(){
	std::cin >> m_name;
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
