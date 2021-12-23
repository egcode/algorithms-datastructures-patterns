# # #### BIT Wise Operations

#####-------------------
# # #### BIT Wise Operations
x=7
print(f'{x:08b}') # 00000111
x = x & (-x) # keeps rightmost 1-bit and sets all other bits to 0
print(f'{x:08b}') # 00000001
print("--")
x=7
print(f'{x:08b}') # 00000111
x = x & (x-1) # removes rightmost 1-bit 
print(f'{x:08b}') # 00000110
#####-------------------


d1=512
print(d1 >> 1) #  256  - Divide by 2
print(d1 << 1) #  1024 - Multiply by 2

################### CREATE BINARY MASK: 
mask=0
print(format(mask, '0{}b'.format(31))) # 0000000000000000000000000000000
for i in range(10):
    mask |= 1<<i # adds one  to the mask
print(format(mask, '0{}b'.format(31))) # 0000000000000000000001111111111
# OR MASK ALL:
mask=0
for i in range(31):
    mask |= 1<<i # adds one  to the mask
print(format(mask, '0{}b'.format(31))) # 1111111111111111111111111111111



# ######################### Inverse BITs
num=203
print("actual   number: " + format(num, '0{}b'.format(31))) # 0000000000000000000000011001011
mask=0
power=30
while num:
    if num & 1 == 1: # if first bit is one
        mask += 1 << power
    num = num >> 1 # shift everything to right, until all bits are zero
    power -= 1
    print("num: " + format(num, '0{}b'.format(31)) + "   mask: "+ format(mask, '0{}b'.format(31)))

'''
num: 0000000000000000000000001100101   mask: 1000000000000000000000000000000
num: 0000000000000000000000000110010   mask: 1100000000000000000000000000000
num: 0000000000000000000000000011001   mask: 1100000000000000000000000000000
num: 0000000000000000000000000001100   mask: 1101000000000000000000000000000
num: 0000000000000000000000000000110   mask: 1101000000000000000000000000000
num: 0000000000000000000000000000011   mask: 1101000000000000000000000000000
num: 0000000000000000000000000000001   mask: 1101001000000000000000000000000
num: 0000000000000000000000000000000   mask: 1101001100000000000000000000000
'''
print("inversed   bits: " + format(mask, '0{}b'.format(31))) # 1101001100000000000000000000000




# #############################################
# ## Bit mask as hash map
mask=0
def setKthBit(mask, k):
    mask |= 1<<k
    return mask
def isKthBitSet(mask, k):
    if (mask & (1 << k)):
        return True
    return False

mask=0
print("mask: " + format(mask, '0{}b'.format(8))) # 00000000
m=setKthBit(mask, 3)
print("mask: " + format(m, '0{}b'.format(8))) # 00001000
for i in range(1,8):
    print(str(i)+"th bit set:"+str(isKthBitSet(m, i)))
'''
1th bit set:False
2th bit set:False
3th bit set:True
4th bit set:False
5th bit set:False
6th bit set:False
7th bit set:False
'''