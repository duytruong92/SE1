CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lsfml-audio -lsfml-window -lsfml-graphics -lsfml-system
SOURCES=main.cpp player.cpp card.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE=main

all:	$(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE):  
	$(CC)  $(SOURCES) -o $(EXECUTABLE) $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	\rm -f *.o  *~ main
