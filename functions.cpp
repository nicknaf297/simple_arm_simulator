#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "function.h"
using namespace std;

//TRIMMING FUNCTIONS

string leftTrim(string input)
{
    int i = 0;
    while (i < input.length())
    {
        if (input[0] == ',')
        {
            input.erase(0,1);
        }
        i = i + 1;
    }
    return input;
}

string rightTrim(string input)
{
    int i = 0;
    while (i < input.length())
    {
        if (input[input.length() - 1] == ',')
        {
            input.erase(input.length() - 1, 1);
        }
        i = i + 1;
    }
    return input;
}

string trim(string input)

{
    input = leftTrim(input);
    input = rightTrim(input);

    return input;
}

string leftBracketTrim(string input)
{
    int i = 0;
    while (i < input.length())
    {
        if (input[0] == '[')
        {
            input.erase(0,1);
        }
        i = i + 1;
    }
    return input;
}

string leftRTrim(string input)
{
    int i = 0;
    while (i < input.length())
    {
        if (input[0] == 'R')
        {
            input.erase(0,1);
        }
        i = i + 1;
    }
    return input;
}

string rightBracketTrim(string input)
{
    int i = 0;
    while (i < input.length())
    {
        if (input[input.length() - 1] == ']')
        {
            input.erase(input.length() - 1, 1);
        }
        i = i + 1;
    }
    return input;
}

string trimParameter(string input)  //[R1] -> 1 (string)
{
    input = leftBracketTrim(input);
    input = rightBracketTrim(input);
    input = leftRTrim(input);

    return input;
}


//GET NUMBER FUNCTION

int getNumber(string parameter)
{
    string para = trimParameter(parameter);
    return stoi(para);
}



//DISPLAYING FUNCTIONS

void displayMemory(Programme& prog, ofstream& outFile)
{
cout << "MEMORY: " << endl;
    for (int position = 0; position <= 7; position++)
    {
        cout << setw(2) << setfill('0') << prog.memory[position] << " ";
        outFile << setw(2) << setfill('0') << prog.memory[position] << " ";
    }
    cout << endl;
    outFile << endl;

    for (int position = 8; position <= 15; position++)
    {
        cout << setw(2) << setfill('0') << prog.memory[position] << " ";
        outFile << setw(2) << setfill('0') << prog.memory[position] << " ";
    }
    cout << endl;
    outFile << endl;

    for (int position = 16; position <= 23; position++)
    {
        cout << setw(2) << setfill('0') << prog.memory[position] << " ";
        outFile << setw(2) << setfill('0') << prog.memory[position] << " ";
    }
    cout << endl;
    outFile << endl;
    
    for (int position = 24; position <= 31; position++)
    {
        cout << setw(2) << setfill('0') << prog.memory[position] << " ";
        outFile << setw(2) << setfill('0') << prog.memory[position] << " ";
    }
    cout << endl;
    outFile << endl;
    
    for (int position = 32; position <= 39; position++)
    {
        cout << setw(2) << setfill('0') << prog.memory[position] << " ";
        outFile << setw(2) << setfill('0') << prog.memory[position] << " ";
    }
    cout << endl;
    outFile << endl;

    for (int position = 40; position <= 47; position++)
    {
        cout << setw(2) << setfill('0') << prog.memory[position] << " ";
        outFile << setw(2) << setfill('0') << prog.memory[position] << " ";
    }
    cout << endl;
    outFile << endl;
    
    for (int position = 48; position <= 55; position++)
    {
        cout << setw(2) << setfill('0') << prog.memory[position] << " ";
        outFile << setw(2) << setfill('0') << prog.memory[position] << " ";
    }
    cout << endl;
    outFile << endl;

    for (int position = 56; position <= 63; position++)
    {
        cout << setw(2) << setfill('0') << prog.memory[position] << " ";
        outFile << setw(2) << setfill('0') << prog.memory[position] << " ";
    }
    cout << endl << "#";
    outFile << endl << "#";
}


void displayRegister(Programme& prog, ofstream& outFile)
{
    cout << "REGISTERS  : R0 R1 R2 R3 R4 R5 R6" << endl;
    outFile << "REGISTERS  : R0 R1 R2 R3 R4 R5 R6" << endl;
    cout << "             ";
    outFile << "             ";

    for (int position = 0; position < 7; position++)
    {
        cout << setw(2) << setfill('0') << prog.reg[position] << " ";
        outFile << setw(2) << setfill('0') << prog.reg[position] << " ";
    }
    cout << "#" << endl;
    outFile << "#" << endl;
}

void displayFlags(Programme& prog, ofstream& outFile)
{
    cout << "FLAGS      : OF UF CF ZF" << endl;
    outFile << "FLAGS      : OF UF CF ZF" << endl;
    cout << "             ";
    outFile << "             ";

    cout << setw(2) << setfill('0') << prog.overflow << " ";
    outFile << setw(2) << setfill('0') << prog.overflow << " ";
    cout << setw(2) << setfill('0') << prog.underflow << " ";
    outFile << setw(2) << setfill('0') << prog.underflow << " ";
    cout << setw(2) << setfill('0') << prog.carry << " ";
    outFile << setw(2) << setfill('0') << prog.carry << " ";
    cout << setw(2) << setfill('0') << prog.zero << " " << "#" << endl;
    outFile << setw(2) << setfill('0') << prog.zero << " " << "#" << endl;
}

void displayPC(Programme& prog, ofstream& outFile)
{
    cout << "PC         : " << prog.counter << endl;
    outFile << "PC         : " << prog.counter << endl;
}

void display(Programme& prog, ofstream& outFile)
{
    cout << endl;
    outFile << endl;
    displayRegister(prog, outFile);
    displayFlags(prog, outFile);
    displayPC(prog, outFile);
    displayMemory(prog, outFile);
    cout << endl << endl << endl;
    outFile << endl << endl << endl;
}



//CONVERT BINARY
void decToBinary(int decimal, int binary[])
{
    int position = 7;
    while (position >= 0)
    {
        binary[position] = decimal % 2;
        decimal = decimal / 2;
        position = position - 1;
    }
}

int binaryToDec(int binary[])
{
    int decimal = 0;
    for (int i = 0, j = 7; j > -1; i++, j--)
    {
        decimal = decimal + binary[i]*pow(2,j);
    }
    return decimal;
}



//METHOD FUNCTIONS

void methodIN(string parameter, Programme& prog, ofstream& outFile)
{
    if (parameter[0] == 'R')
    {
        int input;                              //holds the input by the user
        int location = getNumber(parameter);    //hold the register location

        checkRegister(location, outFile);

        cout << "Input the number to be input in R" << location << " : ";
        outFile << "Input the number to be input in R" << location << " : ";
        cin >> input;
        outFile << input;
        cout << endl;
        outFile << endl;

        checkFlag(input, prog, outFile);

        prog.reg[location] = input;

        prog.counter = prog.counter + 1;
    }
    else
    {
        cout << "Incorrect Parameter: " << parameter << endl;
        outFile << "Incorrect Parameter: " << parameter << endl;
        exit(EXIT_FAILURE);
    }
}

void methodOUT(string parameter, Programme& prog, ofstream& outFile)
{
    if (parameter[0] == 'R')
    {
        int location = getNumber(parameter);    //hold the register location

        checkRegister(location, outFile);

        cout << "The number at R" << location << " is " << prog.reg[location] << endl;
        outFile << "The number at R" << location << " is " << prog.reg[location] << endl;

        prog.counter = prog.counter + 1;
    }

    else
    {
        cout << "Incorrect Parameter: " << parameter << endl;
        outFile << "Incorrect Parameter: " << parameter << endl;
        exit(EXIT_FAILURE);
    }
}

void methodMOV(string parameter1, string parameter2, Programme& prog, ofstream& outFile)
{
    if (parameter2[0] != 'R')
    {
        cout << "Incorrect Parameter: " << parameter1 << " " << parameter2 << endl;
        outFile << "Incorrect Parameter: " << parameter1 << " " << parameter2 << endl;
        exit(EXIT_FAILURE);
    }
    else if (parameter1[0] == 'R' && parameter2[0] == 'R')
    {
        int location1, location2;           //store index of register
        
        location1 = getNumber(parameter1);
        checkRegister(location1, outFile);
        location2 = getNumber(parameter2);
        checkRegister(location2, outFile);

        prog.reg[location2] = prog.reg[location1];

        prog.counter = prog.counter + 1;
    }
    else if (parameter1[0] == '[' && parameter1[1] == 'R' && parameter1[3] == ']' && parameter2[0] == 'R')
    {
        int location1, location2;           //store index of register

        location1 = getNumber(parameter1);
        checkRegister(location1, outFile);
        location2 = getNumber(parameter2);
        checkRegister(location2, outFile);

        int address;                        //store address of memory
        int MEM;                            //store value in memory

        address = prog.reg[location1];
        checkMemory(address, outFile);
        MEM = prog.memory[address];

        prog.reg[location2] = MEM;

        prog.counter = prog.counter + 1;
    }
    else if (parameter2[0] == 'R')
    {
        int location;           //store index of register
        int value;              //store value input

        value = getNumber(parameter1);
        location = getNumber(parameter2);
        checkRegister(location, outFile);
        
        prog.reg[location] = value;

        prog.counter = prog.counter + 1;
    }
    else
    {
        cout << "Incorrect Parameter: " << parameter1 << " " << parameter2 << endl;
        outFile << "Incorrect Parameter: " << parameter1 << " " << parameter2 << endl;
        exit(EXIT_FAILURE);
    }
}

void methodADD(string parameter1, string parameter2, Programme& prog, ofstream& outFile)
{
    if(parameter1[0] == 'R' && parameter2[0] == 'R')
    {
        int result;                     //store result of ADD
        int location1, location2;       //store location of register

        location1 = getNumber(parameter1);
        checkRegister(location1, outFile);
        location2 = getNumber(parameter2);
        checkRegister(location2, outFile);

        result = prog.reg[location1] + prog.reg[location2];

        checkFlag(result, prog, outFile);

        prog.reg[location2] = result;        //assign result to register

        prog.counter = prog.counter + 1;
    }
    else
    {
        cout << "Incorrect Parameter: " << parameter1 << " " << parameter2 << endl;
        outFile << "Incorrect Parameter: " << parameter1 << " " << parameter2 << endl;
        exit(EXIT_FAILURE);
    }
}

void methodSUB(string parameter1, string parameter2, Programme& prog, ofstream& outFile)
{
    if(parameter1[0] == 'R' && parameter2[0] == 'R')
    {
        int result;                     //store result of SUB
        int location1, location2;       //store location of register

        location1 = getNumber(parameter1);
        checkRegister(location1, outFile);
        location2 = getNumber(parameter2);
        checkRegister(location2, outFile);

        result = prog.reg[location1] - prog.reg[location2];

        checkFlag(result, prog, outFile);

        prog.reg[location2] = result;        //assign result to register

        prog.counter = prog.counter + 1;
    }
    else
    {
        cout << "Incorrect Parameter: " << parameter1 << " " << parameter2 << endl;
        outFile << "Incorrect Parameter: " << parameter1 << " " << parameter2 << endl;
        exit(EXIT_FAILURE);
    }    
}

void methodMUL(string parameter1, string parameter2, Programme& prog, ofstream& outFile)
{
        if(parameter1[0] == 'R' && parameter2[0] == 'R')
    {
        int result;                     //store result of MUL
        int location1, location2;       //store location of register

        location1 = getNumber(parameter1);
        checkRegister(location1, outFile);
        location2 = getNumber(parameter2);
        checkRegister(location2, outFile);

        result = prog.reg[location1] * prog.reg[location2];

        checkFlag(result, prog, outFile);

        prog.reg[location2] = result;        //assign result to register

        prog.counter = prog.counter + 1;
    }
    else
    {
        cout << "Incorrect Parameter: " << parameter1 << " " << parameter2 << endl;
        outFile << "Incorrect Parameter: " << parameter1 << " " << parameter2 << endl;
        exit(EXIT_FAILURE);
    }  
}

void methodDIV(string parameter1, string parameter2, Programme& prog, ofstream& outFile)
{
    if(parameter1[0] == 'R' && parameter2[0] == 'R')
    {
        int result;                     //store result of DIV
        int location1, location2;       //store location of register

        location1 = getNumber(parameter1);
        checkRegister(location1, outFile);
        location2 = getNumber(parameter2);
        checkRegister(location2, outFile);

        if (prog.reg[location2] == 0)
        {
            cout << "Cannot divide by 0" << endl;
            outFile << "Cannot divide by 0" << endl;
            exit(EXIT_FAILURE);
        }

        result = prog.reg[location1] / prog.reg[location2];

        checkFlag(result, prog, outFile);

        prog.reg[location2] = result;        //assign result to register

        prog.counter = prog.counter + 1;
    }
    else
    {
        cout << "Incorrect Parameter: " << parameter1 << " " << parameter2 << endl;
        outFile << "Incorrect Parameter: " << parameter1 << " " << parameter2 << endl;
        exit(EXIT_FAILURE);
    }  
}

void methodINC(string parameter1, Programme& prog, ofstream& outFile)
{
    if (parameter1[0] == 'R')
    {
        int location1;      //store index of register
        int value;          //store value in register

        location1 = getNumber(parameter1);
        checkRegister(location1, outFile);

        value = prog.reg[location1];
        value++;

        checkFlag(value, prog, outFile);

        prog.reg[location1] = value;

        prog.counter = prog.counter + 1;
    }
    else
    {
        cout << "Incorrect Parameter: " << parameter1 << endl;
        outFile << "Incorrect Parameter: " << parameter1 << endl;
        exit(EXIT_FAILURE);
    }
}

void methodDEC(string parameter1, Programme& prog, ofstream& outFile)
{
    if (parameter1[0] == 'R')
    {
        int location1;      //store index of register
        int value;          //store value in register

        location1 = getNumber(parameter1);
        checkRegister(location1, outFile);

        value = prog.reg[location1];
        value--;

        checkFlag(value, prog, outFile);

        prog.reg[location1] = value;

        prog.counter = prog.counter + 1;
    }
    else
    {
        cout << "Incorrect Parameter: " << parameter1 << endl;
        outFile << "Incorrect Parameter: " << parameter1 << endl;
        exit(EXIT_FAILURE);
    }
}

void methodROL(string parameter1, string parameter2, Programme& prog, ofstream& outFile)
{
    if (parameter1[0] == 'R' && parameter2[0] != 'R' && parameter2[0] != '[')
    {
        int binary[8];                              //store binary output
        int location, numberRotations;              //store location of register

        location = getNumber(parameter1);
        checkRegister(location, outFile);
        numberRotations = getNumber(parameter2);

       decToBinary(prog.reg[location], binary);     //convert to binary

       cout << endl << "Before rotation: ";
       outFile << endl << "Before rotation: ";         //before rotation
            for (int j = 0; j < 8; j++)
            {
            cout << binary[j];
            outFile << binary[j];
            }


            //rotation operation
            for (int i = 0; i < numberRotations; i++)
            {
                int temp;
                temp = binary[0];

                binary[0] = binary[1];
                binary[1] = binary[2];
                binary[2] = binary[3];
                binary[3] = binary[4];
                binary[4] = binary[5];
                binary[5] = binary[6];
                binary[6] = binary[7];

                binary[7] = temp;

            } 

            cout << endl << "After rotation : ";
            outFile << endl << "After rotation : ";     //after rotation
            for (int j = 0; j < 8; j++)
            {
            cout << binary[j];
            outFile << binary[j];
            }
            cout << endl;

            int newNumber;                      //store new number after conversion
            newNumber = binaryToDec(binary);

            checkFlag(newNumber, prog, outFile);

            prog.reg[location] = newNumber;   //store into register

            prog.counter = prog.counter + 1;
        } 

        else
        {
            cout << "Incorrect Parameter: " << parameter1 << " " << parameter2 << endl;
            outFile << "Incorrect Parameter: " << parameter1 << " " << parameter2 << endl;
            exit(EXIT_FAILURE);
        }  
}

void methodROR(string parameter1, string parameter2, Programme& prog, ofstream& outFile)
{
    if (parameter1[0] == 'R' && parameter2[0] != 'R' && parameter2[0] != '[')
    {
        int binary[8];                              //store binary output
        int location, numberRotations;              //store location of register

        location = getNumber(parameter1);
        checkRegister(location, outFile);
        numberRotations = getNumber(parameter2);

       decToBinary(prog.reg[location], binary);     //convert to binary

       cout << endl << "Before rotation: ";
       outFile << endl << "Before rotation: ";         //before rotation
            for (int j = 0; j < 8; j++)
            {
            cout << binary[j];
            outFile << binary[j];
            }
                         
            for (int i = 0; i < numberRotations; i++) //rotation operation
            {
                int temp;
                temp = binary[7];

                binary[7] = binary[6];
                binary[6] = binary[5];
                binary[5] = binary[4];
                binary[4] = binary[3];
                binary[3] = binary[2];
                binary[2] = binary[1];
                binary[1] = binary[0];

                binary[0] = temp;
            }  

           cout << endl << "After rotation : ";
           outFile << endl << "After rotation : ";     //after rotation
           for (int j = 0; j < 8; j++)
           {
            cout << binary[j];
            outFile << binary[j];
           }
           cout << endl;
           outFile << endl;

            int newNumber;                      //store new number after conversion
            newNumber = binaryToDec(binary);

            checkFlag(newNumber, prog, outFile);

            prog.reg[location] = newNumber;   //store into register

            prog.counter = prog.counter + 1;
        } 

        else
        {
            cout << "Incorrect Parameter: " << parameter1 << " " << parameter2 << endl;
            outFile << "Incorrect Parameter: " << parameter1 << " " << parameter2 << endl;
            exit(EXIT_FAILURE);
        }  
}

void methodSHL(string parameter1, string parameter2, Programme& prog, ofstream& outFile)
{
    if (parameter1[0] == 'R' && parameter2[0] != 'R' && parameter2[0] != '[')
        {
            int binary[8];                              //store binary output
            int location, numberShifts;              //store location of register

            location = getNumber(parameter1);
            checkRegister(location, outFile);
            numberShifts = getNumber(parameter2);

        decToBinary(prog.reg[location], binary);     //convert to binary

        cout << endl << "Before shifting: ";
        outFile << endl << "Before shifting: ";         //before rotation
            for (int j = 0; j < 8; j++)
            {
            cout << binary[j];
            outFile << binary[j];
            }

            int temp;                               
            for (int i = 0; i < numberShifts; i++) //rotation operation
            {
                binary[8] = {0};

                binary[0] = binary[1];
                binary[1] = binary[2];
                binary[2] = binary[3];
                binary[3] = binary[4];
                binary[4] = binary[5];
                binary[5] = binary[6];
                binary[6] = binary[7];
                binary[7] = binary[8];
            } 

        cout << endl << "After shifting : ";
        outFile << endl << "After shifting : ";     //after rotation
        for (int j = 0; j < 8; j++)
        {
            cout << binary[j];
            outFile << binary[j];
        }
        cout << endl;
        outFile << endl;

        int newNumber;                            //store new number after conversion
        newNumber = binaryToDec(binary);

        checkFlag(newNumber, prog, outFile);

        prog.reg[location] = newNumber;             //store into register

        prog.counter = prog.counter + 1;
        } 

        else
        {
            cout << "Incorrect Parameter: " << parameter1 << " " << parameter2 << endl;
            outFile << "Incorrect Parameter: " << parameter1 << " " << parameter2 << endl;
            exit(EXIT_FAILURE);
        }  
}

void methodSHR(string parameter1, string parameter2, Programme& prog, ofstream& outFile)
{
    if (parameter1[0] == 'R' && parameter2[0] != 'R' && parameter2[0] != '[')
        {
            int binary[8];                              //store binary output
            int location, numberShifts;              //store location of register

            location = getNumber(parameter1);
            checkRegister(location, outFile);
            numberShifts = getNumber(parameter2);

        decToBinary(prog.reg[location], binary);     //convert to binary

        cout << endl << "Before shifting: ";
        outFile << endl << "Before shifting: ";         //before rotation
            for (int j = 0; j < 8; j++)
            {
            cout << binary[j];
            outFile << binary[j];
            }

            int temp;                               
            for (int i = 0; i < numberShifts; i++) //rotation operation
            {
                binary[8] = binary[7];
                binary[7] = binary[6];
                binary[6] = binary[5];
                binary[5] = binary[4];
                binary[4] = binary[3];
                binary[3] = binary[2];
                binary[2] = binary[1];
                binary[1] = binary[0];
                binary[0] = {0};
            } 

        cout << endl << "After shifting : ";
        outFile << endl << "After shifting : ";     //after rotation
        for (int j = 0; j < 8; j++)
        {
            cout << binary[j];
            outFile << binary[j];
        }
        cout << endl;

        int newNumber;                      //store new number after conversion
        newNumber = binaryToDec(binary);

        checkFlag(newNumber, prog, outFile);

        prog.reg[location] = newNumber;   //store into register

        prog.counter = prog.counter + 1;
        
        } 

        else
        {
            cout << "Incorrect Parameter: " << parameter1 << " " << parameter2 << endl;
            outFile << "Incorrect Parameter: " << parameter1 << " " << parameter2 << endl;
            exit(EXIT_FAILURE);
        }  
}

void methodLOAD(string parameter1, string parameter2, Programme& prog, ofstream& outFile)
{
    if (parameter1[0] == 'R' && parameter2[0] == '[' && parameter2[1] == 'R' && parameter2[3] == ']')
    {
        int location1, location2;       //store index of register
        int address;                    //store address of memory
        int MEM;                        //store value in memory

        location1 = getNumber(parameter1);
        checkRegister(location1, outFile);
        location2 = getNumber(parameter2);
        checkRegister(location2, outFile);

        address = prog.reg[location2];
        checkMemory(address, outFile);
        MEM = prog.memory[address];

        prog.reg[location1] = MEM;
        prog.counter = prog.counter + 1;
    }
    else if (parameter1[0] == 'R' && parameter2[0] != 'R' && parameter2[0] != '[')
    {
        int location1;                  //store index of register
        int address;                    //store address of memory
        int value;                      //store value in address

        location1 = getNumber(parameter1);
        checkRegister(location1, outFile);
        address = getNumber(parameter2);
        checkMemory(address, outFile);

        value = prog.memory[address];
        prog.reg[location1] = value;

        prog.counter = prog.counter + 1;
    }
    else
    {
        cout << "Incorrect Parameter: " << parameter1 << " " << parameter2 << endl;
        outFile << "Incorrect Parameter: " << parameter1 << " " << parameter2 << endl;
        exit(EXIT_FAILURE);
    }
}

void methodSTORE(string parameter1, string parameter2, Programme& prog, ofstream& outFile)
{
    if (parameter1[0] == 'R' && parameter2[0] == '[' && parameter2[1] == 'R' && parameter2[3] == ']')
    {
        int location1, location2;       //store index of register
        int address;                    //store address of memory
        int value;                      //store value in register

        location1 = getNumber(parameter1);
        checkRegister(location1, outFile);
        location2 = getNumber(parameter2);
        checkRegister(location2, outFile);

        address = prog.reg[location2];
        checkMemory(address, outFile);
        value = prog.reg[location1];
        prog.memory[address] = value;

        prog.counter = prog.counter + 1;
    }
    else if (parameter1[0] == 'R' && parameter2[0] != 'R' && parameter2[0] != '[')
    {
        int location;       //store index of register
        int address;        //store address of memory

        location = getNumber(parameter1);
        checkRegister(location, outFile);
        address = getNumber(parameter2);
        checkMemory(address, outFile);

        prog.memory[address] = prog.reg[location];

        prog.counter = prog.counter + 1;
    }
    else
    {
        cout << "Incorrect Parameter: " << parameter1 << " " << parameter2 << endl;
        outFile << "Incorrect Parameter: " << parameter1 << " " << parameter2 << endl;
        exit(EXIT_FAILURE);
    }
}


//CHECKING FUNCTIONS

void checkInput(string parameter, ofstream& outFile)
{
    if (getNumber(parameter) > 255 || getNumber(parameter) < 0)
    {
        cout << "Number cannot be more than 255 or less than 0" << endl;
        outFile << "Number cannot be more than 255 or less than 0" << endl;
        exit(EXIT_FAILURE);
    }
}

void checkCommmand(string command, ofstream& outFile)
{
    if(command == "IN" || command == "OUT" || command == "INC" || command == "DEC")
    {
        cout << "Too many parameters" << endl;
        outFile << "Too many parameters" << endl;
        exit(EXIT_FAILURE);
    }
}

void checkRegister(int number, ofstream& outFile)
{
    if (number > 6)
    {
        cout << "Max register is 6" << endl;
        outFile << "Max register is 6" << endl;
        exit(EXIT_FAILURE);      
    }
}

void checkMemory(int number, ofstream& outFile)
{
    if (number > 63)
    {
        cout << "Max memory is 63" << endl;
        outFile << "Max memory is 63" << endl;
        exit(EXIT_FAILURE);      
    }
}

void checkFlag(int number, Programme& prog, ofstream& outFile)
{
    if (number > 255)
    {
        prog.overflow = true;
        prog.carry = true;
        display(prog, outFile);

        exit(EXIT_FAILURE);
    }
    else if (number < 0)
    {
        prog.underflow = true;
        display(prog, outFile);

        exit(EXIT_FAILURE);
        
    }
    else if (number == 0)
    {
        prog.zero = true;
    }
}