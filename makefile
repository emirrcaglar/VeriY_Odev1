# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = bin
LIB_DIR = lib

# Source files
SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/BagliListe.cpp $(SRC_DIR)/Dugum.cpp $(SRC_DIR)/Fonksiyonlar.cpp
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(LIB_DIR)/%.o,$(SOURCES))

# Header files
HEADERS = $(INCLUDE_DIR)/BagliListe.hpp $(INCLUDE_DIR)/Dugum.hpp $(INCLUDE_DIR)/Fonksiyonlar.hpp

# Executable name
EXECUTABLE = $(BIN_DIR)/program

# Default target
all: directories $(EXECUTABLE)

# Create necessary directories
directories: $(BIN_DIR) $(LIB_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

# Link the program
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXECUTABLE)

# Compile source files
$(LIB_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Clean built files
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
	rm -rf $(BIN_DIR) $(LIB_DIR)

# Run the program
run: $(EXECUTABLE)
	./$(EXECUTABLE)

.PHONY: all clean run directories