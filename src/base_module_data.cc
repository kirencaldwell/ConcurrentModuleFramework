#include "base_module_data.h"
#include <fstream>

void BaseModuleData::LogTelemetry() {
    std::string out;
    std::map<std::string, std::pair<Signal, std::any>>::iterator it;
    if (_first_pass) {
        _first_pass = false;
        std::string header;
        for (it = _data.begin(); it != _data.end(); it++) {
            auto signal = it->second.first;
            header.append(signal.GetSignalHeader()); 
        }
        _buffer.append(header + "\n");
    }
    for (it = _data.begin(); it != _data.end(); it++) {
        auto signal = it->second.first;
        out.append(signal.GetSignalString());
    }
    _buffer.append(out + "\n");
}

void BaseModuleData::WriteToCsv(std::string module_name) {
    std::cout << "Writing: " << module_name << std::endl;
    std::ofstream logfile;
    logfile.open(module_name + ".csv");
    std::cout << "file is open: " << logfile.is_open() << std::endl; 
    logfile << _buffer;
    logfile.close();
}



