#include <vector>
#include <iostream>
#include "Dessinablef.h"
#include "Cielf.h"
//#include "Montagne.h"
//#include "ChampPotentielf.h"

class Systeme : public Dessinable {
	
	public:
	
		Systeme(ChampPotentiel*, MontagneGaussienne*, double, double, double, double, double);
		Montagne* getMontagne() const;
		ChampPotentiel* getChamp() const;
		Ciel* getCiel() const;
		void deplacerNuages(double dt = 0);
		virtual void dessine_sur(SupportADessin& support) const;
		virtual void afficher(std::ostream&) const override;
		void evolue(double dt=0); // Fait éventuellement une boucle sur tous les CubedAir pour remettre à jour leur état, appelle la méthode dessine_sur() du Système
		void demarre(SupportADessin& support); // Résout l'équation de Laplace pour le ChampPotentiel, construit le Ciel à partir du ChampPotentiel, 
			// fait éventuellement une boucle sur tous les CubedAirs pour remettre à jour leur état, appelle la méthode dessine_sur() du Système, appelle la méthode evolue() du Système
		void afficher_ciel(std::ostream& out, std::vector<std::string> format={"v2", "h", "T", "P", "P_eau", "P_rosee", "nuage"}, char sep=' ') const;
		
	private:
	
		ChampPotentiel* champ;
		MontagneGaussienne* montagne;
		Ciel* ciel;
		double v_inf;
		double cte;
		double P_inf;
		double T_inf;
		double taux_humidite_initial;
		
};

