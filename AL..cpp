/* AL -> Abstraction Layer */
// To my future self or anyone else sorry, but I wasn't thinking when I written this

#include <map>
#include <string>
class x86AL{
private:
    enum registers{
        RAX,
        RBX,
        RCX,
        RDX,
        RDI,
        RSI,
        RBP,
        RSP,
        EAX,
        EBX,
        ECX,
        EDX,
        ESI,
        EDI,
        EBP,
        ESP,
        AX,
        BX,
        CX,
        DX,
        SI,
        DI,
        SP,
        BP,
        AL,
        BL,
        CL,
        DL,
        AH,
        BH,
        CH,
        DH,
    };
    enum instructions{
        MOV,
        CMP,
        JE,
        JNE,
        JG,
        JB,
        JNB,
        ADD,
        SUB,
        MUL,
        DIV,
        BYTE,
        PTR,
        WORD,
        NOP,
        INT,
        PUSH, 
        POP,
        XCHG,
        LODSB,
        XOR,
        AND,
        OR,
        NOT,
        SHR,
        SHL,
        SAL,
        SAR,
        CMOVE,
        CMOVNE,
        QWORD,
        DWORD,
    };
    std::map<int, std::string>ISA;
public:
   x86AL(){
           ISA[NOP]    = "NOP";
           ISA[INT]    = "INT";
           ISA[MOV]    = "MOV";
           ISA[ADD]    = "ADD";
           ISA[SUB]    = "SUB";
           ISA[MUL]    = "MUL";
           ISA[DIV]    = "DIV";
           ISA[BYTE]   = "BYTE";
           ISA[PTR]    = "PTR";
           ISA[WORD]   = "WORD";
           ISA[INT]    = "INT";
           ISA[CMP]    = "CMP";
           ISA[PUSH]   = "PUSH";
           ISA[POP]    = "POP";
           ISA[XCHG]   = "XCHG";
           ISA[LODSB]  = "LODSB";
           ISA[XOR]    = "XOR";
           ISA[AND]    = "AND";
           ISA[OR]     = "OR";
           ISA[NOT]    = "NOT";
           ISA[SHR]    = "SHR";
           ISA[SHL]    = "SHL";
           ISA[SAL]    = "SAL";
           ISA[SAR]    = "SAR";
           ISA[QWORD]  = "QWORD";
           ISA[CMOVE]  = "CMOVE";
           ISA[CMOVNE] = "CMOVNE";
           ISA[DWORD]  = "DWORD";
           ISA[JNE]    = "JNE";  
           ISA[AX]     = "AX";
           ISA[BX]     = "BX";
           ISA[CX]     = "CX";
           ISA[DX]     = "DX";
           ISA[SI]     = "SI";
           ISA[DI]     = "DI";
           ISA[SP]     = "SP";
           ISA[BP]     = "BP";
           ISA[AL]     = "AL";
           ISA[AH]     = "AH";
           ISA[BL]     = "BL";
           ISA[BH]     = "BH";
           ISA[CL]     = "CL";
           ISA[CH]     = "CH";
           ISA[DL]     = "DL";
           ISA[DH]     = "DH";
           ISA[EAX]    = "EAX";
           ISA[EBX]    = "EBX";
           ISA[ECX]    = "ECX";
           ISA[EDX]    = "EDX";
           ISA[ECX]    = "ECX";
           ISA[ESI]    = "ESI";
           ISA[EDI]    = "EDI";
           ISA[EBP]    = "EBP";
           ISA[ESP]    = "ESP";
           ISA[RAX]    = "RAX";
           ISA[RBX]    = "RBX";
           ISA[RCX]    = "RCX";
           ISA[RDX]    = "RDX";
           ISA[RSI]    = "RSI";
           ISA[RDI]    = "RDI";
           ISA[RSP]    = "RSP";
   }
};
