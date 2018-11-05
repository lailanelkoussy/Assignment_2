//
// Created by Laila Nasser ElKoussy 900160812 on 11/5/18.
//

#ifndef ASSIGNMENT_2_INSTRUCTION_H
#define ASSIGNMENT_2_INSTRUCTION_H

#include <string>
#include "Sim.h"

class Instruction {
public:
    Instruction(std::string &, Sim*);

    virtual void execute()=0;

private:
    std::string ins;
    const Sim* simulation;

};

class Add : public Instruction {
public:
    Add(std::string in, Sim* );

};

class Neg : public Instruction {
public:
    Neg(std::string in, Sim*);
};

class Mul : public Instruction {
public:
    Mul(std::string in, Sim*);
};

class Jmp : public Instruction {
public:
    Jmp(std::string in, Sim*);
};

class Jmp0 : public Instruction {
public:
    Jmp0(std::string in, Sim*);
};

class Ass : public Instruction {
public:
    Ass(std::string in, Sim*);
};

class Le : public Instruction {
public:
    Le(std::string in, Sim*);
};

class Read : public Instruction {
public:
    Read(std::string in, Sim*);
};

class Write : public Instruction {
public:
    Write(std::string in, Sim*);
};

class Halt : public Instruction {
public:
    Halt(std::string in, Sim*);
};

#endif //ASSIGNMENT_2_INSTRUCTION_H
