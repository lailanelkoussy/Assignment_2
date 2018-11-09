//
// Created by Laila Nasser ElKoussy 900160812 on 11/5/18.
//

#include "Instruction.h"
#include <iostream>

using namespace std;

Instruction::Instruction(std::string &a, Sim *b) : ins(a), simulation(b) {

}

void Instruction::print() {
    cout << ins << endl;
}

Add::Add(std::string in, Sim *a) : Instruction(in, a) {

}

void Add::execute() {

}


Neg::Neg(std::string in, Sim *a) : Instruction(in, a) {

}

void Neg::execute() {

}

Mul::Mul(std::string in, Sim *a) : Instruction(in, a) {

}

void Mul::execute() {

}

Jmp::Jmp(std::string in, Sim *a) : Instruction(in, a) {

}

void Jmp::execute() {

    string temp1;

    if (ins.find('$') == -1)
        throw MyException(4);
    else {
        temp1 = ins.substr(ins.find('$') + 1);
        for (char element : temp1)
            if (!isdigit(element))
                throw MyException(4);

        simulation->changePCto(atoi(temp1.c_str()));

    }
}

Jmp0::Jmp0(std::string in, Sim *a) : Instruction(in, a) {

}

void Jmp0::execute() {

}

Ass::Ass(std::string in, Sim *a) : Instruction(in, a) {

}

void Ass::execute() {

}

Le::Le(std::string in, Sim *a) : Instruction(in, a) {

}

void Le::execute() {

}

Read::Read(std::string in, Sim *a) : Instruction(in, a) {

}

void Read::execute() {
    string temp1;
    int enter;


    if (ins.find('#') == -1)
        throw MyException(4);
    else {

        temp1 = ins.substr(ins.find('#') + 1);
        for (char element : temp1)
            if (!isdigit(element))
                throw MyException(5);
        cin >> enter;
        simulation->saveInto(enter, atoi(temp1.c_str()));


    }

}


Write::Write(std::string in, Sim *a) : Instruction(in, a) {

}

void Write::execute() {

}

Halt::Halt(std::string in, Sim *a) : Instruction(in, a) {

}

void Halt::execute() {
    simulation->stop();

}

