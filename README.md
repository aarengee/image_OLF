# Image processing in C

See qdbmp API calls at http://qdbmp.sourceforge.net/

colorinfrared.c is a C program to colorise the infrared image ```ifwatch.bmp``` using pixels from colored image ```colorwatch.bmp``` taken in the dark and 
produce a output image  ```imageout.bmp```

```sh
$ cd programs
$ gcc colorinfrared.c -o exec1
$ ./exec1
```
colorinfrared2.c is a C program to do the above task but doesnt desaturate the output image as I fill real pixel values and not the mean

```sh
$ cd programs
$ gcc colorinfrared2.c -o exec2
$ ./exec2
```
