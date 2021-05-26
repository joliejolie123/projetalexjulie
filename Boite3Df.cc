
#include <iostream>
#include "Boite3Df.h"

// Constructeurs
Boite3D::Boite3D(std::array<double,3> l, std::array<int,3> n) {
	for(int i(0); i < 3; ++i) {
		longueurs[i] = l[i];
		n_cubes[i] = n[i];
		lambdas[i] = longueurs[i] / (n_cubes[i] - 1);
	}
}

bool Boite3D::bord(int n, int axe) const {
	// Retourne TRUE si n est à une extremité de l'axe (0 pour l'axe x, 1 pour l'axe y, 2 pour l'axe z)
	return n==0 or n==n_cubes[axe] -1;
}

double Boite3D::i_to_x(int i) const {
	return i * lambdas[0];
}

double Boite3D::j_to_y(int j) const {
	return j * lambdas[1] - longueurs[1] / 2;
}

double Boite3D::k_to_z(int k) const {
	return k * lambdas[2];
}

bool Boite3D::in_boite(int i, int j, int k) const {
	return (i >= 0 and i < n_cubes[0] and j >= 0 and j < n_cubes[1] and k >= 0 and k < n_cubes[2]);
}

std::array<double,3> Boite3D::get_longueurs() const {
	return longueurs;
}

std::array<int,3> Boite3D::get_n_cubes() const {
	return n_cubes;
}

std::array<double,3> Boite3D::get_lambdas() const {
	return lambdas;
}
