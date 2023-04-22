lw x9,120(x10)
sw x1,1000(x2)
add x2, x0, x1
add x6, x0, x2
sub x3, x6, x2
xor x4, x2, x3
srl x0, x2, x2
bne x10,x11,2000
bne x10,x11,x12