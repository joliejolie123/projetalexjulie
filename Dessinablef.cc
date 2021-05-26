#include "Dessinablef.h"

std::ostream& operator<<(std::ostream& out, Dessinable const& objet) {
	objet.afficher(out);
	return out;
}
