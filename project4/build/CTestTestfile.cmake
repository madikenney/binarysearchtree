# CMake generated Testfile for 
# Source directory: /Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4
# Build directory: /Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Pathfinder:test-queue "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/build/test-queue")
set_tests_properties(Pathfinder:test-queue PROPERTIES  _BACKTRACE_TRIPLES "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/CMakeLists.txt;39;add_test;/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/CMakeLists.txt;0;")
add_test(SETUP:test00 "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/build/pathfinder" "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/tests/maze00.png" "output00.png")
set_tests_properties(SETUP:test00 PROPERTIES  FIXTURES_SETUP "TEST0" TIMEOUT "300" _BACKTRACE_TRIPLES "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/CMakeLists.txt;41;add_test;/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/CMakeLists.txt;0;")
add_test(Pathfinder:test00-compare "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/build/compare" "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/tests/output00.png" "output00.png")
set_tests_properties(Pathfinder:test00-compare PROPERTIES  FIXTURES_REQUIRED "TEST0" RUN_SERIAL "TRUE" _BACKTRACE_TRIPLES "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/CMakeLists.txt;42;add_test;/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/CMakeLists.txt;0;")
add_test(SETUP:test01 "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/build/pathfinder" "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/tests/maze01.png" "output01.png")
set_tests_properties(SETUP:test01 PROPERTIES  FIXTURES_SETUP "TEST1" TIMEOUT "300" _BACKTRACE_TRIPLES "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/CMakeLists.txt;46;add_test;/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/CMakeLists.txt;0;")
add_test(Pathfinder:test01-compare "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/build/compare" "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/tests/output01.png" "output01.png")
set_tests_properties(Pathfinder:test01-compare PROPERTIES  FIXTURES_REQUIRED "TEST1" RUN_SERIAL "TRUE" _BACKTRACE_TRIPLES "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/CMakeLists.txt;47;add_test;/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/CMakeLists.txt;0;")
add_test(SETUP:test02 "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/build/pathfinder" "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/tests/maze02.png" "output02.png")
set_tests_properties(SETUP:test02 PROPERTIES  FIXTURES_SETUP "TEST2" TIMEOUT "300" _BACKTRACE_TRIPLES "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/CMakeLists.txt;51;add_test;/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/CMakeLists.txt;0;")
add_test(Pathfinder:test02-compare "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/build/compare" "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/tests/output02.png" "output02.png")
set_tests_properties(Pathfinder:test02-compare PROPERTIES  FIXTURES_REQUIRED "TEST2" RUN_SERIAL "TRUE" _BACKTRACE_TRIPLES "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/CMakeLists.txt;52;add_test;/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/CMakeLists.txt;0;")
add_test(SETUP:test03 "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/build/pathfinder" "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/tests/maze03.png" "output03.png")
set_tests_properties(SETUP:test03 PROPERTIES  FIXTURES_SETUP "TEST3" TIMEOUT "300" _BACKTRACE_TRIPLES "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/CMakeLists.txt;56;add_test;/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/CMakeLists.txt;0;")
add_test(Pathfinder:test03-compare "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/build/compare" "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/tests/output03.png" "output03.png")
set_tests_properties(Pathfinder:test03-compare PROPERTIES  FIXTURES_REQUIRED "TEST3" RUN_SERIAL "TRUE" _BACKTRACE_TRIPLES "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/CMakeLists.txt;57;add_test;/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/CMakeLists.txt;0;")
add_test(Pathfinder:test-invalid1 "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/build/pathfinder" "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/tests/maze00_extra_color.png" "output00_extra_color.png")
set_tests_properties(Pathfinder:test-invalid1 PROPERTIES  WILL_FAIL "TRUE" _BACKTRACE_TRIPLES "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/CMakeLists.txt;61;add_test;/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/CMakeLists.txt;0;")
add_test(Pathfinder:test-invalid2 "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/build/pathfinder" "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/tests/maze00_extra_start.png" "output00_extra_start.png")
set_tests_properties(Pathfinder:test-invalid2 PROPERTIES  WILL_FAIL "TRUE" _BACKTRACE_TRIPLES "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/CMakeLists.txt;62;add_test;/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/CMakeLists.txt;0;")
add_test(Pathfinder:test-invalid3 "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/build/pathfinder" "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/tests/maze00_no_start.png" "output00_no_start.png")
set_tests_properties(Pathfinder:test-invalid3 PROPERTIES  WILL_FAIL "TRUE" _BACKTRACE_TRIPLES "/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/CMakeLists.txt;63;add_test;/Users/Macbook151/Desktop/ECE 0302/ECE0302-MBK81/project4/CMakeLists.txt;0;")
subdirs("lib")
