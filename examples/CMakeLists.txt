add_executable(build_index build_index.cpp)
target_link_libraries(build_index kbest)

add_executable(search_example search_example.cpp)
target_link_libraries(search_example kbest)
