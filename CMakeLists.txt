cmake_minimum_required(VERSION 3.12)
project(kbest LANGUAGES CXX)
option(KBEST_USE_ASAN "Build with AddressSanitizer" ON)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE OFF)

include(cmake/ConfigCompiler.cmake)

if (KBEST_USE_ASAN)
    message(STATUS "AddressSanitizer enabled")
    set(ASAN_FLAGS "-fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ASAN_FLAGS}")
    set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} ${ASAN_FLAGS}")

    # Это критично для ASan!
    set(CMAKE_POSITION_INDEPENDENT_CODE OFF)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -no-pie")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -no-pie")
endif()


# header-only библиотека
add_library(kbest INTERFACE)
target_include_directories(kbest INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# подключаем подпроекты
add_subdirectory(examples)
enable_testing()
add_subdirectory(tests)
