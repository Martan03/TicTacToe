CC:=clang++
OUT:=tictactoe
CFLAGS:=-g -Wall -std=c++20
RFLAGS:=-std=c++20 -DNDEBUG -O3
CFILES:=$(wildcard src/*.cpp)
HFILES:=$(wildcard src/*.hpp)
OBJS:=$(patsubst src/%.cpp, obj/%.o, $(CFILES))

debug: $(OBJS)
	$(CC) $(CFLAGS) -o bin/debug/$(OUT) $(OBJS)

release: $(CFILES)
	$(CC) $(RFLAGS) -o bin/release/$(OUT) $(CFILES)

$(OBJS): $(CFILES)
	$(CC) $(CFLAGS) -c $(patsubst obj/%.o, src/%.cpp, $@) -o $@

clean:
	rm $(OBJS)
