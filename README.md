SOLUTIA PROBLEMEI:

EX 1:
						    | Lista	
	- am implementat urmatoarele tipuri de date-| Echipa   , unde Lista, reprezinta o lista inlantuita de echipe, iar Echipa, reprezinta o lista inlantuita de playeri
						    | Player
	- populez lista cu datele din fisier dupa cum urmeaza: citesc primul rand din fisier (x = numarul de e echipe), iar pentru x iteratii, citesc linia pe care se afla numarul de playeri din echipa = y, respectiv numele acesteia;
	- pentru y iteratii citesc datele pentru cate un player, dupa care il adaug in echipa. In final echipa este adaugata in lista (la inceputul acesteia);
	- parcurg lista de echipe, iar folosind metoda getTeamName(), accesez numele echipei curente, pe care il scriu in fisierul de iesire pe cate o linie separata

EX 2:
	- am iplementat o functie membra a clasei Lista care calculeaza cate echipe trebuie eliminate din lista
	- am implementat o functie care cauta minimul, stocheaza adresa elementului din fata acestuia, iar la sfasitul executiei, il sterge

EX 3:   
							| Stiva
	- am implementat urmatoarele structuri de date -| Coada  , unde clasa Meci contine doua elemente de tip Echipa, Coada contine n- meciuri, iar cu ajutorul Stivei stochez castigatorii si pierzatorii fiecarei runde
							| Meci
	- 1) se ia numarul de echipe din lista (N)
	  2) se creeaza N/2 meciuri in COADA
	  3) se extrag castigatorii din meciuri in STIVA ( se verifica daca in stiva mai sunt 8 echipe, adica mai sunt 2^3 runde si se returneaza aceasta )
	  4) se extrag pirezatorii in STIVA
	  5) se scriu castigatorii in fisier
	  6) se sterg pierzatorii din stiva
	  7) se goleste coada de meciuri
	  8) se se pun in coada meciurile formate cu echipele din stiva de castigatori
	  9) se scriu meciurile in fisier
	  10) se repeta pasii pana cand in coada de meciuri, mai este doar un meci
EX 4:
	- am impelementat structura de date BST	
	- se populeaza acesta cu elementele din stiva cu ultimele 8 echipe returnata de exercitiul anterior
	- se scriu in fisier echipele din bst in ordine descrescatoare

EX 5:
	- am implementat structura de date AVL
	- am implementat o functie membra care primeste ca parametru BST ul de la exercitiul anterior, si creeaza o stiva cu echipele din BST in ordine descrescatorare
	- se extrage pe rand cate o echipa din stiva creata cu elementele din bst, in ordine descrescatoare, si se introduce aceasta in avl
	
