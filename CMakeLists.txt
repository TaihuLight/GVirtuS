cmake_minimum_required(VERSION 3.2)

project(gvirtus)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

find_package(Log4Cplus REQUIRED)

include_directories(${LOG4CPLUS_INCLUDE_DIRS})

add_library(util
        src/util/Buffer.cpp
        src/util/Buffer.h
        src/util/Communicator.cpp
        src/util/Communicator.h
        src/util/ConfigFile.cpp
        src/util/ConfigFile.h
        src/util/Decoder.cpp
        src/util/Decoder.h
        src/util/Encoder.cpp
        src/util/Encoder.h
        src/util/gvirtus-type.h
        src/util/MessageDispatcher.cpp
        src/util/MessageDispatcher.h
        src/util/Mutex.cpp
        src/util/Mutex.h
        src/util/Observable.cpp
        src/util/Observable.h
        src/util/Observer.cpp
        src/util/Observer.h
        src/util/Result.cpp
        src/util/Result.h
        src/util/Subprocess.cpp
        src/util/Subprocess.h
        src/util/Thread.cpp
        src/util/Thread.h
        src/util/Util.cpp
        src/util/Util.h)
target_link_libraries(util ${LOG4CPLUS_LIBRARIES})
