#pragma once

#include <iostream>
#include "SupportADessinf.h"

class TextViewer : public SupportADessin {
	
	public:
		TextViewer(std::ostream& flot);
		virtual ~TextViewer() = default;
		
		TextViewer(TextViewer const&) = delete;
		TextViewer& operator=(TextViewer const&) = delete;
		TextViewer(TextViewer&&) = default;
		TextViewer& operator=(TextViewer&&) = default;
		
		virtual void dessine(MontagneGaussienne const&);
		virtual void dessine(Ciel const&);
		virtual void dessine(Systeme const&);
		virtual void dessine(ChampPotentiel const&);
		virtual void dessine(ChaineDeMontagnes const&);
		
	private:
		std::ostream& flot;
};
