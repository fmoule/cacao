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
## - init-project
## - build-tests
## - tests
## - package
######

#### Tasks => clear
add_custom_target(clear)
add_dependencies(clear cacaocore-clear)

##### Tasks => init-project
add_custom_target(init-project COMMAND sudo apt-get install libgtest-dev)

#### Tasks => build-tests
add_custom_target(build-tests)
add_dependencies(build-tests cacaocore-build-tests)

#### Tasks => tests
add_custom_target(tests)
add_dependencies(tests cacaocore-tests)

#### Tasks => tests-mem
add_custom_target(tests-mem)
add_dependencies(tests-mem cacaocore-tests-mem)
