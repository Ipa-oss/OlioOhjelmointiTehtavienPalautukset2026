/*
//TUNTIESIMERKKI
#include <iostream>

using namespace std;

int main()
{
    int koe = 5;
    printf("Hello World C:n tavalla = %d\n",koe);
    cout << "Hello World!" << koe << endl;
    return 0;
}*/

/*
//OSA1
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));
    int luku = (rand() % 20)+1; // rand() % 20 on luku väliltä 0-19. täten kyseinen luku+1 on luku väliltä 1-20 eli 1 on offset.
    cout << "Arvaa arvottu luku väliltä 1-20." << endl;
    int arvaus = 0;
    while(arvaus!=luku){ // Poistuu loopista kun vastaus on oikein.
        cin >> arvaus;
        if(arvaus<luku){
            cout << "Liian pieni." << endl;
        }else if(arvaus>luku){
            cout << "Liian suuri." << endl;
        }
    }
    cout << "Oikein!" << endl;
}*/

/*
//OSA2
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game(){
    srand(time(NULL));
    int luku = (rand() % 20)+1; // rand() % 20 on luku väliltä 0-19. täten kyseinen luku+1 on luku väliltä 1-20 eli 1 on offset.
    cout << "Arvaa arvottu luku väliltä 1-20." << endl;
    int arvaus = 0;
    int arvauslkm = 0;
    while(arvaus!=luku){ // Poistuu loopista kun vastaus on oikein.
        cin >> arvaus;
        if(arvaus<luku){
            cout << "Liian pieni." << endl;
        }else if(arvaus>luku){
            cout << "Liian suuri." << endl;
        }
        arvauslkm++;
    }
    cout << "Oikein!" << endl;
    return arvauslkm;
}

int main(){
    int tulos = game();
    cout << "Arvausten lukumäärä: " << tulos << endl;
}*/

/*
//OSA3
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game(int maxnum){
    srand(time(NULL));
    int luku = (rand() % maxnum)+1; // rand() % 20 on luku väliltä 0-19. täten kyseinen luku+1 on luku väliltä 1-20 eli 1 on offset.
    cout << "Arvaa arvottu luku väliltä 1-" << maxnum << endl;
    int arvaus = 0;
    int arvauslkm = 0;
    while(arvaus!=luku){ // Poistuu loopista kun vastaus on oikein.
        cin >> arvaus;
        if(arvaus<luku){
            cout << "Liian pieni." << endl;
        }else if(arvaus>luku){
            cout << "Liian suuri." << endl;
        }
        arvauslkm++;
    }
    cout << "Oikein!" << endl;
    return arvauslkm;
}

int main(){
    int suurin = 0;
    cout << "Anna suurin luku, jonka haluat pelin arpovan." << endl;
    cin >> suurin;
    int tulos = game(suurin);
    cout << "Arvausten lukumäärä: " << tulos << endl;
}*/
