# Write a shell script that accepts a file name, starting and ending line numbers as arguments and displays all the lines between the given line numbers. 
```sh
#!/bin/bash
if [ $# -ne 3 ]; then
  echo "Usage: $0 <filename> <start_line> <end_line>"
  exit 1
fi
sed -n "${2},${3}p" "$1"
```
# Write a shell script that deletes all lines containing a specified word in one or more files supplied as arguments to it.
```sh
#!/bin/bash
word="$1"
shift
while [[ $# -gt 0 ]]; do
  file="$1"
  grep -v "$word" "$file" > temp.txt && mv temp.txt "$file"
  shift
done
```
# Write a shell script that displays a list of all the files in the current directory to which the user has read, write and execute permissions.
```sh
#!/bin/bash
for file in *; do
  [[ -r "$file" && -w "$file" && -x "$file" ]] && echo "$file"
done
```
# WC
```c
#include <stdio.h>
int main(int argc, char *argv[]) {
  if (argc != 2) return 1; 
  FILE *f = fopen(argv[1], "r");
  int c, l = 0, w = 0;
  while ((c = fgetc(f)) != EOF) {
    l += (c == '\n');
    w += (c == ' ' || c == '\t' || c == '\n');
  }
  printf("Lines: %d\nWords: %d\nChars: %ld\n", l, w, ftell(f));
  fclose(f);
  return 0;
}
```
# cat
```c
#include <stdio.h>
int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    FILE *f = fopen(argv[i], "r");
    if (f) {
      int c;
      while ((c = fgetc(f)) != EOF) putchar(c);
      fclose(f);
    } 
  }
  return 0;
}
```
# cp
```sh
#include <stdio.h>
int main(int argc, char *argv[]) {
  if (argc != 3) return 1;
  FILE *s = fopen(argv[1], "rb"), *d = fopen(argv[2], "wb");
  if (!s || !d) return 1;
  char buf[1024];
  size_t n;
  while ((n = fread(buf, 1, 1024, s)) > 0) 
    fwrite(buf, 1, n, d);
  fclose(s);
  fclose(d);
  return 0;
}
```
# Write a shell script that receives any number of file names as arguments checks if every argument supplied is a file or directory and reports accordingly. Whenever the argument is a file, the number of lines on it is also reported.
```sh
#!/bin/bash
for file in "$@"; do
  if [[ -f "$file" ]]; then
    echo "$file is a file."
    echo "Number of lines: $(wc -l < "$file")"
  elif [[ -d "$file" ]]; then
    echo "$file is a directory."
  else
    echo "$file is not a regular file or directory."
  fi
done
```
# Write a shell script that accepts a file names as its arguments, counts and reports the occurrence of each word that is present in the file argument file in other argument files
```sh
#!/bin/bash
if [ $# -lt 2 ]; then
  echo "Usage: $0 <target_file> <file1> <file2> ..."
  exit 1
fi
target_file="$1"
shift
while [[ $# -gt 0 ]]; then
  file="$1"
  mapfile -t words < <(tr -s ' ' '\n' < "$target_file")
  for word in "${words[@]}"; do
    count=$(grep -o "$word" "$file" | wc -l)
    if [ "$count" -gt 0 ]; then
      echo "$word occurs $count times in $file"
    fi
  done
  shift
done
```
# To list all of the directory files in a directory
```sh
#!/bin/bash
for file in *; do
  if [[ -d "$file" ]]; then
    echo "$file"
  fi
done
```
# Write a shell script to find factorial of a given number.
```sh
#!/bin/bash
if [ $# -ne 1 ]; then
  echo "Usage: $0 <number>"
  exit 1
fi
num=$1
fact=1
while [ $num -gt 0 ]; do
  fact=$((fact * num))
  num=$((num - 1))
done
echo "Factorial of $1 is: $fact"
```
# Rename
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <old_name> <new_name>\n", argv[0]);
        return 1;
    }
    if (rename(argv[1], argv[2]) == -1) {
        perror("rename");
        return 1;
    }
    printf("File renamed successfully.\n");
    return 0;
}
```
```sh
gcc rename.c -o rename
gcc link.c -o link
./rename old_filename new_filename
./link original_file link_name
```
# Link
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <original_file> <link_name>\n", argv[0]);
        return 1;
    }
    if (link(argv[1], argv[2]) == -1) {
        perror("link");
        return 1;
    }
    printf("Link created successfully.\n");
    return 0;
}
```
# Write a C program to emulate the Unix ls – l command. 
```c
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
int main(int argc, char **argv) {
  if (argc != 2) { 
    fprintf(stderr, "Usage: %s <directory>\n", argv[0]); 
    return 1; 
  }
  DIR *dir;
  struct dirent *entry;
  if ((dir = opendir(argv[1])) == NULL) { 
    perror(argv[1]); 
    return 1; 
  }
  while ((entry = readdir(dir)) != NULL) { 
    printf("%s\n", entry->d_name); 
  }
  closedir(dir);
  return 0;
}
```
```sh
gcc my_ls.c -o my_ls
./my_ls <directory_name>
```
# Write a C program on zombie process 
```sh
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    if (pid == 0) { // Child process
        printf("Child process: PID = %d\n", getpid());
        sleep(5); // Simulate some work
        exit(0); // Child process exits normally
    } else { // Parent process
        printf("Parent process: PID = %d\n", getpid());
        // Parent continues without waiting for child
        while(1); 
    }
    return 0;
}
```
```sh
gcc zombie.c -o zombie
./zombie
```