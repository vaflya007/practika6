app: main.c filelib.c
	gcc main.c filelib.c -o app
run: app
	./app
clean:
	rm -f app