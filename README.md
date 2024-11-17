# Assembly helper: Str2Zasm for ZX81 strings

The <a href='https://www.bing.com/search?q=Sinclair+ZX81'>Sinclair ZX81</a> home computer uses a non-ASCII character set and most Z80 assemblers do not support it. But with defined bytes you can string the chacters together

Tired of manually typing strings into db or DEFB constructs? Use **Str2Zasm**

       ;'HELLO WORLD'
       DEFB _H,_E,_L,_L,_O,__,_W,_O,_R,_L,_D

The manual way is
* tedious
* error-prone

Source code here is C++ and includes a Visual Studio 2022 project for Windows Console (command line application)


This is sort of a copy-and-paste utility. Or you can redirect the output to a file:

       C:\fasmw-zx>Str2Zasm "ZX81 LIVES"
       _Z,_X,_8,_1,__,_L,_I,_V,_E,_S
       
       C:\fasmw-zx>Str2Zasm "ZX81 LIVES" > text.txt


With the output, you can put it into your favorite cross-platform Z80 assembly file:


         include "charcodes.inc"
       
            ;'HELLO WORLD'
            db _H,_e,_l,_l,_o,__,_W,_o,_r,_l,_d

Tested with sjasm and sjasmplus assemblers

# License
Use and modify Str2Zasm [as you see fit](UNLICENSE)
