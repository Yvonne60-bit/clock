all: signals test
signals: signal.c
	gcc signal.c -o signalab
test: Clock.c
	gcc Clock.c -o clocklab
