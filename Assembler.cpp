#include <map>
#include <string>
class Assembler {
public:
	std::map<std::string, std::string>instructions = {
		{"pmr", "0"},  // Power management/mode register
		{"rtr", "1"},  // Return register
		{"blr", "01"}, // boolean register
		{"eqr", "10"}, // Equal Register
		{"gtr", "11"}, // Greater Then register
		{"cpmr", "001"}, // CPU Mode Register
		{"a.l", "1"},
		{"a.h", "01"},
		{"b.h", "00"},
		{"b.l", "001"},
		{"sr0", "0000000000"}, // string register 0
		{"sr1", "0000000001"}, // string register 1
		{"sr2", "0000000010"},
	};
};