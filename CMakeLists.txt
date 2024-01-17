cmake_minimum_required(VERSION 3.18.0)
project(test-znver4)

find_package(LLVM REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LLVM_CXX_FLAGS} -std=c++17 -fvisibility-inlines-hidden")

add_executable(test-znver4 test-znver4.cpp)
target_include_directories(test-znver4 PRIVATE ${LLVM_INCLUDE_DIRS})
target_compile_definitions(test-znver4 PRIVATE ${LLVM_DEFINITIONS})
llvm_map_components_to_libnames(TEST_ZNVER4_LLVM_LIBS
  Support TargetParser ExecutionEngine AllTargetsDescs AllTargetsInfos AllTargetsCodeGens AllTargetsAsmParsers)
target_link_libraries(test-znver4 ${TEST_ZNVER4_LLVM_LIBS})

install(TARGETS test-znver4)

