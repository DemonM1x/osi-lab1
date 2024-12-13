get_filename_component(MONOLITH_INCLUDE_PATH "." ABSOLUTE)
get_filename_component(MONOLITH_SOURCE_PATH "./${PROJECT_NAME}" ABSOLUTE)
include_directories("C:/Libraries/phnt")
file(GLOB_RECURSE MONOLITH_SOURCES CONFIGURE_DEPENDS *.hpp *.cpp)

set(MONOLITH_LIB_SOURCES ${MONOLITH_SOURCES}
        monolith/console/Console.cpp
        monolith/console/Console.hpp
        monolith/console/Command.cpp
        monolith/console/Command.hpp
        monolith/commands/Exit.cpp
        monolith/commands/Exit.hpp
        monolith/commands/Help.cpp
        monolith/commands/Help.hpp
        monolith/console/CommandFactory.cpp
        monolith/console/CommandFactory.hpp
        monolith/commands/History.cpp
        monolith/commands/History.hpp
        monolith/commands/Ls.cpp
        monolith/commands/Ls.hpp
        monolith/commands/Cat.cpp
        monolith/commands/Cat.hpp
        monolith/commands/Cd.cpp
        monolith/commands/Cd.hpp
        monolith/commands/Mkdir.cpp
        monolith/commands/Mkdir.hpp
        monolith/commands/Rm.cpp
        monolith/commands/Rm.hpp
        monolith/bench/CreateProcessHelper.cpp
        monolith/bench/CreateProcessHelper.hpp
        monolith/app/Shell.cpp
        monolith/app/Shell.hpp
        monolith/bench/EmaSortInt.cpp
        monolith/bench/EmaSortInt.hpp
        monolith/bench/EmaSortIntProcess.cpp
        monolith/bench/EmaSortIntProcess.hpp
        monolith/bench/Dedup.hpp
        monolith/bench/Dedup.cpp
)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(MONOLITH_APP_SOURCES monolith/app/Main.cpp)
add_executable(Shell
        monolith/app/Shell.cpp
        monolith/app/Shell.hpp
        monolith/bench/CreateProcessHelper.cpp)

add_executable(monolithOpt ${MONOLITH_APP_SOURCES})
target_link_libraries(
        monolithOpt PRIVATE
        ${PROJECT_NAME}
)
target_compile_options(monolithOpt PRIVATE -march=native -ffast-math -funroll-loops)


add_library(${PROJECT_NAME} STATIC ${MONOLITH_LIB_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${MONOLITH_INCLUDE_PATH})

add_executable(${PROJECT_NAME}-app ${MONOLITH_APP_SOURCES})
set_property(TARGET ${PROJECT_NAME}-app PROPERTY OUTPUT_NAME ${PROJECT_NAME})
target_link_libraries(
    ${PROJECT_NAME}-app PRIVATE
    ${PROJECT_NAME}
)
