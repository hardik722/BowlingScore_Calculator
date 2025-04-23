# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wextra -I./src

# Directories
SRC_DIR := src
TEST_DIR := test
BUILD_DIR := build
BIN_DIR := bin

# Output files
MAIN_OBJ := $(BUILD_DIR)/main.o
GAME_OBJ := $(BUILD_DIR)/Bowling_game.o
TEST_OBJ := $(BUILD_DIR)/Bowling_scoretest.o

MAIN_EXEC := $(BIN_DIR)/bowling_game
TEST_EXEC := $(BIN_DIR)/bowling_test

# Google Test flags (update paths if needed)
GTEST_FLAGS := -lgtest -lgtest_main -pthread

# Create folders if they don't exist
$(shell mkdir -p $(BUILD_DIR) $(BIN_DIR))

# Default target: build main game
all: $(MAIN_EXEC)

# Compile main game
$(MAIN_EXEC): $(MAIN_OBJ) $(GAME_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile main.o
$(BUILD_DIR)/main.o: main.cpp $(SRC_DIR)/Bowling.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile Bowling_game.o
$(BUILD_DIR)/Bowling_game.o: $(SRC_DIR)/Bowling_game.cpp $(SRC_DIR)/Bowling.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run main game
run: $(MAIN_EXEC)
	./$(MAIN_EXEC)

# Compile test binary
test: $(TEST_EXEC)

$(TEST_EXEC): $(TEST_OBJ) $(GAME_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(GTEST_FLAGS)

# Compile test object
$(BUILD_DIR)/Bowling_scoretest.o: $(TEST_DIR)/Bowling_scoretest.cpp $(SRC_DIR)/Bowling.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run unit tests
run_test: $(TEST_EXEC)
	./$(TEST_EXEC)

# Clean build files
clean:
	rm -rf $(BUILD_DIR)/*.o $(BIN_DIR)/*
