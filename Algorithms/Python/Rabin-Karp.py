def findStartIndex(pattern, source):
    '''
    Rolling hash. 
    '''
    seen = set()
    curHash = 0
    patternHash = 0
    MOD = 9023874098237409872309487
    length = len(pattern)

    def toInt(c):
        return ord(c)-ord('a')

    # d is the number of characters in the input alphabet
    d = 256            
    for i in range(length):
        curHash = (curHash * d + toInt(source[i])) % MOD
        patternHash = (patternHash * d + toInt(pattern[i])) % MOD
    seen.add(curHash)
    
    a = (d**length) % MOD
    for i in range(length,len(source)):
        curHash = (curHash * d + toInt(source[i]) - toInt(source[i-length]) * a) % MOD
        
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
print("Source not found: "+str(res2)) # Source not found: -1
