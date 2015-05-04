cmake_minimum_required(VERSION 3.2.2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")

# Add pthreads
set(CMAKE_THREAD_PREFER_PTHREAD ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads)

# Add Boost libraries
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(Boost_USE_STATIC_LIBS OFF)

# Don't forget to set BOOST_ROOT as a cache entry!

find_package(Boost 1.57 COMPONENTS system log thread)

add_subdirectory(src)

