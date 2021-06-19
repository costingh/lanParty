# lanParty

## Descriere

Facultatea de Automatica si Calculatoare prin LSAC organizează in fiecare semestru un LAN Party la care participă toți studenții care vor sa își testeze abilitățile la un anumit joc. Se dorește realizarea unei soluții software(program executabil) ce poate automatiza acest proces.

## Cerinte

1. Item 1
1. Item 2
1. Item 3
   1. Item 3a
   1. Item 3b

1. Se va crea o listă cu informațiile din fișierul d.in(lista se va forma prin adaugarea elementelor la inceput - O(1)).
2. Se vor elimina din lista anterior creată, echipele cu cel mai mic punctaj de echipă (informațiile despre modul de calcul al acestui punctaj se găsesc în cadrul secțiunii Detalii Tehnice) astfel incat in lista sa ramana n echipe (unde n maxim si n este putere a lui 2).În cazul în care mai multe echipe au acelasi scor se elimina prima echipă gasita in lista. Dupa fiecare eliminare se va relua parcurgerea listei de la cap.
3. Se vor implementa structurile de date necesare pentru a se efectua meciurile:
* Se va crea o coadă în care se vor pune meciurile dintre echipe.
* Echipele vor forma meciuri în ordinea în care se află în lista de la punctul anterior, primele două echipe vor forma primul meci (și așa mai departe).
* Se vor crea două stive - una pentru învinși și una pentru câștigători - ce vor conține echipele ce au pierdut, respectiv, au câștigat meciul anterior.
* Se vor introduce în stivă echipele în funcție de rezultatul obținut și se va adauga un punct la punctajul de echipă al echipelor ce au câștigat.
* In cazul unui meci in care ambele echipe au acelasi punctaj, se va alege prima echipa adaugata in meciul disputat.
Se vor șterge echipele ce se găsesc în stiva de învinși.
* Din stiva de câștigători se vor extrage echipele și se va umple din nou coada de meciuri formându-se meciuri cu echipele consecutive (prima echipă scoasă din stivă va juca cu a doua echipa scoasă din stivă primul meci).
* Se vor repeta pașii enumerați pana la aflarea echipelor de pe primele 8 locuri, care vor fi salvate intr-o alta lista, dupa aflarea acestora se vor continua meciurile pana la aflarea echipei castigatoare.
4. Se va realiza un clasament al ultimelor 8 echipe (salvate la subpunctul anterior) sub forma unui BST(Binary Search Tree). Acesta va fi ordonat după punctajul pe echipă și i se va afișa conținutul în ordine descrescătoare(in cazul in care doua echipe au acelasi punctaj se vor ordona in functie de nume, descrescator).
5. Se va realiza un arbore de tip AVL cu ultimele 8 echipe (salvate la subpunctul 3, dar sortate ca la subpunctul 4) si se vor afisa echipele de pe nivelul 2 al arborelui.

## Detalii tehnice
* Rezultatele obținute în urma executări cerințelor din fișierul c.in vor fi scrise in fișierul r.out
* Pentru cerințele 1 si 2 este suficienta scrierea in fișierul de rezultate a numelor echipelor, in ordinea din lista creata, pe cate o linie separata.
* Pentru cerința 3 se va scrie in fișier la fiecare runda conținutul cozii de meciuri alături de conținutul stivei de învingători.
* Pentru cerința 4 se dorește afișarea BST -ului în ordine descrescătoare. Adică afișarea clasamentului în ordine descrescătoare.
* Pentru cerința 5 se dorește crearea unui AVL cu echipele de la sub punctul anterior și scrierea în fișier a echipelor de la nivelul 2.
* Structurile de date necesare trebuie deduse astfel încât sa respecte normele de buna implementare Ex: un jucator are nume, prenume, experienta - prin urmare se va folosi un tip de date care sa caracterizeze aceasta entitate:(Acelasi lucru trebuie facut si pentru alte tipuri de date necesare realizarii aplicatiei.)

### player.hpp
```cpp
class Player
{
private:
    string firstName;
    string secondName;
    int points;
};
```
Formula de calcul a punctajului de echipa este: media aritmetica a experienței (xp) jucătorilor din echipa respectiva. La fiecare meci câștigat punctajul de echipa va creste cu 1.(Trebuie modificate toate punctajele jucătorilor echipei pentru realizarea acestui task.)

### c.in
```cpp
1 0 0 0 0
```
Obiectivele se vor realiza în funcție de cum apar în fișierul cu cerinte cerinte.in (Spre exemplu dacă fișierul cerinte.in conține 1 0 0 0 0 înseamnă ca se dorește doar realizarea cerinței 1. Se vor folosi ca valori de intrare datele din fișierul date.in)

### d.in
```cpp
45                   // numarul de echipe din fisier
10 The Waiver Wire   // numarul de jucatori si numele echipei
Popa Ana-Maria 6     // nume prenume puncte jucator 1
Popescu Alexandru 10
Pop Mihaela 6
Radu Andreea 2
Dumitru Elena 1
Stan Adrian 4
Stoica Andrei 0
Gheorghe Alexandra 6
Matei Mihai 3
Ciobanu Ionut 1
 
10 The Big Egos
Ionescu Grigore 8
Rusu Cosmin-Alexandru 7
Mihai Ionut-Florin 5
Serban Victoria 3
Constantin Marius-Valentin 7
Marin Elena-Claudia 4
Stefan Maria-Roxana 9
Lazar Alina-Daniela 10
Vasile Andreea-Simona 2
Munteanu Cristina-Daniela 0
 
10 Chafing the Dream
Ilie Cristian-Mihai 10
Oprea Mihai-Catalin 8
Toma Andra-Maria 5
Florea Ioana-Mihaela 0
Moldovan Alexandru-Iulian 4
Tudor Bogdan-Ioan 6
Stanci Alexandra-Georgiana 0
Sandu Cristina-Gabriela 10
Ion Andreea-Catalina 3
Andrei Marius-Mihai 10
```
### r.out
```cpp
VALLEY GIRLS
TWISTING TORNADOES
TOUCANS
TIMBERWOLVES
TERMINATORS
TEAL TITANS
SWEETHEARTS
SUPER POWER GIRLS
SUGER BEES
STINGRAYS
STAR SHOOTERS
SPEEDY TURTLES
SPACE BABES
SOCCER DIVAS
SNOW DEVILS
SLICK CHICS
SILVER STRIKE
SILVER BUTTERFLIES
SHARKS
SCORPIONS
MUTINY
MIND TRIP
MIGHTY PANTHERS
MIDNIGHT RAIDERS
MEAN GREEN ALIENS
MANARCHS
FUGITIVES
FLASH
FLAMING TIGERS
FIRE STRIKERS
FIGHTING IRISH
AVALANCHE
 
--- ROUND NO:1
VALLEY GIRLS                     -               TWISTING TORNADOES
TOUCANS                          -                     TIMBERWOLVES
TERMINATORS                      -                      TEAL TITANS
SWEETHEARTS                      -                SUPER POWER GIRLS
SUGER BEES                       -                        STINGRAYS
STAR SHOOTERS                    -                   SPEEDY TURTLES
SPACE BABES                      -                     SOCCER DIVAS
SNOW DEVILS                      -                      SLICK CHICS
SILVER STRIKE                    -               SILVER BUTTERFLIES
SHARKS                           -                        SCORPIONS
MUTINY                           -                        MIND TRIP
MIGHTY PANTHERS                  -                 MIDNIGHT RAIDERS
MEAN GREEN ALIENS                -                         MANARCHS
FUGITIVES                        -                            FLASH
FLAMING TIGERS                   -                    FIRE STRIKERS
FIGHTING IRISH                   -                        AVALANCHE
 
WINNERS OF ROUND NO:1
FIGHTING IRISH                    -  7.80
FLAMING TIGERS                    -  6.20
FUGITIVES                         -  7.00
MEAN GREEN ALIENS                 -  6.60
MIDNIGHT RAIDERS                  -  5.70
MIND TRIP                         -  6.90
SCORPIONS                         -  6.80
SILVER BUTTERFLIES                -  7.00
SLICK CHICS                       -  5.00
SPACE BABES                       -  6.70
SPEEDY TURTLES                    -  7.90
STINGRAYS                         -  7.10
SWEETHEARTS                       -  6.90
TERMINATORS                       -  8.30
TOUCANS                           -  6.70
TWISTING TORNADOES                -  5.50
...
```
Executabilul obținut în urma compilării va avea numele lanParty, iar regula de rulare va fi:
./lanParty c.in d.in r.out




