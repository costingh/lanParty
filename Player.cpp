#include "Player.hpp"

Player::Player():points(0), next_player(NULL) {}

Player::Player(std::string fn, std::string sn, int pts): firstName(fn), secondName(sn), points(pts) {}

Player::Player(const Player &p) 
{
	firstName = p.firstName;
	secondName = p.secondName;
	points = p.points;
	next_player = NULL;	
	*this = p;
}

Player& Player::operator=(const Player &p) 
{ 	
	if(this != &p)
	{
		firstName = p.firstName;
		secondName = p.secondName;
		points = p.points;
		next_player = NULL;
	}
  return *this;
}

int Player::getPoints() const { return points; }

Player::~Player() {}

std::istream& operator>>(std::istream &dev, Player &player) 
{
	dev >> player.firstName >> player.secondName >> player.points;
	return dev;
}

