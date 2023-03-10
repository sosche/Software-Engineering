# Project: Rezeptbuch
# Aufruf make -f makefile.mak Parameter

CPP  = g++ 
CC   = gcc 

OBJ  = *.o  
LINKOBJ  = *.o  
INCS = -I. 
GTEST = ../googleTest
CXXINCS = 
BIN  = CocktailPro 
CXXFLAGS = $(CXXINCS)    
CFLAGS = $(INCS) -g -O0 -std=gnu++11
RM = rm -rf
COVERAGE = -fprofile-arcs -ftest-coverage -fPIC 

build: CocktailPro

clean: 
	g++ --version
	${RM} $(OBJ) $(BIN) *.gcno *.gcda CocktailProD/Docs/* cppcheck-results.xml CocktailProTest gtest.xml gcovr.xml reports/lcov* reports/CocktailPro.*.xml

cleanCoverage: 
	-lcov --zerocounters --directory .   

CocktailPro: 
	$(CPP) -o bin/CocktailPro main/main.cpp $(CFLAGS) -Wall *.cpp   

CocktailProPicky: 
	$(CPP) -o bin/CocktailPro main/main.cpp $(CFLAGS) -Wall -Wextra -pedantic -Wfloat-equal -Wundef -Wcast-align -Wwrite-strings -Wlogical-op -Wmissing-declarations -Wredundant-decls -Wshadow -Woverloaded-virtual *.cpp 
# -fsanitize=leak -llsan # performs memory checks at run time

Doku: 
	- doxygen config/CocktailProDoxy.cfg

Doxygen: 
	- doxygen config/CocktailProDoxy.cfg 2> reports/doxygen/DoxygenWarningLog.txt

build-tests: 
	$(CPP) $(COVERAGE) $(CFLAGS) -c *.cpp
	$(CPP) $(CFLAGS) -I$(GTEST)/include -c Test/*.cpp main/Main_TestAll.cpp
	$(CPP) $(COVERAGE) $(CFLAGS) -L$(GTEST) -o bin/CocktailProTest *.o -lgtest -lpthread 
# fuer Linker-Debugging: -Wl,--verbose

prepareTest2:
	- lcov --no-external --capture --initial --quiet --directory . --output-file reports/lcovbase.info

prepareTest:
	-lcov --zerocounters --directory .

test: 
	- ./bin/CocktailProTest --gtest_output="xml:./reports/gtest.xml"

Cppcheck:
	- cppcheck --suppress=missingIncludeSystem --xml --xml-version=2 --inline-suppr --enable=all --language=c++ --std=c++11 --quiet *.cpp main/main.cpp 2> reports/cppcheck-results.xml

convertCoverage:
	- lcov --capture --directory . --no-external --no-recursion --quiet --output-file reports/lcov1.info 
	- lcov --quiet --remove reports/lcov1.info '*.h' -o reports/lcov.info       
	- genhtml --quiet --function-coverage reports/lcov.info --output-directory reports

convertCoverage2:
#	- gcovr --xml-pretty --xml -r . --output=reports/gcovr.xml
#	- gcovr --exclude=".*_Test.*" -r . --html --html-details -o reports/Coverage.html
	- lcov --capture --directory . --no-external --no-recursion --rc lcov_branch_coverage=1 --quiet --output-file reports/lcovnew.info 
	- lcov --add-tracefile reports/lcovbase.info --add-tracefile --rc lcov_branch_coverage=1 reports/lcovnew.info --quiet --output-file reports/lcovcombined.info
	- lcov --rc lcov_branch_coverage=1 --quiet --remove reports/lcovcombined.info '*.h' -o reports/lcov.info
	- genhtml --quiet --function-coverage reports/lcov.info --output-directory reports
#	- genhtml --quiet --function-coverage --branch-coverage reports/lcov.info --output-directory reports
#	gcovr --verbose --branches --xml-pretty --exclude=".*_Test.*" -r . --output=reports/gcovr.xml
#	gcovr --object-directory=reports/gcovr --branches --xml-pretty --exclude="*_Test.*" -r . --output=reports/gcovr.xml

CCCC:
	- cccc --opt_infile=./config/cccc.opt --outdir=reports/cccc --report_mask=pPS *.cpp *.h > reports/cccc/cccc.txt 2>&1

publish:
	- /usr/local/bin/CopyBin2Tmp.sh
#   copies binaries to a folder that is accessible without root permission

GitStats:
	- gitstats . reports/gitstats >> reports/gitstats.txt

build: CocktailPro
	