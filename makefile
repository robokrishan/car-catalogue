# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2

# Target executable name
TARGET = car_app

# Source and header files
SRCS = main.cpp car/car.cpp doubly_linked_list/doubly_linked_list.cpp engine/engine.cpp linked_list/linked_list.cpp parser/parser.cpp
HEADERS = car/car.h doubly_linked_list/doubly_linked_list.h engine/engine.h linked_list/linked_list.h parser/parser.h

# Object files (automatically generated from source files)
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Linking step
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compilation step for each .cpp file to .o
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)
