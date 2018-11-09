//
// Created by Laila Nasser ElKoussy 900160812 on 11/5/18.
//

#ifndef ASSIGNMENT_2_SIM_H
#define ASSIGNMENT_2_SIM_H

const int SIZE = 1024;

#include "Instruction.h"

class Instruction;

struct MyException;

class Sim {
public:
    Sim(std::string);

    void run();

    void changePCto(const int &);  //edits the PC
    void saveInto(int &, int);  //saves first value into second data address
    int getData(int a) { return data[a]; }

    void stop();    //stops simulation (called by Halt)


private:
    friend class Instruction;

    int data[SIZE];
    Instruction *inst[SIZE];
    bool running;
    unsigned int PC, instCount;

};

struct MyException {
    MyException(int a) {
        switch (a) {
            case 0:
                wha = "Unknown Instruction";
                break;
            case 1:
                wha = "Cannot Open File";
                break;

            case 2:
                wha = "Too Many Instructions";
                break;

            case 3:
                wha = "Out of Range";
                break;

            case 4:
                wha = "Syntax Error";
                break;

            case 5:
                wha = "Instruction Extraction Problem";
                break;

            default:
                wha = "Unknown Error";
                break;
        }
    }


    std::string what() {
        return wha;
    }

private:
    std::string wha;


};


#endif //ASSIGNMENT_2_SIM_H
