PRGNAME     = enigma.elf
CC			= gcc
CXX			= g++
STRIP		= strip


SRCDIR		= ./src ./src/actors ./src/floors ./src/gui ./src/items ./src/lev ./src/others ./src/stones
SRCDIR		+= ./lib-src/enet ./lib-src/enigma-core ./lib-src/lua ./lib-src/oxydlib
SRCDIR		+= ./lib-src/zipios++/src

VPATH		= $(SRCDIR)
SRC_C		= $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.c))
SRC_CP		= $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.cpp))
SRC_CP2		= $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.cc))
OBJ_C		= $(notdir $(patsubst %.c, %.o, $(SRC_C)))
OBJ_CP		= $(notdir $(patsubst %.cpp, %.o, $(SRC_CP)))
OBJ_CP2		= $(notdir $(patsubst %.cc, %.o, $(SRC_CP2)))
OBJS		= $(OBJ_C) $(OBJ_CP) $(OBJ_CP2)

CFLAGS		= -O0 -g3 -I/usr/include/SDL -DHAS_SOCKLEN_T -DHAVE_STD_IOSTREAM -DUSE_STD_IOSTREAM -DDPAD_CONTROLS
CFLAGS		+= -Ilib-src/zipios++ -I./lib-src/zipios++/zipios++ -Ilib-src/enet/include -Ilib-src/enigma-core -Ilib-src/lua -Ilib-src/oxydlib
CFLAGS		+= -I./src -I./src/actors -I./src/floors -I./src/gui -I./src/items -I./src/lev -I./src/others -I./src/stones -Ilib-src/zipios++ -Ilib-src


ifeq ($(PROFILE), YES)
CFLAGS 		+= -fprofile-generate=./
else ifeq ($(PROFILE), APPLY)
CFLAGS		+= -fprofile-use
endif

CXXFLAGS	= $(CFLAGS) -std=gnu++11
LDFLAGS     = -lc -lgcc -lstdc++ -lrt -ldl -lm -lSDL -lasound -lpthread -ldrm -ludev -lpng -lz -lxerces-c -lcurl -lSDL_image -lSDL_ttf -lfreetype -lSDL_mixer

ifeq ($(PROFILE), YES)
LDFLAGS 	+= -lgcov
endif

# Rules to make executable
$(PRGNAME): $(OBJS)  
	$(CXX) $(CXXFLAGS) -o $(PRGNAME) $^ $(LDFLAGS)

$(OBJ_C) : %.o : %.c
	$(CC) $(CFLAGS) -Dbool=char -Dtrue=1 -Dfalse=0 -c -o $@ $<
	
$(OBJ_CP) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	
$(OBJ_CP2) : %.o : %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(PRGNAME) *.o
