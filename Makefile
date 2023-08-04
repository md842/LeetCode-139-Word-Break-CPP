CFLAGS = -std=gnu17 -Wall -O0 -pipe -fno-plt -fPIC
CPPFLAGS = -Wall -O0 -pipe -fno-plt -fPIC

default: word_break_cpp

word_break: word_break.c
	$(CC) $(CFLAGS) word_break.c -o word_break

word_break_cpp: word_break.cpp
	g++ $(CPPFLAGS) word_break.cpp -o word_break

.PHONY: clean
clean:
	rm -f word_break
