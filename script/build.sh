cd ../build
rm -rf *

cmake ../

# CPPCheck

# cppcheck ../src --enable=all --xml-version=2 2>cppcheck_report.xml
# cppcheck-htmlreport --file=cppcheck_report.xml --report-dir=cppcheck_report
# open cppcheck_report/index.html

make
./test/test_stack

# lcov

# lcov -d . -c -o test_stack.info --exclude '/usr/local/*'
# genhtml test_stack.info -o lcov_result
# open lcov_result/index.html