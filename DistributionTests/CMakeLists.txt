
cmake_minimum_required (VERSION 3.8)

add_definitions(-D_SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING)

project ("Test")

add_executable (Test  "main.cpp" "Test.h" "UniformTest.h" "NormalTest.h")

target_include_directories(Test PUBLIC "C:\\Level_4_Rian_Olson\\C++\\nana\\include")
target_link_libraries(Test "nana_v143_Debug_x64")
target_link_directories(Test PUBLIC "C:\\Level_4_Rian_Olson\\C++\\nana\\build\\bin")



# TODO: Add tests and install targets if needed.
