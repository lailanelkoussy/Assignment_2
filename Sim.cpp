//
// Created by Laila Nasser ElKoussy 900160812 on 11/5/18.
//

#include "Sim.h"
#include <fstream>
#include <iostream>
#include <string>
#include <exception>

using namespace std;

Sim::Sim(std::string a) {
    ifstream file;
    string line;
    instCount = 0;
    try {
        file.open(a);
        if (!file.is_open())
            throw MyException(1);;

        for (int i = 0; (i < SIZE + 1) && (file.good()); i++) {
            if (i == SIZE)
                throw MyException(2);;

            std::getline(file, line);
            switch (line[0]) {
                case 'a':
                case 'A':
                    if (line.find("add") != -1 || line.find("Add") != -1 ||
                        line.find("ADD") != -1) //if it is an add instruction
                    { inst[i] = new Add(line, this); }
                    else if (line.find("ass") != -1 || line.find("Ass") ||
                             line.find("ASS")) // if it as an ass instruction
                        inst[i] = new Ass(line, this);
                    else throw MyException(0);
                    break;

                case 'h':
                case 'H':
                    if (line.find("halt") != -1 || line.find("Halt") != -1 || line.find("HALT") != -1)
                        inst[i] = new Halt(line, this);
                    else throw MyException(0);
                    break;

                case 'j':
                case 'J':
                    if (line.find("jmp0") != -1 || line.find("Jmp0") != -1 ||
                        line.find("JMP0") != -1) //if it is a jump0 instruction
                        inst[i] = new Jmp0(line, this);
                    else if (line.find("jmp") != -1 || line.find("Jmp") != -1 ||
                             line.find("JMP") != -1) // if it as an ass instruction
                        inst[i] = new Jmp(line, this);
                    else throw MyException(0);
                    break;

                case 'l':
                case 'L':
                    if (line.find("le") != -1 || line.find("Le") != -1 || line.find("LE") != -1)
                        inst[i] = new Le(line, this);
                    else throw MyException(0);
                    break;

                case 'm':
                case 'M':
                    if (line.find("mul") != -1 || line.find("Mul") != -1 || line.find("MUL") != -1)
                        inst[i] = new Mul(line, this);
                    else throw MyException(0);
                    break;

                case 'n':
                case 'N':
                    if (line.find("neg") != -1 || line.find("Neg") != -1 || line.find("NEG") != -1)
                        inst[i] = new Neg(line, this);
                    else throw MyException(0);
                    break;

                case 'r':
                case 'R':
                    if (line.find("read") != -1 || line.find("Read") != -1 || line.find("READ") != -1)
                        inst[i] = new Read(line, this);
                    else throw MyException(0);
                    break;
                case 'w':
                case 'W':
                    if (line.find("write") != -1 || line.find("Write") != -1 || line.find("WRITE") != -1)
                        inst[i] = new Write(line, this);
                    else throw MyException(0);
                    break;
                case char(0):
                    instCount--;
                    break;
                default:
                    throw MyException(0);


            }
            instCount++;
        }

    }
    catch (MyException e) {
        cout << e.what();
    }
    catch (...) {
        cout << "Uncaught exception occured";
    }

    file.close();
}

void Sim::run() {
    PC = 0;
    running = true;
    try{
    while (running && PC < instCount) {
        inst[PC]->print();
        inst[PC]->execute();
        PC++;
    }}
    catch (MyException e){
        cout<<e.what();
    }

}

void Sim::changePCto(const int &a) {

    if (a > SIZE || a < 0)
        throw MyException(3);;
    PC = a - 1;

}

void Sim::saveInto(int &a, int b){

    if (a > SIZE)
        throw MyException(3);
    else data[a] = b;

}

void Sim::stop() {
    running = false;
}