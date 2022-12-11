%[flags][width][.precision][size]type

printf("I am a boy of age, %d", 30);

printf("I aged %5d years old, and I am a boy", 30);

## Task 0
printf("%s");
printf("%c");
printf("%%");
````c
int _printf(const char *format, ...)
````
```
SET format TO a character string
SET list TO variadic parameters
SET CONST BUFF_SIZE to 1028
SET buffer TO array of size BUFF_SIZE
SET buffer_index TO 0
SET printed_chars TO 0

if format == NULL
    return (-1)

SET i = 0
for (i; format && format[i] != '\0'; ++i)
    if (format[i] != '%')
        SET buffer[buffer_index++] to format[i];
        if (buffer_index == BUFFER_SIZE)
            PRINT AND RESET BUFFER: buffer, buffer_size
        INCREMENT printed_char;
    else
        PRINT AND RESET BUFFER: buffer, buffer_size
        SET flag TO GET_FLAG(format, i);
        SET width TO GET_WIDTH(format, i);
        SET precision TO GET_PRECISION(format, i);
        SET size TO GET_SIZE(format, i);
        SET type TO GET_TYPE(format, i);

        INCREMENT i;

        SET printed TO length of conversion string
        if printed == -1
            return (-1)
        SET printed_char += printed;

PRINT AND RESET BUFFER: buffer, buffer_size

return (printed_char);
```

### PRINT AND RESET BUFFER FUNCTION

````c
READ buffer, buffer_index
if buffer_index > 0
    write buffer TO stdout
SET *buffer_index TO 0
````

### GET CONVERSION STRING LENGTH

