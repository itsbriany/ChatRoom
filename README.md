# ChatRoom

####ABOUT

The plan is to build a multi chatroom that acts as a service where clients can connect from anywhere.
Eventually, encryption will also be added.





####DEFINITIONS

%ROOTDIR% => Project root directory








####RECOMMENDED

Install Boost 1.57.0 C++ libraries

You can install the libraries with the install script %ROOTDIR%/libs/buildLibs.sh

This is recommended because you may want to use a boost library that has not yet been
included in the project. If you do not have Boost 1.57.0 C++ libraries installed, then
you should still be able to make the build as long as your LD_LIBRARY_PATH environment
variable is properly configured. See INSTALLATION for more details on setting up boost
or refer to the boost documentation: 

http://www.boost.org/doc/libs/1_57_0/more/getting_started/unix-variants.html











####INSTALLATION

This project uses Boost 1.57.0 C++ libraries.
Therefore, your LD_LIBRARY_PATH environment variable should include the following path:
%PROJECTDIRECTORY%/libs

It is also highly recommended to update your compiler build path
















####THIRD PARTY

Boost C++ libraries
Google C/C++ Unit Testing Framework
















####SOFTWARE VERSIONS

This project was compiled with g++ 4.8.2 
The supported C++ version is C++14
