PROJ_NAME = hello
make:
	go build -o bin/$(PROJ_NAME) $(PROJ_NAME).go

run:
	go run $(PROJ_NAME).go

clean:: 
	-rm -f bin/$(PROJ_NAME)