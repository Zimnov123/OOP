#ifndef PROBLEMS_H
#define PROBLEMS_H

#include <string>
#include <vector>
using namespace std;

class Problem {
public:
    string description;
    static vector<string> DefaultProblems;
    Problem(const string& desc) : description(desc) {}
};

class CarProblem : public Problem {
public:
    CarProblem(const string& desc) : Problem(desc) {}
    static vector<CarProblem> carProblems;
    static vector<string> carGas;
    static vector<string> carElectric;
    static vector<string> carDiezel;
    static vector<string> carGasoline;
};

class TruckProblem : public Problem {
public:
    TruckProblem(const string& desc) : Problem(desc) {}
    static vector<TruckProblem> truckProblems;
    static vector<string> truckGas;
    static vector<string> truckElectric;
    static vector<string> truckDiezel;
    static vector<string> truckGasoline;
};

class MotoProblem : public Problem {
public:
    MotoProblem(const string& desc) : Problem(desc) {}
    static vector<MotoProblem> motoProblems;
    static vector<string> motoGasProblems;
    static vector<string> motoElectricProblems;
    static vector<string> motoGasolineProblems;
};

#endif 
