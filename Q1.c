#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

// Buffer size for reading and writing
#define BUFFER_SIZE 1024

    // Function prototypes
    void demonstrateSystemCalls();
void demonstrateCLibraryFunctions();

int main()
{
    printf("Demonstrating file operations using System Calls:\n");
    demonstrateSystemCalls();

    printf("\nDemonstrating file operations using C Library Functions:\n");
    demonstrateCLibraryFunctions();

    return 0;
}

void demonstrateSystemCalls()
{
    int fd;
    ssize_t bytesRead, bytesWritten;
    char buffer[BUFFER_SIZE];

    // 1. Opening a file using open (O_CREAT creates the file if it doesn't exist)
    fd = open("system_call_example.txt", O_CREAT | O_RDWR, 0644);
    if (fd == -1)
    {
        perror("Error opening file using open");
        exit(EXIT_FAILURE);
    }

    // 2. Writing to a file using write
    const char *text = "This is a demonstration of file operations using system calls.\n";
    bytesWritten = write(fd, text, strlen(text));
    if (bytesWritten == -1)
    {
        perror("Error writing to file using write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // 3. Moving the file pointer using lseek
    if (lseek(fd, 0, SEEK_SET) == -1)
    {
        perror("Error using lseek");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // 4. Reading from a file using read
    bytesRead = read(fd, buffer, BUFFER_SIZE - 1);
    if (bytesRead == -1)
    {
        perror("Error reading from file using read");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Null-terminate the buffer and print the content
    buffer[bytesRead] = '\0';
    printf("Read from file:\n%s", buffer);

    // 5. Closing a file using close
    if (close(fd) == -1)
    {
        perror("Error closing file using close");
        exit(EXIT_FAILURE);
    }
}

void demonstrateCLibraryFunctions()
{
    FILE *file;
    char buffer[BUFFER_SIZE];

    // 1. Opening a file using fopen
    file = fopen("c_library_example.txt", "w+");
    if (file == NULL)
    {
        perror("Error opening file using fopen");
        exit(EXIT_FAILURE);
    }

    // 2. Writing to a file using fwrite and fprintf
    const char *text = "This is a demonstration of file operations using C library functions.\n";
    if (fwrite(text, sizeof(char), strlen(text), file) < strlen(text))
    {
        perror("Error writing to file using fwrite");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Adding another line using fprintf.\n");

    // 3. Moving the file pointer to the beginning using fseek
    if (fseek(file, 0, SEEK_SET) != 0)
    {
        perror("Error using fseek");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // 4. Reading from a file using fread
    size_t bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE - 1, file);
    if (ferror(file))
    {
        perror("Error reading from file using fread");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // Null-terminate the buffer and print the content
    buffer[bytesRead] = '\0';
    printf("Read from file:\n%s", buffer);

    // 5. Closing a file using fclose
    if (fclose(file) != 0)
    {
        perror("Error closing file using fclose");
        exit(EXIT_FAILURE);
    }
}