# Trivial ISS

Implementation of an Instruction Set Simulator for a trivial Instruction Set Architecture given below using C.

<br>

![Trivial ISA](https://github.com/Dybios/trivial_iss/blob/main/images/trivial_isa.png?raw=true)

<br>

Current code.bin file in bin/ contains the code for adding 10 numbers. As per the source requirements, code.bin is made to be 1024 bytes and data.bin is made to be 256 bytes initialized to 0xFF.

To compile, just run:

    $ make all
    
To run the program, use the following command.

    $ ./cpurun.o
