# Directory that contains this project
PROJECT_DIR = Algorithms_Project
PROJECT = project

# Compilation command and flags
CXX=g++
CXXVERSION= -std=c++11
CXXFLAGS= $(CXXVERSION) -g -fprofile-arcs

# Directories
SRC_DIR = src
PROJECT_SRC_DIR = src/project
SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}

# Default goal, used by Atom for local compilation
.DEFAULT_GOAL := compileProject

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# compilation using the files in include, src, and src/project
compileProject: $(SRC_DIR) $(PROJECT_SRC_DIR)
	$(CXX) $(CXXVERSION) -o $(PROJECT) $(INCLUDE) \
	$(SRC_DIR)/*.cpp $(PROJECT_SRC_DIR)/*.cpp
