# Zadanie3
## Nizkourovnove IO

### Windows

 * generator
   * compile `gcc -Wall -o generator.exe src/generator.c `
   * run `generator.exe $filename $n`with params filename and count of sequences

 * analyze 
   * compile `gcc -Wall -o analyze.exe src/analyze.c`
   * run `analyze.exe $filename`with param filename
   
### Linux

 * remove `O_BINARY` in method `open` (analyze.c and generator.c)
 * add mode `0666`in method `open` (generator.c)

