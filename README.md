# Basic login system with C++

I was made this because idk i was bored.

It saves the login information with binary code.

You can edit the converter if u want. 

The converter is [Here](https://github.com/Mal1koRe1ss/CPP_Login/blob/main/source/Converter.cpp).

DataManager saves the data to a .data file.

LoginManager only performs the tasks of Register and Login operations.

## Requirements

**G++**

<br>

## MinGW(Windows 10) Installation and Compiling 

[Download MinGW from here](https://www.msys2.org/) and install it.

Type ```$ pacman -S mingw-w64-ucrt-x86_64-gcc``` in MSYS2 UCRT64.

When **:: Proceed with installation? [Y/n]** text comes press Y.

After the msys2 Installation you can check G++ with ```g++ --version``` in CMD or you can go to **"C:\msys64\ucrt64\bin"** this directory.

If you done everything correct you should be able to have g++ in your system.

## Compile The Project

Clone the project:
  <br>Open a terminal and type the command below. Or directly download with **<> Code** button.
   ```bash
   git clone https://github.com/Mal1koRe1ss/CPP_Login.git
   ```
**Make sure that the files are extracted and they are in the same location in this repository.**

Go to the directory where **Source code** is located.

Open a terminal and use cd to change the location to the directory where **Source code** is located.

Compile the project: 
<br>Open a terminal and use the command below
  ```bash
  g++ main.cpp source/DataManager.cpp source/LoginManager.cpp source/Converter.cpp -o CPPLogin icon.o
  ```
Now you are ready to go.

You can use the software with opening the **CPPLogin.exe** executable file.
