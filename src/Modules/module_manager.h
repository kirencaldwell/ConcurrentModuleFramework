#ifndef MODULE_MANAGER_H
#define MODULE_MANAGER_H

#include <vector>
#include <thread>
#include <iostream>
#include "base_module.h"

class ModuleManager {

  public:
    void AddModules(std::vector<BaseModule*> modules);
    void InitModules();
    void StartModules();

  private:
   
    std::vector<BaseModule*> _modules;

};


#endif
