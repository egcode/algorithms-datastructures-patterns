# # #### BIT Wise Operations

#####-------------------
# # #### BIT Wise Operations
x=7
print(f'{x:08b}')
x = x & (-x) # keeps rightmost 1-bit and sets all other bits to 0
print(f'{x:08b}')
print("--")
x=7
print(f'{x:08b}')
x = x & (x-1) # removes rightmost 1-bit 
print(f'{x:08b}')
#####-------------------


d1=512
print(d1 >> 1) # = 256  - Divide by 2
print(d1 << 1) # = 1024 - Multiply by 2

## CREATE BINARY MASK: 
mask=0
print(format(mask, '0{}b'.format(31)))
for i in range(10):
    mask |= 1<<i # adds one  to the mask
binary_string = format(mask, '0{}b'.format(31))
print(binary_string)
# OR MASK ALL:
mask=0
for i in range(31):
    mask |= 1<<i # adds one  to the mask
binary_string = format(mask, '0{}b'.format(31))
print(binary_string)



# # # # ### Inverse BITs
num=43261596
print("actual   number: " + format(num, '0{}b'.format(31)))
mask=0
power=0
while num:
    if num & 1 == 1: # if first bit is one
        mask += 1 << power        
    num = num >> 1 # shift everything to right, until all bits are zero
    power += 1
print("reproduced bits: " + format(mask, '0{}b'.format(31)))

num=43261596
mask=0
power=31
while num:
    if num & 1 == 1: # if first bit is one
        mask += 1 << power
    num = num >> 1 # shift everything to right, until all bits are zero
    power -= 1
print("inversed   bits: " + format(mask, '0{}b'.format(31)))

#############################################
## But mask as hash map
mask=0
def setKthBit(mask, k):
    mask |= 1<<k
    return mask
def isKthBitSet(mask, k):
    if (m & (1 << k)):
        return True
    return False

mask=0
print("mask: " + format(mask, '0{}b'.format(8)))
m=setKthBit(mask, 3)
print("mask: " + format(m, '0{}b'.format(8)))
for i in range(1,8):
    print(str(i)+"th bit set:"+str(isKthBitSet(m, i)))
