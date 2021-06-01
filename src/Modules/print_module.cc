#include "print_module.h"

PrintModule::PrintModule() {
  _module_name = "Print Module";
}

void PrintModule::Init(std::shared_ptr<ModuleDataCollection> data) {
}

void PrintModule::Poll(std::shared_ptr<ModuleDataCollection> data) {
  std::lock_guard<std::mutex> guard(_module_mutex);

  std::cout << "t = " << data->simulation_data.simulation_time << std::endl;
  std::cout << "x = " << data->simulation_data.x << std::endl;
  std::cout << "u = " << data->controls_data.u << std::endl;
}

