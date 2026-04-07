*This project has been created as part of the 42 curriculum by adede.*

# Get Next Line

## Description

**get_next_line** is a custom function that lets you read the text file pointed to by the file descriptor, one line at a time. This implementation works as expected both when reading a file and when reading from the standard input.

This subject reinforces:

- Static variables
- System read calls
- Grasp on memory management

## Implemented Features

### Supported Behaviors

Repeated calls (e.g., using a loop) to `get_next_line()` function should let you read the text file pointed to by the file descriptor, one line at a time.

This function returns the line that was read. If there is nothing left to read or if an error occurs, it returns `NULL`.

You can expect this function to work as expected both when reading a file and when reading from the standard input.

The returned line includes the terminating '\n' character, except when the end of the file is reached and the file does not end with a '\n' character.

### Multiple File Descriptors (Bonus)

You can read from multiple file descriptors simultaneously with the bonus features.

> Note that modifying these files during runtime is undefined behavior.

## Instructions

### Compilation
To compile the library, add both of these files:

```bash
cc get_next_line.c get_next_line_utils.c
```

To compile with bonus features, use the '*_bonus*' suffix.

```bash
cc get_next_line_bonus.c get_next_line_utils_bonus.c
```

You can modify the buffer size for the read function by defining the following macro:

```bash
cc get_next_line.c get_next_line_utils.c -D BUFFER_SIZE="1"
```

### Usage
Don't forget to include the header to use `get_next_line` in your projects:

```c
#include "includes/get_next_line.h"
```

For bonus features:

```c
#include "includes/get_next_line_bonus.h"
```

## Example Usage

```c
#include "get_next_line.h"

int main(void)
{
	int fd = 0;
	char *line;

	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	return (0);
}
```

Bonus feature

```c
#include "get_next_line_bonus.h"

int main(void)
{
	int fd1 = open("1", O_RDONLY);
	int fd2 = open("2", O_RDONLY);
	char *line;

	line = get_next_line(fd1);
	printf("%s", line);
	line = get_next_line(fd2);
	printf("%s", line);
	line = get_next_line(fd1);
	printf("%s", line);
	return (0);
}
```

## Resources
- [File descriptors](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/)
- [`read` specification](https://pubs.opengroup.org/onlinepubs/009604599/functions/read.html)
- [`open` specification](https://pubs.opengroup.org/onlinepubs/009604599/functions/open.html)

### AI Usage
AI tools were used to:
- Create unit tests and inform about edge cases.
- Provide explanations for complex C concepts.
- Educate about real world uses of the functions that this library implements.

No AI was used to generate the library code **directly**; all functions were personally implemented but assistively tested.
