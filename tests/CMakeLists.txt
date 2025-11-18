file(GLOB TEST_SRC
    test_kbest.cpp
)

# основной тест
add_executable(kbest_tests ${TEST_SRC})
target_link_libraries(kbest_tests kbest)
add_test(NAME kbest_tests COMMAND kbest_tests)

# ASan тест
add_executable(kbest_asan_test test_asan.cpp)
target_link_libraries(kbest_asan_test kbest)
add_test(NAME kbest_asan_test COMMAND kbest_asan_test)
