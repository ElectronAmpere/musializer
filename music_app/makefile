CC= cc
CFLAGS= -Wall -std=c11 $(shell pkg-config --cflags raylib)
ELIBS= $(shell pkg-config --libs raylib)
SYSLIBS= -framework IOKit -framework Cocoa
LIBS= $(ELIBS) $(SYSLIBS)

SRCS= source/main.c
EINCS= source/external/raygui.h

all: musializer

musializer: $(SRCS) $(EINCS)
	$(CC) $(CFLAGS) $(SRCS) -o $@ $(LIBS)

clean:
	rm -rf musializer