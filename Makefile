CC=g++
CFLAGS += -Wall -Wextra -Werror
PROJ_NAME = sshell
PROJ_OBJ = sshell.o

all: $(PROJ_NAME)
	$(CC) $(CFLAGS) $(PROJ_OBJ) -o $(PROJ_NAME)

$(PROJ_OBJ): $(PROJ_NAME).cpp
	$(CC) $(CFLAGS) -c $(PROJ_NAME).c

clean:: 
	-rm -f $(PROJ_NAME) $(PROJ_OBJ)

.PHONY: clean