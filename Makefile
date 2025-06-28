# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude

# Source files
SRC = src/main.cpp src/glad.c
OBJ = $(SRC:.cpp=.o)
TARGET = opengl_app

# Libraries to link
LIBS = -lglfw -ldl -lGL -lm

# Build target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $(SRC) $(LIBS)

clean:
	rm -f $(TARGET) *.o