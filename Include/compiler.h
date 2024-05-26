#include "HierarchicalList.h"
#include "SyntacsisControler.h"
#include <iostream>
#include <fstream>
#include <string>



class Compiler {
private:
    // ����� ������
    ifstream inputFile;
    HierarchicalList program;
    SyntacsisControler ctrl;

    // ������
    void parse();
    void generateMachineCode();
    void writeMachineCode();

public:
    Compiler(const string& inputFile);
    void compile();
}; 

