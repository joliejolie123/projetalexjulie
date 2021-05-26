#pragma once 

class Montagne;
class MontagneGaussienne;
class ChaineDeMontagnes; //PAS SURRRRRRR
class ChampPotentiel;
class Systeme;
class Ciel;


class SupportADessin {
	
	public:
		
		virtual ~SupportADessin() = default;
		// On ne copie pas les supports
		SupportADessin(SupportADessin const&) = delete;
		SupportADessin& operator=(SupportADessin const&) = delete;
		// Mais on peut les déplacer
		SupportADessin(SupportADessin&&) = default;
		SupportADessin& operator=(SupportADessin&&) = default;
		
		SupportADessin() = default;
	
		/* Mettre ici toutes les méthodes nécessaires pour dessiner tous les objets que l'on veut dessiner. Par example:
		 * 	virtual void dessine(Avion const& a_dessiner) = 0;
		 * 	virtual void dessine(Vélo const& a_dessiner) = 0;
		*/
		
		virtual void dessine(MontagneGaussienne const&) = 0;
		virtual void dessine(Ciel const&) = 0;
		virtual void dessine(ChampPotentiel const&) = 0;
		virtual void dessine(Systeme const&) = 0;
		virtual void dessine(ChaineDeMontagnes const&) = 0; // PAS SUR!!!!!!!

		
};

