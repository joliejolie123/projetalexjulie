#pragma once
#include <iostream>
#include "SupportADessinf.h"

class Dessinable {
	
	public:
		virtual ~Dessinable() = default;
		Dessinable(Dessinable const&) = default;
		Dessinable& operator=(Dessinable const&) = default;
		Dessinable(Dessinable&&) = default;
		Dessinable& operator=(Dessinable&&) = default;
		
		Dessinable() = default;
		
		virtual void dessine_sur(SupportADessin&) const = 0; // Ecrira un texte dans la version "mode texte" et dessinera quelque chose lorsqu'on ajoute du graphisme
		virtual void afficher(std::ostream&) const = 0; // Si on enleve ostream comme argument ca marche plus
	
};

