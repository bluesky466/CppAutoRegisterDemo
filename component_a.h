#ifndef __COMPONENT_A_H__
#define __COMPONENT_A_H__

#include "factory.h"

class ComponentA : public IComponent {
public:
	void Init() override;
};

AUTO_REGISTER(ComponentA)

#endif