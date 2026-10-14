*This project has been created as part of the 42 curriculum by Younes Abyaa.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the C standard library function `printf()`. The goal of the project is to learn how **variadic functions** work in C (`<stdarg.h>`) and to write clean, extensible code that parses a format string and prints formatted output.

The project produces a static library, `libftprintf.a`, exposing a single function:

```c
int ft_printf(const char *format, ...);
```

It returns the number of characters printed, like the original `printf()`.

### Supported conversions

| Conversion | Description                                      |
|------------|--------------------------------------------------|
| `%c`       | A single character                               |
| `%s`       | A string (prints `(null)` for a `NULL` pointer)  |
| `%p`       | A `void *` pointer in hexadecimal (`0x...`)      |
| `%d`       | A signed decimal (base 10) number                |
| `%i`       | A signed integer in base 10                      |
| `%u`       | An unsigned decimal (base 10) number             |
| `%x`       | A number in lowercase hexadecimal (base 16)      |
| `%X`       | A number in uppercase hexadecimal (base 16)      |
| `%%`       | A literal percent sign                           |

As required by the subject, the buffer management of the original `printf()` is **not** reimplemented.

## Instructions

### Compilation

The library is built with `cc` and the flags `-Wall -Wextra -Werror`, and archived with `ar`.

```bash
make          # builds libftprintf.a at the root of the repository
make clean    # removes object files
make fclean   # removes object files and libftprintf.a
make re       # fclean + all
```

### Usage

Include the header and link against the library:

```c
#include "ft_printf.h"

int main(void)
{
    int n;

    n = ft_printf("Hello %s! %d + %i = %u | %x %X | %c | %p | 100%%\n",
                  "world", 1, 2, 3U, 255, 255, 'A', (void *)&n);
    ft_printf("Printed %d characters\n", n);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
./test
```

### Testing

Compare the output and the return value of `ft_printf()` against the original `printf()` for each conversion, including edge cases (`INT_MIN`, `UINT_MAX`, `0`, `NULL` string, `NULL` pointer, empty string, `%` at the end of the format string).

## Algorithm and data structure

### Algorithm

`ft_printf` walks through the format string **once, from left to right**, using a simple parse-and-dispatch approach:

1. Initialise the argument list with `va_start`.
2. For each character of the format string:
   - If it is not `%`, write it directly to standard output with `write`.
   - If it is `%`, read the following character (the conversion specifier) and dispatch to the matching handler.
3. Each handler fetches its argument with `va_arg`, converts it if needed, writes it, and **returns the number of bytes written**.
4. The returned counts are accumulated into a running total, which is returned at the end after `va_end`.

Number printing (`%d`, `%i`, `%u`, `%x`, `%X`, `%p`) is done with a **recursive base conversion**: the number is divided by the base, the function recurses on the quotient, then prints the current digit. This outputs digits in the right order without any temporary buffer, so **no dynamic allocation** is needed and there is no risk of memory leaks.

Details handled explicitly:

- `%d` / `%i`: `INT_MIN` is handled by converting to a wider type before negating.
- `%u`, `%x`, `%X`: the argument is read as `unsigned int`.
- `%p`: the argument is read as `unsigned long` (pointer-sized) and printed with a `0x` prefix. A `NULL` pointer is printed as `(nil)` to match the Linux `printf()`.
- `%s`: a `NULL` string is printed as `(null)`.
- Write errors are propagated by returning `-1`.

### Why this design?

- **No special data structure is needed.** The format string is processed sequentially and every conversion is independent, so the only state is the `va_list` and an integer counter.
- **Dispatch by specifier** keeps the main loop small and makes the code easy to extend: adding a new conversion (or the bonus flags) means adding a handler, not rewriting the parser.
- **Writing directly with `write`** follows the subject (no buffering) and keeps the return value trivially correct, since each handler reports exactly what it printed.
- **Recursion for base conversion** avoids `malloc`/`free` entirely, which removes a whole class of errors.

## Resources

### References

- `man 3 printf` — behaviour of the original function and its conversions
- `man 3 stdarg` (`va_start`, `va_arg`, `va_copy`, `va_end`) — variadic functions
- `man 2 write`
- *The C Programming Language*, Kernighan & Ritchie — chapter on variadic functions and formatted output
- The 42 Norm and the project subject (version 12.1)

### Use of AI

AI was used for the following tasks only:

- Drafting and structuring this `README.md` file.