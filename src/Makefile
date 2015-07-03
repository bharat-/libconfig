SHELL = /bin/bash
CXX = g++
LDFLAGS = -shared
CPPFLAGS = -fPIC -g
DEBUGFLAGS = -O0 -D _DEBUG
LIBPATH = -ljson_linux-gcc-4.8_libmt

TARGET = config_json.so
SOURCES = get.cpp set.cpp init.cpp main.cpp
HEADERS = json_lib.h
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(FLAGS) $(CFLAGS) $(DEBUGFLAGS) $(OBJECTS) $(LIBPATH) -o $(TARGET)

main.o: main.cpp
	$(CXX) $(FLAGS)	-c main.cpp $(LIBPATH)

get.o: get.cpp
	$(CXX) $(FLAGS)	-c get.cpp $(LIBPATH)

set.o: set.cpp
	$(CXX) $(FLAGS)	-c set.cpp $(LIBPATH)

init.o: init.cpp
	$(CXX) $(FLAGS)	-c init.cpp $(LIBPATH)

clean:
	rm *.o  *.so
