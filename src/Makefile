# Makefile para compilar un proyecto con SFML usando MinGW

CXX = g++
CXXFLAGS = -IE:/Nicolax/Spacio/SFML/include
LDFLAGS = -LE:/Nicolax/Spacio/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = main.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

run: all
	./$(TARGET)

clean:
	del /Q *.o *.exe
