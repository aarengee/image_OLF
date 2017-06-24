# Image processing in C

colorinfrared.c is a C program to colorise the infrared image ```ifwatch.bmp``` using pixels from colored image ```colorwatch.bmp``` taken in the dark and 
produce a output image  ```imageout.bmp```

```sh
$ cd programs
$ gcc colorinfrared.c -o exec1
$ ./exec1
```
colorinfrared2.c is a C program to do the above but doesnt desaturate the output image

```sh
$ cd programs
$ gcc colorinfrared2.c -o exec2
$ ./exec2
```
