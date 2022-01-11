#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string instruction;
    std::cin >> instruction;
    int nops = 0;
    int next_instr_loc = 0;
    int curr_mem_loc = 0;
    // invariant: next_instr_loc points to next machine instruction
    // curr_mem_loc points to the supposed ideal location of the pointer 
    for (int i = 0; i < instruction.size(); i++) {
        if (std::isupper(instruction[i])) {
            nops += next_instr_loc - curr_mem_loc;
            curr_mem_loc = next_instr_loc;
        }
        next_instr_loc = (curr_mem_loc+4) - (curr_mem_loc%4);
        curr_mem_loc++;
    }
    std::cout << nops << std::endl;
}