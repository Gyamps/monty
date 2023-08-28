# Testing basic operations
push 1
push 2
push 3
pall
pop
pall

# Testing character and string operations
push 72
pchar
push 101
push 108
push 108
push 111
push 0
push 108
push 111
push 111
push 104
push 99
push 83
pstr

# Testing nop, swap, and rotl/rotr
nop
swap
pall
rotl
pall
rotr
pall

# Testing additional cases
push 65
pint
pchar
push 0
pchar
