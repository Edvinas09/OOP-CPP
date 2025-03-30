# Compiler and flags
CXX = g++

# Targets
TARGET = program.exe
TEST_TARGET = test.exe
MAIN_OBJ = main.o
TEST_OBJ = test.o
HASH_OBJ = HashTable.o

# Default target
run: $(TARGET)
	./$(TARGET) > main.txt

# Build the main program
$(TARGET): $(MAIN_OBJ) $(HASH_OBJ)
	$(CXX) -o $(TARGET) $(MAIN_OBJ) $(HASH_OBJ)

# Build the test program
$(TEST_TARGET): $(TEST_OBJ) $(HASH_OBJ)
	$(CXX) -o $(TEST_TARGET) $(TEST_OBJ) $(HASH_OBJ)

# Compile main.cpp
$(MAIN_OBJ): main.cpp HashTable.h
	$(CXX) -c main.cpp -o $(MAIN_OBJ)

# Compile test.cpp
$(TEST_OBJ): test.cpp HashTable.h
	$(CXX) -c test.cpp -o $(TEST_OBJ)

# Compile HashTable.cpp
$(HASH_OBJ): HashTable.cpp HashTable.h
	$(CXX) -c HashTable.cpp -o $(HASH_OBJ)

# Clean build files
clean:
	del /q *.o *.exe main.txt

# Rebuild everything
rebuild: clean all