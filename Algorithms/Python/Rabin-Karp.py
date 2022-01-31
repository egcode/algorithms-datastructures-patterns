def findPattern(s: str, power: int, modulo: int, pattern: str) -> int:
    '''
    Rolling hash. 
    
    Example from problem 2156 in leetcode.
    hash(s, p, m) = (val(s[0]) * p^0 + val(s[1]) * p^1 + ... + val(s[k-1]) * p^k-1) mod m.


    The idea here is to do sliding window.
    Tricky part is that we should slide window from beginning
    because we need p^0 + p^1 + ... + p^k-1
    1. if we do that from the beginning we need to add p^k-1 at the end 
    of the window and divide whole window to p
    2. if we loop from the end - we always add val(s[i]) * p^0 where p^0 always 1,
    and we need to multiply whole window to p.
    
    Multiplication here is better than division.

    '''

    def val(ch):
        return (ord(ch)-ord('a')+1)           

    # Calculating pattern hash value
    k=len(pattern)
    hashValue=0
    for j in range(k):
        hashValue += (val(pattern[j]) * (pow(power,j)) ) % modulo
    hashValue %= modulo
    print("Pattern Hash Value: "+str(hashValue))


    # Searching Pattern in the string
    n=len(s)
    pk=pow(power,k)
    res=n
    win=0
    for i in range(n-1,-1,-1):
        # win*power=mult power to prev window
        # val(s[0]) * p^0 
        win = (win*power + val(s[i])) % modulo              
        
        if i+k<n:
            win = (win - val(s[i+k]) * pk) % modulo
            
        if win==hashValue:
            res=i
    
    print(pattern + "  was found on index: "+str(res))
    print("final pattern found: "+s[res:res+k] )
    return res   


findPattern("onetwothree", 31, 100, "two")
