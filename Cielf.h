#pragma once
#include <vector>
#include "Boite3Df.h"
#include "CubedAirf.h"
#include "ChampPotentielf.h"
#include "SupportADessinf.h"
#include "Dessinablef.h"

class Ciel : public Boite3D, public Dessinable {
	
	public:
		// Constructeurs
		Ciel(std::array<double,3>, std::array<int,3>, double taux_humidite, double v1=0, double v2=0, double v3=0);
		Ciel(const ChampPotentiel& champ, double taux_humidite, std::array<double,3> v_default = {0.0, 0.0, 0.0});
		
		// Méthodes
		//void affiche_ciel();
		CubedAir getCube(int,int,int) const; // Retourne le cube correspondant à la posistion (i,j,k)
		void calc_nuage(double cte, double P_inf, double T_inf);
		void set_humidite(int i, int j, int k, double taux);
		std::array<int,3> previous(double dt, int i, int j, int k) const;
		void dessine_sur(SupportADessin& s) const override;
		void afficher(std::ostream& out, Montagne& montagne, std::vector<std::string> format={"v2", "h", "T", "P", "P_eau", "P_rosee", "P_nuage"}) const;
		virtual void afficher(std::ostream&) const;
		
	
	private:
		std::vector<std::vector<std::vector<CubedAir> > > air;
};
		
//std::ostream& operator <<(std::ostream& out, Ciel const& ciel);
