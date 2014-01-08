
include build.conf
include jvm_ldpath.def

SRCS := jbuse.c jbuse_bindings.c
HDRS := jbuse.h jbuse_bindings.h
LIB_SO := libjbuse.so

INCLUDES := -I${BUSE_INCLUDE} -I${JDK_HOME}/include -I${JDK_HOME}/include/linux

LDPATH := ${LDPATH} -L${BUSE_HOME}

all: ${LIB_SO}

${LIB_SO}: ${SRCS} ${HDRS}
	gcc -fPIC -shared -D_FILE_OFFSET_BITS=64 -o ${LIB_SO} ${INCLUDES} ${LDPATH} ${SRCS} -ljvm -lBUSE -lpthread

clean:
	rm -f ${LIB_SO}
