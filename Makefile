# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude

# Source files
SRC = src/main.cpp src/common/loadShader.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = opengl_app

# Libraries to link
LIBS = -lglfw -lGLEW -ldl -lGL -lm

# Build target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $(SRC) $(LIBS)

clean:
	rm -f $(TARGET) *.o