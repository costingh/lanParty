#include "Meci.hpp"


Meci::Meci(): next(NULL) {}

Meci::Meci(const Echipa &gazda, const Echipa &oaspete): echipa_gazda(gazda), echipa_oaspete(oaspete), next(NULL) {}

void Meci::display() const
{
	std::cout << std::left << std::setw(33) << echipa_gazda.getTeamName() << "-" << std::right << std::setw(33) << echipa_oaspete.getTeamName() << std::endl;
}

Meci::~Meci() {}

Meci& Meci::operator=(const Meci &m) 
{ 	
	if(this != &m)
	{
		echipa_gazda = m.echipa_gazda;
		echipa_oaspete = m.echipa_oaspete;
		next = NULL;	
	}
	return *this;
}

std::ostream& operator<<(std::ostream &dev, const Meci &meci) 
{
	dev << std::left << std::setw(33) << meci.echipa_gazda.getTeamName() << "-";
    dev << std::right << std::setw(33) << meci.echipa_oaspete.getTeamName();
    dev << '\n';
	return dev;
}

bool Meci::compareFloats(float a, float b)
{
	return (a - b) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * 0.00001);
}

Echipa Meci::getWinner()
{		
	if(compareFloats(echipa_gazda.getMedie(), echipa_oaspete.getMedie()))
		return echipa_gazda;
	else
		return echipa_oaspete;	
}

Echipa Meci::getLoser()
{	
	if(compareFloats(echipa_gazda.getMedie(), echipa_oaspete.getMedie()))
		return echipa_oaspete;
	else
		return echipa_gazda;
}




