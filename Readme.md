# serial.c

POSIX serial port interface with optional XON/XOFF transmission flow control support.

## Example

Check out the included example.c or compile it using the included Makefile.
The example application allows you to list available serial ports, or connect
to one and print all received data.

## API

The API is pretty much self-explanatory. Take a look at src/serial.h for more
informations, the file contains much more documentation and explanations.

```c

// Configuration

//#define XONXOFF
#define XON 0x11  //!< XON flow control character
#define XOFF 0x13 //!< XOFF flow control character
#define SEARCH "tty"
//#define TRY_TO_OPEN_PORTS
#define TIMEOUT 2

// Setup

int serialOpen(const char *port, unsigned int baud);
void serialClose(int fd);
char **getSerialPorts(void);

// Raw, non-blocking I/O

unsigned int serialReadRaw(int fd, char *data, int length);
unsigned int serialWriteRaw(int fd, const char *data, int length);
void serialWaitUntilSent(int fd);

// Blocking I/O

int serialHasChar(int fd);
void serialReadChar(int fd, char *c);
void serialWriteChar(int fd, char c);
void serialWriteString(int fd, const char *s);

```

