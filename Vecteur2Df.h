#pragma once
#include <ostream>

class Vecteur2D {
	
	public:
	
		// Constructeurs
		Vecteur2D()
		: x(0.0), y(0.0)
		{}
		Vecteur2D(double x, double y)
		: x(x), y(y)
		{}
		
		// Méthodes
		double getX() const {
			return x;
		}
		double getY() const {
			return y;
		}
		void set_coord(double x_, double y_);
		std::ostream& affiche(std::ostream& sortie) const;
		bool compare(const Vecteur2D& autre) const;
		
		// Surcharge
		Vecteur2D& operator-();
		Vecteur2D addition(Vecteur2D autre) const;
		Vecteur2D soustraction(Vecteur2D autre) const;
		Vecteur2D oppose() const;
		Vecteur2D mult(double k) const;
		double prod_scal(Vecteur2D autre) const;
		double norme() const;
		double norme2() const;
		Vecteur2D unitaire() const;
		
	private:
	
		double x;
		double y;
	
};

std::ostream& operator<<(std::ostream& sortie, Vecteur2D const& v);

bool operator==(Vecteur2D v, Vecteur2D& autre) ;

const Vecteur2D operator+(Vecteur2D v1, Vecteur2D const& v2 );
const Vecteur2D operator-(Vecteur2D v1, Vecteur2D const& v2 );
const Vecteur2D operator*(double a, Vecteur2D const& v);

