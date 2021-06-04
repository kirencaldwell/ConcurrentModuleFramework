#ifndef TELEMETRY_LOGGING_H
#define TELEMETRY_LOGGING_H

#include <eigen3/Eigen/Dense>
#include <iostream>
#include <vector>
#include <fstream>

using Eigen::MatrixXd;
using Eigen::VectorXd;

class Signal {
    public:
        Signal(std::string signal_name);
        std::string GetSignalString();
        std::string GetSignalName();
        std::string GetSignalHeader();
        void SetSignalName(std::string signal_name);
        void SetSignal(MatrixXd *x);
        void SetSignal(VectorXd *x);
        void SetSignal(double *x);

    private:
        std::string _signal_name;
        MatrixXd *_mx;
        VectorXd *_vx;
        double *_dx;
        std::string _datatype;
};

class TelemetryLogging {
    public:
        void OpenFile(std::string filename);
        void AddSignal(std::string signal_name, VectorXd *signal);
        void AddSignal(std::string signal_name, MatrixXd *signal);
        void AddSignal(std::string signal_name, double *signal);
        void LogSignals();
        void CreateLogHeader();
        void EndLogging();
    private:
        std::vector<Signal> _signals;
        std::ofstream _logfile;
        std::string _filename;
        
};


// class MatrixSignal: public Signal {
//     public:
//         void CreateLink(MatrixXd *x);
//     private:
//         MatrixXd *_x;
// };

// class VectorSignal: public Signal {
//     public:
//         void CreateLink(VectorXd *x);
//     private:
//         VectorXd *_x;
// };

#endif
