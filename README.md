# simple_arm_simulator
Simple ARM Simulator Using C++ with registers. flags, and memory. Controlled using .asm file.

There should be 5 files inside the folder:
a. Commands.asm (Instruction File)
b. function.h (Header File)
c. Functions.cpp (Function Definition Source Code File)
d. Main.cpp (Main Source Code File)
e. output.txt (Output File)

Make sure you have a C++ Compiler, I use MSYS2: https://code.visualstudio.com/docs/cpp/config-mingw

Compile the file using the following command:
g++ main.cpp functions.cpp -o samplerun.exe

Run the samplerun.exe file using the following command:
.\samplerun.exe

COMMANDS
IMPORTANT NOTE:
The interpreter will rely on the comma after the first parameter in the assembly programme to
determine whether the assembly programme has a second parameter. Hence, make sure the
comma is present after the first parameter if a second parameter is present.
The interpreter only reads caps characters from the assembly program. Any small characters
will result in the Incorrect Command error.

The correct syntax should be: MOV R1, R2
Example of incorrect syntax: Mov R1 R2 (no comma and has small letters)

1) Move Operations (MOV)

Syntax: MOV value, Rdst
Operation: places value into the destination register, Rdst.

Syntax: MOV Rsrc, Rdst
Operation: copies the value in source register, Rsrc into the destination register, Rdst.

Syntax: MOV [Rsrc], Rdst
Operation: Rsrc contains the memory address. The interpreter will copy the value with the
address stored in Rsrc to Rdst. The square brackets [] indicates that the value in Rsrc is an
address.

2)  Mathematical Operations (ADD, SUB, MUL, DIV, INC, DEC)

ADD Method
Syntax: ADD Rsrc, Rdst
Operation: The interpreter will add the value in the source Register (Rsrc) with the value in the
destination Register (Rdst) and store the sum value in the destination Register (Rdst).

SUB Method
Syntax: SUB Rsrc, Rdst
Operation: The interpreter will subtract the value in the source Register (Rsrc) with the value in
the destination Register (Rdst) and store the result value in the destination Register (Rdst).

MUL Method
Syntax: MUL Rsrc, Rdst
Operation: The interpreter will multiply the value in the source Register (Rsrc) with the value in
the destination Register (Rdst) and store the result value in the destination Register (Rdst).

DIV Method
Syntax: DIV Rsrc, Rdst
Operation: The interpreter will divide the value in the source Register (Rsrc) with the value in the
destination Register (Rdst) and store the result value in the destination Register (Rdst). If the
Rdst is 0, an error is displayed and the interpreter ends.

INC Method
Syntax: INC Rdst
Operation: The interpreter will add 1 to the value stored in Rdst.

DEC Method
Syntax: DEC Rdst
Operation: The interpreter will subtract 1 from the value stored in Rdst

3)  Rotation and Shifting Operations (ROL, ROR, SHL, SHR)

ROL Method
Syntax: ROL Rsrc, count
Operation: The interpreter will rotate the binary of the value in source Register (Rsrc) to the left
by ‘count’ positions. The first number of the binary will wrap around the binary to the last
position of the binary. The 8-bit binary before and after rotating are also displayed.

ROR Method
Syntax: ROR Rsrc, count
Operation: The interpreter will rotate the binary of the value in source Register (Rsrc) to the right
by ‘count’ positions. The last number of the binary will wrap around the binary to the first
position of the binary. The 8-bit binary before and after rotating are also displayed.

SHL Method
Syntax: SHL Rsrc, count
Operation: The interpreter will shift the binary of the value in source Register (Rsrc) to the left by
‘count’ positions. The end position of the binary will be replaced with ‘0’. The 8-bit binary before
and after shifting are also displayed.

SHR Method
Syntax: SHR Rsrc, count
Operation: The interpreter will shift the binary of the value in source Register (Rsrc) to the right
by ‘count’ positions. The first position of the binary will be replaced with ‘0’. The 8-bit binary
before and after shifting are also displayed.

4) Basic I/O Operations
   
IN Method
Syntax: IN Rdst
Operation: The interpreter will ask the user to input a value and it will be stored into the
destination Register (Rdst).

OUT Method
Syntax: OUT Rsrc
Operation: The interpreter will return the value stored in the source Register (Rsrc).

5) Loading Data from Memory (LOAD)

LOAD Method
Syntax: LOAD Rdst, addr
Operation: Load the value at memory address 'addr' into Rdst.

Syntax: LOAD Rdst, [Raddr]
Operation: Load the value at the memory address stored in register Raddr into Rdst.

6) Storing Data to Memory (STORE)
   
STORE Method
Syntax: STORE Rsrc, addr
Operation: Store the value in Rsrc into memory address 'addr'.

Syntax: STORE Rsrc, [Raddr]
Operation: Store the value in Rsrc into a memory address stored in register Raddr.
