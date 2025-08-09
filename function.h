#ifndef functions
    #define functions
    using namespace std;

    class Programme
    {
        public:
        int counter = 0;                //holds the program counter
        int reg[7] = {};                //register
        int memory[64] = {};            //memory
        string overflow = "false";
        bool underflow = false;
        bool carry = false;
        bool zero = false;
    };

    //trimming functions
    string trim(string);
    string leftTrim(string);
    string rightTrim(string);

    string trimParameter(string);
    string leftBracketTrim(string);
    string rightBracketTrim(string);
    string leftRTrim(string);

    //getNumber
    int getNumber(string);    //convert "[R1]" to 1

    //converting functions (binary and decimal)
    void decToBinary(int, int[]);
    int binaryToDec(int[]);

    //display functions
    void display(Programme&, ofstream&);   //MAIN DISPLAY FUNCTION
    void displayRegister(Programme&, ofstream&);  
    void displayFlags(Programme&, ofstream&);
    void displayPC(Programme&, ofstream&);
    void displayMemory(Programme&, ofstream&);

    //output functions
    void output(Programme&);

    //method function
    void methodIN(string, Programme&, ofstream&);
    void methodOUT(string, Programme&, ofstream&);
    void methodMOV(string, string, Programme&, ofstream&);
    void methodADD(string, string, Programme&, ofstream&);
    void methodSUB(string, string, Programme&, ofstream&);
    void methodMUL(string, string, Programme&, ofstream&);
    void methodDIV(string, string, Programme&, ofstream&);
    void methodINC(string, Programme&, ofstream&);
    void methodDEC(string, Programme&, ofstream&);
    void methodROL(string, string, Programme&, ofstream&);
    void methodROR(string, string, Programme&, ofstream&);
    void methodSHL(string, string, Programme&, ofstream&);
    void methodSHR(string, string, Programme&, ofstream&);
    void methodLOAD(string, string, Programme&, ofstream&);
    void methodSTORE(string, string, Programme&, ofstream&);

    //checking
    void checkInput(string, ofstream&);
    void checkCommmand(string, ofstream&);
    void checkRegister(int, ofstream&);
    void checkMemory(int, ofstream&);
    void checkFlag(int, Programme&, ofstream&);
#endif