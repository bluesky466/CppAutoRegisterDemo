#include "factory.h"

static const std::string kGlobalStr = "GlobalStr";
#define GLOBAL_STR "GLOBAL_STR"

Factory& Factory::Instance() {
	static Factory instance;
	return instance;
}

Factory::Factory() {
    std::cout << "kGlobalStr : " << kGlobalStr << std::endl;
    std::cout << "GLOBAL_STR : " << GLOBAL_STR << std::endl;
}

void Factory::RegisterCreatorFunc(const std::string& name, CreatorFunc func) {
	creators_[name] = func;
}

std::shared_ptr<IComponent> Factory::Create(const std::string& name) {
	auto it = creators_.find(name);
    if (it == creators_.end()) {
        std::cout<<"Unknown : " << name <<std::endl;
        return nullptr;
    }
    auto instance = it->second();

#ifdef EN_SHARED_FROM_THIS
    return instance;
#else
    return std::shared_ptr<IComponent>(instance);
#endif
}

AutoRegister::AutoRegister(const std::string& name, CreatorFunc func) {
	Factory::Instance().RegisterCreatorFunc(name, func);
}
