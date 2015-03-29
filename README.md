# ChatRoom

####About

The plan is to build a multi chatroom that acts as a service where clients can connect from anywhere.
Eventually, encryption will also be added.





####Definitions

* %ROOTDIR% => Project root directory








####Installation

* This project uses Boost 1.57.0 C++ libraries.

* If you are doing a system install of boost, then it is recommended that your LD_LIBRARY_PATH environment variable should include the path to your boost shared objects directory. 

* **Make sure to modify the %ROOTDIR%/src/env.mk file so that your copmiler can find the boost source code and the linker can link to the boost shared objects!**

* If you are having any trouble with installing boost, there is some documentation here:
http://www.boost.org/doc/libs/1_57_0/more/getting_started/unix-variants.html

* This project uses C++14 features so make sure you have an up to date compiler (g++ 4.9.1+ recommended).















####Third Party

* Boost C++ libraries
*Google C/C++ Unit Testing Framework






####Software Versions

* This project is compiled with g++ 4.9.1+ 
* The supported C++ version is C++14
