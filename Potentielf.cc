#include <iostream>
#include "Vecteur2Df.h"
#include "Potentielf.h"

Potentiel::Potentiel(Vecteur2D v1, Vecteur2D v2) {
	laplacien = v2;
	potentiel = v1;
}

void Potentiel::setPotentiel(Vecteur2D v) {
	potentiel = v;
}

void Potentiel::setLaplacien(Vecteur2D v) {
	laplacien = v;
}

Vecteur2D Potentiel::getPotentiel() const {
	return potentiel;
}

Vecteur2D Potentiel::getLaplacien() const {
	return laplacien;
}
