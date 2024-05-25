#ifndef DI_CONTAINER_H
#define DI_CONTAINER_H

#include <string>
using namespace std;

class DIContainer {
public:
    virtual ~DIContainer() {}
    virtual void registerDependency(const string& key, void* dependency) = 0;
    virtual void* resolveDependency(const string& key) = 0;
    virtual void updateDependency(const string& key, void* dependency) = 0;
    virtual void removeDependency(const string& key) = 0;
};

#endif
