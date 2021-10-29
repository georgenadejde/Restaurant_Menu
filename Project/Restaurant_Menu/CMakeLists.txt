cmake_minimum_required(VERSION 3.17)
project(ProiectLab13_14)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProiectLab13_14 main.cpp ReadFromFileException.h RepoException.h Repository/RepoFile.cpp Repository/RepoFile.h  ValidationException.h Domain/Preparat.cpp Domain/Preparat.h Domain/FelulPrincipal.cpp Domain/FelulPrincipal.h Domain/FelulSecundar.cpp Domain/FelulSecundar.h Domain/Desert.cpp Domain/Desert.h Teste/Tests.cpp Teste/Tests.h Repository/Repository.h Repository/Repository.cpp Service/Service.cpp Service/Service.h UI/UI.cpp UI/UI.h Domain/ValidatorPreparat.cpp Domain/ValidatorPreparat.h Domain/ValidatorFelulPrincipal.cpp Domain/ValidatorFelulPrincipal.h Domain/ValidatorFelulSecundar.cpp Domain/ValidatorFelulSecundar.h Domain/ValidatorDesert.cpp Domain/ValidatorDesert.h)