#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;


    vector<string> LF();
    string pickF(vector<string>);
    uint32_t hex(string);
    void saveF(string, string);

    string ADD(string, string);
    string AND(string, string);
    string ASR(string, string);
    string LSR(string, string);
    string LSL(string, string);
    string NOT(string);
    string ORR(string, string);
    string SUB(string, string);
    string XOR(string, string);


int main() {
    string s, filename = "output.txt";
    vector<string> Contents = LF(); 
    s = pickF(Contents); 
    saveF(s, filename);
    cout << s;
    return 0;
}

void saveF(string s, string filename) {
    ofstream file;
    file.open(filename);
    if (file.is_open()) {
        file << s;
    }
    file.close();
}


string pickF(vector<string> Contents) {
    string s;
    for (int i = 0; i < Contents.size(); i++) { 
        if ((Contents[i].compare("ADD")==0)) { 
            s = s + ADD(Contents[i+1], Contents[i+2]) + "\n";
        } else if ((Contents[i].compare("AND")==0)) { 
            s = s + AND(Contents[i+1], Contents[i+2]) + "\n";
        } else if ((Contents[i].compare("ASR")==0)) { 
            s = s + ASR(Contents[i+1], Contents[i+2]) + "\n";
        } else if ((Contents[i].compare("LSR")==0)) { 
            s = s + LSR(Contents[i+1], Contents[i+2]) + "\n";
        } else if ((Contents[i].compare("LSL")==0)) { 
            s = s + LSL(Contents[i+1], Contents[i+2]) + "\n";
        } else if ((Contents[i].compare("NOT")==0)) { 
            s = s + NOT(Contents[i+1]) + "\n";
            i--;
        } else if ((Contents[i].compare("ORR")==0)) { 
            s = s + ORR(Contents[i+1], Contents[i+2]) + "\n";
        } else if ((Contents[i].compare("SUB")==0)) { 
            s = s + SUB(Contents[i+1], Contents[i+2]) + "\n";
        } else if ((Contents[i].compare("XOR")==0)) { 
            s = s + XOR(Contents[i+1], Contents[i+2]) + "\n";
        } else {
            cout << "Error in processing text.txt" << endl;
        } i++; i++;
    }
    return s;
}
vector<string> LF() {
    ifstream file;
    vector<string> fileContent;
    string line, a;
    file.open("text.txt");

    if (file.is_open()) {
        int i;
        while (getline(file, line)) { 
            stringstream s(line);
            while (s >> a) { fileContent.push_back(a); }
        }
    }
    return fileContent;
}

uint32_t hex(string Hex) {
    uint32_t bin1;
    stringstream ss; 

    ss << hex << Hex;
    ss >> bin1;

    return bin1; 
}

string LSR(string c1, string c2) { //done
    uint32_t op1 = hex(c1), opF;
    int op2 = stoi(c2);
    opF = op1>>op2;
    string s, ss;
    stringstream sss;
    sss << uppercase << hex << opF;
    sss >> ss;
    s = "LSR 0x" + c1 + " = 0x" + ss;
    return s;
}

string ADD(string c1, string c2) { 
    uint32_t bin1 = hex(c1), bin2 = hex(c2), binF = bin1 + bin2;
    bitset<32> c(binF);
    string s, ss;
    stringstream sss;
    sss << uppercase << hex << binF;
    sss >> ss;
    s = "ADD 0x" + c1 + " 0x" + c2 + " = 0x" + ss;
    return s;
}

string AND(string c1, string c2) { 
    uint32_t bin1 = hex(c1), bin2 = hex(c2), binF = (bin1&bin2);
    bitset<32> c(binF);
    string s, ss;
    stringstream sss;
    sss << uppercase << hex << binF;
    sss >> ss;
    s = "AND 0x" + c1 + " 0x" + c2 + " = 0x" + ss;
    return s;
}

string ASR(string c1, string c2) { 
    int32_t op1 = hex(c1), opF;
    int op2 = stoi(c2);
    opF = op1>>op2;
    string s, ss;
    stringstream sss;
    sss << uppercase << hex << opF;
    sss >> ss;
    s = "ASR 0x" + c1 + " = 0x" + ss;
    return s;
}

string LSL(string c1, string c2) { 
    uint32_t op1 = hex(c1), opF;
    int op2 = stoi(c2);
    opF = op1<<op2;
    string s, ss;
    stringstream sss;
    sss << uppercase << hex << opF;
    sss >> ss;
    s = "LSL 0x" + c1 + " = 0x" + ss;
    return s;
}

string NOT(string c1) {  
    uint32_t op1 = hex(c1), opF = ~op1;
    string s, ss;
    stringstream sss;
    sss << uppercase << hex << opF;
    sss >> ss;
    s = "NOT 0x" + c1 + " = 0x" + ss;
    return s;
}

string ORR(string c1, string c2) {  
    uint32_t op1 = hex(c1), op2 = hex(c2), opF = (op1|op2);
    string s, ss;
    stringstream sss;
    sss << uppercase << hex << opF;
    sss >> ss;
    s = "ORR 0x" + c1 + " 0x" + c2 + " = 0x" + ss;
    return s;
}

string XOR(string c1, string c2) {  
    uint32_t op1 = hex(c1), op2 = hex(c2), opF = (op1^op2);
    bitset<32> c(opF);
    string s, ss;
    stringstream sss;
    sss << uppercase << hex << opF;
    sss >> ss;
    s = "ORR 0x" + c1 + " 0x" + c2 + " = 0x" + ss;
    return s;
}

string SUB(string c1, string c2) {  
    uint32_t op1 = hex(c1), op2 = hex(c2), opF = op1 - op2;
    bitset<32> c(opF);
    string s, ss;
    stringstream sss;
    sss << uppercase << hex << opF;
    sss >> ss;
    s = "ORR 0x" + c1 + " 0x" + c2 + " = 0x" + ss;
    return s;
}