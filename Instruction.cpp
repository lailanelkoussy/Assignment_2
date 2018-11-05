//
// Created by Laila Nasser ElKoussy 900160812 on 11/5/18.
//

#include "Instruction.h"

Instruction::Instruction(std::string &a, Sim *b): ins(a), simulation(b) {

}

Add::Add(std::string in, Sim *a): Instruction(in,a) {

}

Neg::Neg(std::string in, Sim *a): Instruction(in,a) {

}

Mul::Mul(std::string in, Sim *a): Instruction(in,a) {

}

Jmp::Jmp(std::string in, Sim *a): Instruction(in,a) {

}
Jmp0::Jmp0(std::string in, Sim *a): Instruction(in,a) {

}

Ass::Ass(std::string in, Sim *a): Instruction(in,a) {

}

Le::Le(std::string in, Sim *a): Instruction(in,a) {

}
Read::Read(std::string in, Sim *a): Instruction(in,a) {

}

Write::Write(std::string in, Sim *a): Instruction(in,a) {

}

Halt::Halt(std::string in, Sim *a): Instruction(in,a) {

}

