add_subdirectory(gtest)

function(add_zmij_test name)
    add_executable(${name} zmij-test.cc)
    target_compile_features(${name} PRIVATE ${ZMIJ_STANDARD})
    target_link_libraries(${name} gtest)
    add_test(NAME ${name} COMMAND ${name})
endfunction()

add_zmij_test(zmij-test)

add_zmij_test(zmij-no-int128-test)
target_compile_definitions(zmij-no-int128-test PRIVATE ZMIJ_USE_INT128=0)

add_zmij_test(zmij-no-simd-test)
target_compile_definitions(zmij-no-simd-test PRIVATE ZMIJ_USE_SIMD=0)

add_executable(verify verify.cc dragonbox/dragonbox_to_chars.cpp)
target_include_directories(verify PRIVATE .)
target_link_libraries(verify zmij)

add_executable(verify-double verify-double.cc)
target_include_directories(verify-double PRIVATE .)
