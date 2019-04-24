cmake_minimum_required(VERSION 3.9)
set(NAME M_DGW_5)
project(${NAME})

set(CMAKE_CXX_STANDARD 11)

#set(CMAKE_PREFIX_PATH /home/idalov/geant4/geant4-install)
set(CMAKE_PREFIX_PATH /home/user/geant4/geant4-install)

find_package(Geant4 REQUIRED ui_all vis_all)

include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)


file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

add_executable(${NAME} main.cpp ${sources} ${headers} include/Command.hh src/Command.cc)
target_link_libraries(${NAME} ${Geant4_LIBRARIES})

set(M_SCRIPTS
        init_vis.mac
        vis.mac
        run.mac
        )

foreach(_script ${M_SCRIPTS})
    configure_file(
            ${PROJECT_SOURCE_DIR}/${_script}
            ${PROJECT_BINARY_DIR}/${_script}
            COPYONLY
    )
endforeach()


install(TARGETS ${NAME} DESTINATION bin)