build:
	g++ main.cpp utils.h utils.cpp Lista.cpp Lista.hpp Player.hpp Player.cpp Echipa.hpp Echipa.cpp Coada.cpp Coada.hpp Stiva.hpp Stiva.cpp Meci.hpp Meci.cpp BST.cpp BST.hpp AVL.cpp AVL.hpp -o lanParty
run:
	./lanParty c.in d.in r.out
clean:
	rm lanParty
