
example: example.c src/serial.c
	$(CC) -std=c99 -Wall $^ -o $@

clean:
	rm -rf example

.PHONY: example clean
