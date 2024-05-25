#ifndef VEHICLE_DI_CONTAINER_H
#define VEHICLE_DI_CONTAINER_H

#include <unordered_map>
#include <string>
#include <iostream> 
#include "vehicle.h"
#include "di_container.h"

class VehicleDIContainer : public DIContainer {
private:
    std::unordered_map<std::string, void*> dependencies;

public:
    void registerDependency(const std::string& key, void* dependency) override {
        if (dependencies.find(key) == dependencies.end()) {
            dependencies[key] = dependency;
        }
    }

    void updateDependency(const std::string& key, void* dependency) override {
        auto it = dependencies.find(key);
        if (it != dependencies.end()) {
            it->second = dependency;
        }
    }

    void* resolveDependency(const std::string& key) override {
        auto it = dependencies.find(key);
        if (it != dependencies.end()) {
            return it->second;
        }
        return nullptr;
    }

    void removeDependency(const std::string& key) {
        dependencies.erase(key);
    }
};

#endif
