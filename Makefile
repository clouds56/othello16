CC=g++
CFLAGS=-O2 -Wall
SOURCE=othello16.cpp gamti.cpp main.cpp

ai1: ${SOURCE}
	${CC} ${CFLAGS} -D_AI1 -o ai/ai1 ${SOURCE}

ai2: ${SOURCE}
	${CC} ${CFLAGS} -D_AI2 -o ai/ai2 ${SOURCE}

debug: ${SOURCE}
	${CC} ${CFLAGS} -D_T_DEBUG -o ai/othello ${SOURCE} ../othello.cpp

clean:
	rm ai/ai1 ai/ai2 ai/othello
