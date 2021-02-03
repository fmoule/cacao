cmake_minimum_required(VERSION 3.5)

#########################
#### Définition du projet
#########################

### Définition des propriétés du projet
project(cacao)
enable_language(CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -O -pedantic -ansi -std=gnu++17")

### Liste des modules
add_subdirectory(cacao-core)

######
## Définition des tâches
## - clear
## - build-tests
## - tests
## - package
######

#### Target => clear
add_custom_target(clear)
add_dependencies(clear cacaocore-clear)

#### Target => build-tests
add_custom_target(build-tests)
add_dependencies(build-tests cacaocore-build-tests)

#### Target => tests
add_custom_target(tests)
add_dependencies(tests cacaocore-tests)

#### Target => tests-mem
add_custom_target(tests-mem)
add_dependencies(tests-mem cacaocore-tests-mem)
