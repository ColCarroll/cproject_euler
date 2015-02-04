CC=gcc
CFLAGS=-Wall -g
LDFLAGS=-shared

PROBLEMS=$(wildcard p*.c)
PROBLEM_LIBS=$(patsubst %.c,%.so,$(PROBLEMS))

all: solve $(PROBLEM_LIBS)

solve: solve.c
	cc -Wall -g -DNDEBUG solve.c -ldl -o solve

primes.o: primes.c
	$(CC) $(CFLAGS) -c $^ -o $@

libprimes.a: primes.o
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -fPIC -o $@ $^

%.so: %.o libprimes.a
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -f libprimes.a
	rm -f solve
	rm -f *.o
	rm -f *.so
	rm -rf *.dSYM
