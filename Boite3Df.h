#pragma once
#include <array>

class Boite3D {
		
	public:
		
		//Constructeurs
		Boite3D(std::array<double,3>, std::array<int,3>); // Initialisation de la taille de la boite
		std::array<double,3> get_longueurs() const; // Retourne les longueurs de la boite dans les 3 directions
		std::array<int,3> get_n_cubes() const; // Retourne le nombre de cubes de la boite dans les 3 directions
		std::array<double,3> get_lambdas() const; // Retourne le pas d'échantillonnage
		bool bord(int, int) const; // TRUE si le 1er argument est au bord du champ dans la direction passée en 2eme argument
		bool in_boite(int i, int j, int k) const;
		double i_to_x(int i) const; 
		double j_to_y(int j) const;
		double k_to_z(int k) const;
		
	protected:
	
		std::array<double,3> longueurs;
		std::array<int,3> n_cubes;
		std::array<double,3> lambdas;
		
};
		
			
