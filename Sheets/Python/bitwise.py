# # #### BIT Wise Operations

# ######################### Combination Binary masks

### Reverse Indexing:
n=5
for i in range(n):
    print("     i: "+str(i))     # 0 1 2 3 4
print(" ")
for i in range(n):
    print(" n-1-i: "+str(n-1-i)) # 4 3 2 1 0

# ######################### Combination Binary masks
'''
if we want all combinations of bits withing 3 bit sections, we should loop 1 << 3 which is 8. Example:
'''
n=3 # we need all combination within 3 bit sections.  1 << n  ==  1 << 3 == 8
for i in range(1 << n): # will loop from `0` to `8`
    '''
    i: 0 binary: 000
    i: 1 binary: 001
    i: 2 binary: 010
    i: 3 binary: 011
    i: 4 binary: 100
    i: 5 binary: 101
    i: 6 binary: 110
    i: 7 binary: 111
    '''
    print("i: " + str(i) + " binary: " + format(i, '0{}b'.format(n)))
    for j in range(n): # loop through bits:
        if i & (1 << n-1-j):
            print(" \t\t\tyes ")
        else:
            print(" \t\t\tno ")
        
print("-"*20)


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