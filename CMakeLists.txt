cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project(SnakeGame)

set(SOURCE_EXE SnakeGame.cpp)

add_executable(SnakeGame ${SOURCE_EXE})

set(SOURCE_LIB Sleep.cpp Input.cpp OS.hpp KeyCodes.hpp GameField.hpp GameField.cpp)

add_library(Lib STATIC ${SOURCE_LIB})

target_link_libraries(SnakeGame Lib)	
