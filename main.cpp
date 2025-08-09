/*VIRTUAL MACHINE ASSIGNMENT
GROUP 19
NIK AMEER FAIQ BIN NIK MUHD ASLAN (1231302098) TT2L
TUAN MUZFIR KHALIS BIN TUAN MOHD RAFIZAM (1231301604) TT2L 
TAREQ AZHAD BIN SHARIFF (1231302857) TT1L
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "function.h"
using namespace std;


//COMPONENTS
string untrimmedCommand, untrimmedParameter1, untrimmedParameter2;  //raw contents from file
string command, parameter1, parameter2;                             //trimmmed contents
Programme programme;                                                //programme contents


int main()
{
    ifstream myFile;                            //declare myFile
    myFile.open("commands.asm");                //connect
    ofstream outFile;                           //declare outFile
    outFile.open("output.txt");                 //connect

    //DISPLAY
    cout << "STEP 0";
    outFile << "STEP 0";
    display(programme, outFile);

    //GET INPUT FROM FILE

    while(myFile >> untrimmedCommand >> untrimmedParameter1)
    {
        command = trim(untrimmedCommand);
        parameter1 = trim(untrimmedParameter1);

        //CHECKING INPUT
        checkInput(parameter1, outFile);
        
        cout << "STEP " << programme.counter + 1 << endl;
        outFile << "STEP " << programme.counter + 1 << endl;
        cout << "COM : " << command << endl;
        outFile << "COM :" << command << endl;
        cout << "PAR1: " << parameter1 << endl;
        outFile << "PAR1: " << parameter1 << endl;

        int lastLetter = untrimmedParameter1.length() - 1;

        if (untrimmedParameter1[lastLetter] == ',')
        {
            myFile >> untrimmedParameter2;
            parameter2 = trim(untrimmedParameter2);

            //CHECKING INPUT
            checkInput(parameter2, outFile);
            cout << "PAR2: " << parameter2 << endl;
            outFile << "PAR2:" << parameter2 << endl;

            checkCommmand(command, outFile);
        }
        

        //METHODS
        if (command == "IN")
        {
            methodIN(parameter1, programme, outFile);
        }

        else if (command == "OUT")
        {
            methodOUT(parameter1, programme, outFile);
        }

        else if (command == "MOV")
        {
            methodMOV(parameter1, parameter2, programme, outFile);
        }

        else if (command == "ADD")
        {
            methodADD(parameter1, parameter2, programme, outFile);
        }

        else if (command == "SUB")
        {
            methodSUB(parameter1, parameter2, programme, outFile);
        }

        else if (command == "MUL")
        {
            methodMUL(parameter1, parameter2, programme, outFile);
        }

        else if (command == "DIV")
        {
            methodDIV(parameter1, parameter2, programme, outFile);
        }

        else if (command == "INC")
        {
            methodINC(parameter1, programme, outFile);
        }
        else if (command == "DEC")
        {
            methodDEC(parameter1, programme, outFile);
        }
        else if (command == "ROL")
        {
            methodROL(parameter1, parameter2, programme, outFile);
        }
        else if (command == "ROR")
        {
            methodROR(parameter1, parameter2, programme, outFile);
        }
        else if (command == "SHL")
        {
            methodSHL(parameter1, parameter2, programme, outFile);
        }
        else if (command == "SHR")
        {
            methodSHR(parameter1, parameter2, programme, outFile);
        }
        else if (command == "LOAD")
        {
            methodLOAD(parameter1, parameter2, programme, outFile);
        }
        else if (command == "STORE")
        {
            methodSTORE(parameter1, parameter2, programme, outFile);
        }
        else
        {
            cout << "Incorrect Command: " << command << endl;
            outFile << "Incorrect Command: " << command << endl;
            return -1;
        }

        display(programme, outFile);
    }

    myFile.close();
    outFile.close();
}