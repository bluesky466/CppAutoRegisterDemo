#include "component_b.h"

void ComponentB::Init() {
	std::cout << "ComponentB::Init() - " << this->shared_from_this() <<std::endl;
}