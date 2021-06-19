#include "Player.hpp"

class Echipa
{
private:
	int nr_players;
	float media;
	int sumaPuncte;
	std::string nume_echipa;
	Player *start;
public: 
	Echipa *next_team;
	Echipa();
	~Echipa();
	Echipa(int nr, std::string nume);
	Echipa(const Echipa &);
	Echipa& operator=(const Echipa &);
	std::string getTeamName() const;
	float getMedie() const;
	void addPlayer(const Player &);
	void display() const;
	void calcMedie();
	void modificaMedie();
	void writeTeam(std::ofstream &) const;
	void adauga_player_la_final(const Player &);
	friend std::istream& operator>>(std::istream &, Echipa &);
	friend std::ostream& operator<<(std::ostream &, const Echipa &);
};
