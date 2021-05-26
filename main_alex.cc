#include<iostream>
#include<cmath>
#include "Vecteur2Df.h"
#include "ChampPotentielf.h"
#include "Montagnef.h"
#include "Potentielf.h"

using namespace std;


int main(){

    Montagne himalaya(15.0*(20.0/29.0),15.0*(20.0/29.0),15.0*(20.0/29.0)-20/2,5*(20.0/29.0),5*(20.0/29.0));
    ChampPotentiel champ(20.0,20.0,20.0,20.0/29.0);
    champ.initialise(20.0,himalaya);
    champ.calcule_laplacien(himalaya);
    champ.affiche_laplacien();
}
