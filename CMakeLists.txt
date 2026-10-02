# CMakeList.txt : CMake project for postgresORM, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.10)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("postgresORM")

# Add source to this project's executable.
add_executable (postgresORM 
main.cpp 
main.h
connection.cpp
connection.h
addData.cpp
addData.h
)

target_include_directories(postgresORM PRIVATE
    "C:/Program Files/Wt 4.14.3 msvs2017 x64/include"
)

target_link_directories(postgresORM PRIVATE
    "C:/Program Files/Wt 4.14.3 msvs2017 x64/lib"
)

target_link_libraries(postgresORM PRIVATE
    debug wtdbod
    optimized wtdbo

    debug wtdbopostgresd
    optimized wtdbopostgres
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET postgresORM PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
