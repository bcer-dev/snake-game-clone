CXX ?= g++
CXXFLAGS ?= -g
SFML := -IC:\SFML-2.5.1\include -LC:\SFML-2.5.1\lib
LIBS += -lsfml-system -lsfml-window -lsfml-graphics

snake: *.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SFML) $(LIBS)