#
#	Compiler
#
COMPILER		=	g++
LINKER			=	g++
COMPILER_FLAGS		=	-Wall -c -O2 -std=c++11 -fpic -Iinclude -o
LINKER_FLAGS		=	-shared
LINKER_DEPENDENCIES	=	-lphpcpp

NAME			=	cpphalcon
EXTENSION 		=	${NAME}.so
EXTENSION_DIR		=	$(shell php-config --extension-dir)
INI 			=	${NAME}.ini
INI_DIR			=	/etc/php5/conf.d
PHP_CONFIG_DIR		=	/etc/php5/cli/conf.d

RM			=	rm -f
CP			=	cp -f
MKDIR			=	mkdir -p

HEADERS			=	$(wildcard include/*.h)
SOURCES			=	$(wildcard Source/*.cpp)
OBJECTS			=	$(SOURCES:%.cpp=%.o)


#
#	From here the build instructions start
#

all: ${EXTENSION}

${EXTENSION}: ${OBJECTS}
	${LINKER} ${LINKER_FLAGS} -o $@ ${OBJECTS} ${LINKER_DEPENDENCIES}

${OBJECTS}: ${SOURCES} ${HEADERS}
	${COMPILER} ${COMPILER_FLAGS} $@ ${@:%.o=%.cpp}

install: ${EXTENSION}
	${CP} ${EXTENSION} ${EXTENSION_DIR}
	${CP} ${INI} ${INI_DIR}
	${CP} ${INI} ${PHP_CONFIG_DIR}
				
clean:
	${RM} ${EXTENSION} ${OBJECTS}
