add_subdirectory(gtest)

add_executable(zmij-test zmij-test.cc)
target_compile_features(zmij-test PRIVATE ${ZMIJ_STANDARD})
target_link_libraries(zmij-test gtest)
add_test(NAME zmij-test COMMAND zmij-test)

add_executable(zmij-no-int128-test zmij-test.cc)
target_compile_features(zmij-no-int128-test PRIVATE ${ZMIJ_STANDARD})
target_compile_definitions(zmij-no-int128-test PRIVATE ZMIJ_USE_INT128=0)
target_link_libraries(zmij-no-int128-test gtest)
add_test(NAME zmij-no-int128-test COMMAND zmij-no-int128-test)

add_executable(verify verify.cc dragonbox/dragonbox_to_chars.cpp)
target_include_directories(verify PRIVATE .)
target_link_libraries(verify zmij)
