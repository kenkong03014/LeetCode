CC=g++
CFLAGS += -Wall -Wextra -Werror
PROJ_NAME = reverseLinkedList
PROJ_OBJ = reverseLinkedList.o

all: $(PROJ_NAME)
	$(CC) $(CFLAGS) $(PROJ_OBJ) -o $(PROJ_NAME)

$(PROJ_OBJ): $(PROJ_NAME).cpp
	$(CC) $(CFLAGS) -cpp $(PROJ_NAME).cpp

clean:: 
	-rm -f $(PROJ_NAME) $(PROJ_OBJ)

.PHONY: clean
	