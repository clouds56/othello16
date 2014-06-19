CC=g++
CFLAGS=-O2 -Wall
SOURCE=othello16.cpp gamti.cpp main.cpp
OBJDIR=ai
AIDIR=..

ai1: ${OBJDIR}/ai1

ai2: ${OBJDIR}/ai2

debug: ${OBJDIR}/othello

${OBJDIR}/ai1: ${SOURCE} ${AIDIR}/ai1.cpp |${OBJDIR}
	${CC} ${CFLAGS} -D_AI1 -o ${OBJDIR}/ai1 ${SOURCE}

${OBJDIR}/ai2: ${SOURCE} ${AIDIR}/ai2.cpp |${OBJDIR}
	${CC} ${CFLAGS} -D_AI2 -o ${OBJDIR}/ai2 ${SOURCE}

${OBJDIR}/othello: ${SOURCE} |${OBJDIR}
	${CC} ${CFLAGS} -D_T_DEBUG -o ${OBJDIR}/othello ${SOURCE} ${AIDIR}/othello.cpp

run: ${OBJDIR}/pt.log

show: ${OBJDIR}/pt.log ${OBJDIR}/Show.nb
	mathematica -sl -nosplash ${PWD}/${OBJDIR}/Show.nb

${OBJDIR}/Show.nb: Show.nb
	cp Show.nb ${OBJDIR}/Show.nb

${OBJDIR}/pt.log: ${OBJDIR}/ai1 ${OBJDIR}/ai2 runner.py
	python3 runner.py

${OBJDIR}:
	mkdir -p ${OBJDIR}

clean:
	rm -f ${OBJDIR}/ai1 ${OBJDIR}/ai2 ${OBJDIR}/othello ${OBJDIR}/l1.log ${OBJDIR}/l2.log ${OBJDIR}/pt.log ${OBJDIR}/Show.nb

.PHONY: ai1 ai2 debug clean run show
