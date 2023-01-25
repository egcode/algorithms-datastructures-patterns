

def findPattern(text, pattern):
    '''
    Knuth–Morris–Pratt Algorithm
    '''
    if pattern == "": return 0
    
    # Defining Longest Prefix Suffix
    lps=[0]*len(pattern)
    prevLPS=0
    i=1
    while i<len(pattern):
        if pattern[i]==pattern[prevLPS]:
            lps[i]=prevLPS+1
            prevLPS += 1
            i += 1
        elif prevLPS==0:
            lps[i]=0
            i += 1
        else:
            prevLPS=lps[prevLPS-1]
            
    # Finding patterin in the text
    i=0 # text pointer
    j=0 # pattern pointer
    while i<len(text):
        if text[i]==pattern[j]:
            i += 1
            j += 1
        else:
            if j==0:
                i += 1
            else:
                j=lps[j-1]
            
        if j==len(pattern):
            return i-len(pattern)
    
    return -1

#         0123456789
source = "----abcxxxabcy---------";
patt = "abcxxxabcy";

index = findPattern(source, patt)
print("Found pattern: "+patt+"  on index: "+str(index)+" in text: "+source) # Found pattern: abcxxxabcy  on index: 4


#         01234567890    
source = "123456yobanaV346563sdsdkhfhs"
pattern = "yobana"
index = findPattern(source, pattern)
print("Found pattern: "+pattern+"  on index: "+str(index)+" in text: "+source) # Found pattern: abcxxxabcy  on index: 6
