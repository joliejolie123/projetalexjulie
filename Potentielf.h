#pragma once
#include "Vecteur2Df.h"

class Potentiel {
	
	public:
		Potentiel(Vecteur2D, Vecteur2D);
		void setPotentiel(Vecteur2D);
		void setLaplacien(Vecteur2D);
		Vecteur2D getPotentiel() const; // Retourne le vecteur Potentiel
		Vecteur2D getLaplacien() const; // Retourne le vecteur Laplacien
		
	private:
		Vecteur2D potentiel;
		Vecteur2D laplacien;
};
