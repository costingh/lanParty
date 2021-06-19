#include <string>
#include <cmath>													// log2 ()
#include <fstream>
#include <iostream>
#include <iomanip> 													//setw()
#include "compara.hpp"												// fisier ce contine functii de comparare ( a strig-urilor )

class Player
{
private:
    std::string firstName;
    std::string secondName;
    int points;
public:
	Player *next_player;
	Player();
	Player(std::string, std::string, int =0);
	Player(const Player &);
	Player& operator=(const Player &);
	~Player();
	int getPoints() const;
	friend std::istream& operator>>(std::istream &, Player &);
};



