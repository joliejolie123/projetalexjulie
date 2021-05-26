#include "Vecteur2Df.h"
#include <iostream>
#include <cmath>
using namespace std;

// Setter pour les coordonnées
void Vecteur2D::set_coord(double x_, double y_) {
	x = x_;
	y = y_;
}

// Affichage des coordonnées
ostream& Vecteur2D::affiche(ostream& sortie) const {
	sortie << "( " << x << ", "  << y << " )";
	return sortie;	
};

// Surcharge de cout
ostream& operator<<(ostream& sortie, Vecteur2D const& v);

ostream& operator<<(ostream& sortie, Vecteur2D const& v){
		return v.affiche(sortie);
}
	
// Comparaison de deux vecteurs 
bool Vecteur2D::compare(const Vecteur2D& autre) const {	
	return((abs(autre.x - x) <= 1e-10) and (abs(autre.y - y) <= 1e-10));	
}

// Surcharge pour comparer deux vecteurs 
bool operator==(Vecteur2D v, Vecteur2D& autre) ;

bool operator==(Vecteur2D v, Vecteur2D& autre) {
	
	return v.compare(autre);
	
}
	
// Addition de deux vecteurs 
Vecteur2D Vecteur2D::addition(Vecteur2D autre) const {
	Vecteur2D c;
	c.set_coord(x + autre.getX(), y + autre.getY());
	return c;
}

// Soustraction de deux vecteurs 
Vecteur2D Vecteur2D::soustraction(Vecteur2D autre) const {
	Vecteur2D c;
	c.set_coord(x - autre.getX(), y - autre.getY());
	return c;
}

// L'opposé d'un vecteur 
Vecteur2D Vecteur2D::oppose() const {
	Vecteur2D c;
	c.set_coord(-x, -y);
	return c;
	
}

// La multiplication par un scalaire 
Vecteur2D Vecteur2D::mult(double k) const {
	Vecteur2D c;
	c.set_coord(k*x, k*y);
	return c;

}

//Le produit scalaire de deux vecteurs
double Vecteur2D::prod_scal(Vecteur2D autre) const {
	double c;
	c = x * autre.getX() + y * autre.getY();
	return c;
}

// La norme d'un vecteur 
double Vecteur2D::norme() const {
	double c;
	c = sqrt(x*x + y*y);
	return c;	
}

// La norme au carré
double Vecteur2D::norme2() const {
	return norme()*norme();
}

// Vecteur unitaire 
Vecteur2D Vecteur2D::unitaire() const {
	return mult(1/norme());
}

const Vecteur2D operator+(Vecteur2D v1, Vecteur2D const& v2 );
const Vecteur2D operator-(Vecteur2D v1, Vecteur2D const& v2 );
const Vecteur2D operator*(double a, Vecteur2D const& v);

const Vecteur2D operator*(double a, Vecteur2D const& v) {
	Vecteur2D v2(a * v.getX(), a * v.getY());
	return v2;
}

Vecteur2D& Vecteur2D::operator-() {
	x = -x;
	y = -y;
	return *this;
}

// Surcharge d'addition 
const Vecteur2D operator+(Vecteur2D v1, Vecteur2D const& v2 ){
	Vecteur2D v3(v1.getX() + v2.getX(), v1.getY() + v2.getY());
	return v3;
};

// Surcharge de soustraction
const Vecteur2D operator-(Vecteur2D v1, Vecteur2D const& v2 ){
	Vecteur2D v3(v1.getX() - v2.getX(), v1.getY() - v2.getY());
	return v3;
};

