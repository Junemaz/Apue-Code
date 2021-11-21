INSTALL_ROOT = $(shell pwd)
SRC = "default.c"

def:
	gcc -I ${INSTALL_ROOT}/include -o ${INSTALL_ROOT}/a.out ${INSTALL_ROOT}/src/error.c ${SRC}

clean:
	rm -f ${INSTALL_ROOT}/*.out