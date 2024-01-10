#include "factory.h"
#include "component_b.h"

int main(int argc,char **argv) {
	// has not #include "component_a.h", ComponentA will not auto register when use static library dependent
	auto a = Factory::Instance().Create("ComponentA");
	if(a != nullptr) {
		a->Init(); 
	}

	// has #include "component_a.h",ComponentA will auto register when use static library dependent
	auto b = Factory::Instance().Create("ComponentB");
	if(b != nullptr) {
		b->Init(); 
	}
	return 0;
}
