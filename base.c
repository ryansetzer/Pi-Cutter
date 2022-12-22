#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

struct msg {
    uint8_t id;
    uint8_t type;
    uint8_t flags;
};



int
main()
{
   // opening file
   char *filename = "testMessageBits";
   int fd = open (filename, O_RDONLY);
   FILE *file = fopen(filename, "r");
   // checking valid file
   if (fd == -1) {
    return EXIT_FAILURE;
   }
   // determining packet size
   struct stat s;
   memset (&s, 0, sizeof (s));
   fstat (fd, &s);
   printf ("size of file: %lld\n", s.st_size);
   char *buffer = calloc (1, sizeof (char));
   struct msg message;
   // copying file into struct
   // memcpy (&buffer, file, s.st_size);
   // fread (&buffer, s.st_size, 1, file);
   // printf ("Buffer: %s\n", buffer);
   fread (&message, s.st_size, 1, file);
   printf ("message id: %d\n", message.id - 18);
   printf ("message type: %d\n", message.type - 18);
   printf ("message flags: %d\n", message.flags - 18);
   fclose (file);
   // free (buffer);
   return 0;
}