INCLUDE=./include/
SRC=./src/
LIB=./lib/
TMP=./tmp/
BIN=./bin/

all:test.cpp libLDPC.a 
	g++ test.cpp -I${INCLUDE} -L${LIB} -lLDPC -o ${BIN}test.out
	${BIN}test.out
libLDPC.a:H.o ${INCLUDE}H.h code.o ${INCLUDE}code.h channel.o ${INCLUDE}channel.h 
	ar rcs ${LIB}libLDPC.a ${TMP}H.o ${TMP}code.o ${TMP}channel.o 
H.o:${SRC}H.cpp
	g++ -c ${SRC}H.cpp -o ${TMP}H.o
code.o:${SRC}code.cpp
	g++ -c ${SRC}code.cpp -o ${TMP}code.o
channel.o:${SRC}channel.cpp
	g++ -c ${SRC}channel.cpp -o ${TMP}channel.o




main:
	g++ main.cpp -o a.out 
	clear
	./a.out

clear:
	rm -r ${BIN}*
	rm -r ${TMP}*
	rm -r ${LIB}*
