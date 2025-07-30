# String from array
array = ["Andrew", "Ben", "John", "Paul", "Peter", "Laura"]
joined = ", ".join(array)
print("String from Array: "+joined) # String from Array: Andrew, Ben, John, Paul, Peter, Laura

print(60*"-")

# Array from string
someStr = "super String with awesome TExt"
arr = someStr.split(" ")
print("Array from string: " + str(arr)) # Array from string: ['super', 'String', 'with', 'awesome', 'TExt']

print(60*"-")


# Split String
s="leetcode"
ss="leet"
print(s[:len(ss)]) # leet
print(s[len(ss):]) # code


s = "123"
i = 1
tra = int(s[i:i+2])  # This is int("23") => 23
