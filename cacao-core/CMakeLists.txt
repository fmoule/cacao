cmake_minimum_required(VERSION 3.5)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

##########################
##### Définition du module
##########################

project(cacao-core)
enable_language(CXX)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/target/bin)
set(PROJECT_BINARY_DIR ${PROJECT_SOURCE_DIR}/target/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/target/lib)

## Définition des entêtes
set(INC_DIR include/main)
set(INC_TEST_DIR include/test)
file(GLOB_RECURSE INC_FILES ${INC_DIR}/*.h)
file(GLOB_RECURSE INC_TEST_FILES ${INC_TEST_DIR}/*.h)
include_directories(AFTER ${INC_DIR} ${INC_TEST_DIR})

## Définition des fichiers sources
set(SRC_DIR src/main)
set(SRC_TEST_DIR src/test)
file(GLOB_RECURSE SRC_FILES ${SRC_DIR}/*.cpp)
file(GLOB_RECURSE SRC_TEST_FILES ${SRC_TEST_DIR}/*.cpp)

######
## Définition des tâches
######

#### Target => clear
add_custom_target(cacaocore-clear COMMAND echo '=== Nettoyage du projet')
if (EXISTS ${EXECUTABLE_OUTPUT_PATH})
    add_custom_command(TARGET cacaocore-clear COMMAND rm -rf ${EXECUTABLE_OUTPUT_PATH}/*)
endif ()
if (EXISTS ${LIBRARY_OUTPUT_PATH})
    add_custom_command(TARGET cacaocore-clear COMMAND rm -rf ${LIBRARY_OUTPUT_PATH}/*)
endif ()

#### target => cacaocore-prepare
add_custom_target(cacaocore-prepare COMMAND mkdir -p ${EXECUTABLE_OUTPUT_PATH})
add_dependencies(cacaocore-prepare cacaocore-clear)
add_custom_command(TARGET cacaocore-prepare POST_BUILD COMMAND mkdir -p ${LIBRARY_OUTPUT_PATH})

#### Tâche principale : target => cacaocore
add_library(cacaocore SHARED ${SRC_FILES})
add_dependencies(cacaocore cacaocore-prepare)

#### Test

## target => cacaocore-build-test
add_executable(cacaocore-build-tests ${SRC_FILES} ${SRC_TEST_FILES})
add_dependencies(cacaocore-build-tests cacaocore)
target_include_directories(cacaocore-build-tests PUBLIC /usr/include/cppunit)
target_link_libraries(cacaocore-build-tests PUBLIC /usr/lib/x86_64-linux-gnu/libcppunit.so)

## target => cacaocore-test
add_custom_target(cacaocore-tests COMMAND ${EXECUTABLE_OUTPUT_PATH}/cacaocore-build-tests)
add_dependencies(cacaocore-tests cacaocore-build-tests)

## target => cacaocore-tests-mem
add_custom_target(cacaocore-tests-mem COMMAND valgrind --leak-check=full ${EXECUTABLE_OUTPUT_PATH}/cacaocore-build-tests)
add_dependencies(cacaocore-tests-mem cacaocore-build-tests)
