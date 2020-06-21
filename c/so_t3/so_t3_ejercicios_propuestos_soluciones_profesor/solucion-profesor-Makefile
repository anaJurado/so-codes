CC = gcc
CFLAGS = -g -Wall

PROGRAMS = myseq invert getenv mycd myhead

all: $(PROGRAMS)

% : %.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY : clean

clean:
	rm *~ $(PROGRAMS)

