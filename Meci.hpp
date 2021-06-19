#include "Lista.hpp"

class Meci
{
private:
	Echipa echipa_gazda, echipa_oaspete;	
public:
	Meci *next;
	Meci();
	Meci(const Echipa& , const Echipa& );
	~Meci();
	Meci& operator=(const Meci &);
	Echipa getWinner();
	Echipa getLoser();
	void display() const;
	bool compareFloats(float , float );
	friend std::ostream& operator<<(std::ostream &, const Meci &);
};
