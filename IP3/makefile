CC = g++
CFLAGS = -Wall -Wextra -std=c++11
COMMON_SOURCES = RentalPricer.cpp CarRental.cpp HouseRental.cpp RentalService.cpp

all: demo test
demo: demo.cpp $(COMMON_SOURCES) RentalSystem.h
	$(CC) $(CFLAGS) -o demo.exe demo.cpp $(COMMON_SOURCES)

test: test.cpp $(COMMON_SOURCES) RentalSystem.h
	$(CC) $(CFLAGS) -o test.exe test.cpp $(COMMON_SOURCES)


clean:
	del /F /Q demo.exe test.exe

.PHONY: all demo test clean
