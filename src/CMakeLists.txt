
cmake_minimum_required(VERSION 2.8)              
PROJECT(doughControl)                                   
FIND_PACKAGE( OpenCV REQUIRED )  
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

INCLUDE_DIRECTORIES( ${OpenCV_INCLUDE_DIRS} )
INCLUDE_DIRECTORIES(src)

ADD_EXECUTABLE(breadMake main.cpp ./components/display.cpp ./components/tempMeasure.c ./components/checkGrowth.cpp)                          
TARGET_LINK_LIBRARIES (breadMake ${OpenCV_LIBS} Threads::Threads) 
                   
