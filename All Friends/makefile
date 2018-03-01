CC = g++
CFLAGS = -std=$(VERSION)
DFLAGS = -g
VERSION = c++17

run: compiled/release/main
	./$< < input.txt

compiled/release/main: All\ Friends.cpp
	$(CC) "$<" -o $@ $(CFLAGS)

debug: compiled/debug/main
	gdb $<

compiled/debug/main: All\ Friends.cpp
	$(CC) $(DFLAGS) "$<" -o $@ $(CFLAGS)
