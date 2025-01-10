#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <bitset>
class VCPU {
private:
	bool cpu_mode, ret, greater_then, equal, power_mode = false;

public:
	/*
	* If the CPU mode is set to zero you are in unrestricted mode otherwise you are in restricted
	* mode
	 The 4 bit registers mirror 0.5 bytes of the 1 byte registers
	 For example,
	 A.L is the first 4 bits of A
	 A.H is the last  4 bits of A.

	 In Restricted mode:
	 1. No interrupt access
	 2. You can only access memory that the VCPU has allocated for you
	 3. Interrupts are managed by the VINTM (Virtual Interrupt Manager)
	 4. No CPU BUS access
	 5. Access to 1 bit CPU registers other than the PM (Power Management) and R (Return) Register
	 6. No IP register access: CPU managed 
	 
	 In Unrestricted mode:
	 1. Direct hardware and memory access
	 2. No memory restrictions
	 3. CPU BUS access
	 4. Access to all of the 1 bit CPU registers
	 5. IP register access
	 Any CPU flag register is controled with a 1 (on) or a 0 (off)
	*/

    /* CPU Flag Registers */
	std::map<std::string, std::bitset<1>>registers1 = {
		{"0",   std::bitset<1>(0)},       // Power management register
		{"1",   std::bitset<1>(0)},       // Return  register (Should the CPU return back?)
		{"01",  std::bitset<1>(0)},       // Boolean register
		{"10",  std::bitset<1>(0)},       // Equal register
		{"11",  std::bitset<1>(0)},       // Greater than register
		{"001", std::bitset<1>(0)},       // CPU Mode register 
	};

	/* General Purpose Registers */

	// Low Data (4 bit registers)
	std::map<std::string, std::bitset<4>>registers4 = {
		{"1",   std::bitset<4>(0)},       //A.L -> Low Accumulator
		{"01",  std::bitset<4>(0)},      // A.H -> High Accumulator
		{"00",  std::bitset<4>(0)},     //  B.L -> Low base register
		{"001", std::bitset<4>(0)},    //   B.H -> High base register
		{"010", std::bitset<4>(0)},   //    C.L -> Low  counter register
		{"011", std::bitset<4>(0)},  //     C.H -> High counter register
		{"0001",std::bitset<4>(0)}, //      D.L -> Low data register
		{"1000",std::bitset<4>(0)}, //      D.H -> High data register
	};


	// High Data (8 bit registers)
	std::map<std::string, uint8_t>registers8 = {
		{"00000000", 0},   // A  -> Accumulator
		{"00000001", 0},   // B  -> Base
		{"00000100", 0},   // C  -> Counter
		{"00000010", 0},   // IP -> Instruction pointer
	};


	// String registers (32 bit) 
	std::map<std::string, std::string>registers32 = {
		{"0000000000", ""},// SR0 -> String Register Zero
		{"0000000001", "" },// SR1 -> String register one
		{"0000000010", "" },//SR2 -> String register two
	};

	/* CPU Instructions */

	std::map<std::string, std::function<void()>>instructions = {
		{"00", [this]() {this->add();}},
		{"01", [this]() {this->cpu_mode = this->cpu_mode ^ 1;}},
	};

	void add() {
		if (this->registers8["000"] < 15) {
			this->registers8["000"]++;
			this->registers8["001"]++; // IP += 1
		}
	}

	void execute(std::string instruction) {
		if (cpu_mode == 1) {
			if (instruction.find("1") || instruction.find("00000010")) {
				std::cout << "Restricted!";
				return;
			}
			registers8["00000010"]++;
		}
		this->instructions[instruction]();
	}
};

int main() {
	VCPU cpu;
}