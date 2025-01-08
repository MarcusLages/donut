# donut
A program that runs ASCII donut and other geometric shapes using ASCII and linear algebra.
Code is based on the post made by [a1k0n](https://www.a1k0n.net/2011/07/20/donut-math.html) on how to make an ASCII donut. Main idea is to replicate it in both C and Javascript and apply quaternion rotation to it (plus adding some extra shapes).

## TODO list
- [X] Comprehend donut code from a1k0n
- [ ] Replicate code from a1k0n
  - [ ] Replicate code in C
  - [ ] Replicate code in JS
- [ ] Apply quaternion rotation to the code
- [ ] Apply code to other geometric shapes:
  - [ ] Square
  - [ ] Pyramid

## Build
### C terminal program
1. Go into the `c` directory in the terminal.
2. Run the Makefile.
3. Run the executable (`donut`, `./donut` or `./donut` depending on your terminal).
```shell
cd c
make
donut
```

## References and Links
- OneNote with all the math concepts used: [Donut Math Notebook](https://1drv.ms/o/c/8d41faf66157047f/EhQDVeGORbBKqGOD6cRC8scBiFTDcKaRes_5Q3RIGiz0ZA?e=fAhMGX) by [MarcusLages](https://github.com/MarcusLages)
- Initial idea and code: [Donut math: how donut.c works](https://www.a1k0n.net/2011/07/20/donut-math.html) by [a1k0n](https://github.com/a1k0n)
