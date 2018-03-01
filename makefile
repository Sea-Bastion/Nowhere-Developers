CC = g++
CFLAGS = -std=$(VERSION)
DFLAGS = -g
VERSION = c++17

run: compiled/release/main
	./$<

compiled/release/main: No\ Friends.cpp
	$(CC) "$<" -o $@ $(CFLAGS)

debug: compiled/debug/main
	gdb $<

compiled/debug/main: No\ Friends.cpp
	$(CC) $(DFLAGS) "$<" -o $@ $(CFLAGS)