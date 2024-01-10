#ifndef __COMPONENT_B_H__
#define __COMPONENT_B_H__

#include "factory.h"

class ComponentB : public IComponent, public std::enable_shared_from_this<ComponentB> {
public:
	void Init() override;
};

AUTO_REGISTER(ComponentB)

#endif