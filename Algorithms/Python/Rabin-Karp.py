def findStartIndex(pattern, source):
    '''
    Rolling hash. 
    '''
    seen = set()
    curHash = 0
    patternHash = 0
    MOD = 9023874098237409872309487
    length = len(pattern)

    numsSource=[ord(c)-ord('a') for c in source]
    numsPattern=[ord(c)-ord('a') for c in pattern]

    # d is the number of characters in the input alphabet
    d = 256            
    for i in range(length):
        curHash = (curHash * d + numsSource[i]) % MOD
        patternHash = (patternHash * d + numsPattern[i]) % MOD
    seen.add(curHash)
    
    a = (d**length) % MOD
    for i in range(length,len(source)):
        curHash = (curHash * d + numsSource[i] - numsSource[i-length] * a) % MOD
        
        if curHash == patternHash:
            return i-length+1
    return -1

#         01234567890    
source = "123456yobanaV346563sdsdkhfhs"
pattern = "yobana"

res1 = findStartIndex(pattern, source)
print("Found source: "+str(res1)) # Found source: 6

source = "abcdefghijklm"
pattern = "xyz"
res2 = findStartIndex(pattern, source)
print("Found source: "+str(res2)) # Found source: 1
