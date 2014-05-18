/*
 * Copyright 2014 Thomas Buck <xythobuz@xythobuz.de>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/serial.h"

int fd = -1;

void exithandler() {
    serialClose(fd);
}

int main(int argc, char **argv) {
    if ((argc == 2) && (strcmp(argv[1], "-l") == 0)) {
        char **ports = getSerialPorts();
        char **tmp = ports;
        printf("Available serial ports:\n");
        while (*tmp != NULL)
            printf("  %s\n", *(tmp++));
        free(ports);
    } else if (argc == 3) {
        fd = serialOpen(argv[1], atoi(argv[2]));
        if (fd == -1) {
            printf("Could not open %s with %d!\n", argv[1], atoi(argv[2]));
            return 1;
        }
        atexit(exithandler);
        printf("Connected! Data received will be printed...\n");
        printf("Use CTRL+C to quit.\n");
        for (;;) {
            if (serialHasChar(fd)) {
                char c;
                serialReadChar(fd, &c);
                printf("%c", c);
            }
        }
    } else {
        printf("Usage:\n");
        printf("  %s -l        --> list available ports\n", argv[0]);
        printf("  %s PORT BAUD --> monitor port\n", argv[0]);
    }

    return 0;
}

