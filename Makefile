all: flappyBirb


WARNINGS = -Wall
DEBUG = -ggdb -fno-omit-frame-pointer
OPTIMIZE = -O2
RAYLIB = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

flappyBirb: Makefile main.c
	$(CC) -o $@ $(WARNINGS) $(DEBUG) $(OPTIMIZE) $(RAYLIB) main.c

clean:
	rm -f flappyBirb

# Builder will call this to install the application before running.
install:
	echo "Installing is not supported"

# Builder uses this target to run your application.
run: flappyBirb
	./flappyBirb

