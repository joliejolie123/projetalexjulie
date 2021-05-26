#include <iostream>
#include "Boite3Df.h"

int main() {
	
	Boite3D b({20,20,20}, {30,30,30});
	for (auto l : b.get_lambdas()) {
		std::cout << l << std::endl;
	}
	
	return 0;
}
