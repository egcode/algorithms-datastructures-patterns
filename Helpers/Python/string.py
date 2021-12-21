# String from array
array = ["Andrew", "Ben", "John", "Paul", "Peter", "Laura"]
joined = ", ".join(array)
print("String from Array: "+joined)

print(60*"-")

# Array from string
someStr = "super String with awesome TExt"
arr = someStr.split(" ")
print("Array from string: " + str(arr))

print(60*"-")

# Sort string
some_str = "defbgca"
str_sorted="".join(sorted(some_str))
print("Sorted string: " + str_sorted)

print(60*"-")


# Split String
s="leetcode"
ss="leet"
print(s[:len(ss)])
print(s[len(ss):])
