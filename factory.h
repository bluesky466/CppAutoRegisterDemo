#ifndef __FACTORY_H__
#define __FACTORY_H__

#include <map>
#include <memory>
#include <string>
#include <iostream>

class IComponent {
public:
	virtual ~IComponent() = default;
	virtual void Init() = 0;
};

#ifdef EN_SHARED_FROM_THIS

// creator func return std::shared_ptr<IComponent>, shared_from_this will not crash

#define AUTO_REGISTER(NAME) \
static std::shared_ptr<IComponent> __##NAME##_ComponentCreatorFunc(){return std::make_shared<NAME>();} \
const AutoRegister __##NAME##_ComponentRegister(#NAME, __##NAME##_ComponentCreatorFunc);

typedef std::shared_ptr<IComponent> (*CreatorFunc)();

#else

// creator func return IComponent*, shared_from_this will crash

#define AUTO_REGISTER(NAME) \
static IComponent* __##NAME##_ComponentCreatorFunc(){return new NAME();} \
const AutoRegister __##NAME##_ComponentRegister(#NAME, __##NAME##_ComponentCreatorFunc);

typedef IComponent* (*CreatorFunc)();

#endif


class Factory {
public:
	static Factory& Instance();
	
	Factory();

	void RegisterCreatorFunc(const std::string& name, CreatorFunc func);

	std::shared_ptr<IComponent> Create(const std::string& name);

private:
	std::map<std::string, CreatorFunc> creators_;
};

class AutoRegister {
public:
	AutoRegister(const std::string& name, CreatorFunc func);
};

#endif
