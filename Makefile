CC=g++
CFLAGS += -Wall -Wextra -Werror
PROJ_NAME = MergeSortedArray
PROJ_OBJ = MergeSortedArray.o

all: $(PROJ_NAME)
	$(CC) $(CFLAGS) $(PROJ_OBJ) -o $(PROJ_NAME)

$(PROJ_OBJ): $(PROJ_NAME).cpp
	$(CC) $(CFLAGS) -c $(PROJ_NAME).cpp

clean:: 
	-rm -f $(PROJ_NAME) $(PROJ_OBJ)

.PHONY: clean