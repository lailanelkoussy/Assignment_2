//
// Created by Laila Nasser ElKoussy 900160812 on 11/5/18.
//

#ifndef ASSIGNMENT_2_SIM_H
#define ASSIGNMENT_2_SIM_H

#include "Instruction.h"

class Sim {
public:
    void changePCto(int&);
    void saveInto(int&, int&);


private:
    int data[1028];
    Instruction inst[1028];
    friend class Halt;

};


#endif //ASSIGNMENT_2_SIM_H
