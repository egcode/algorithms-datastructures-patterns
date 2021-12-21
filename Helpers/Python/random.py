import random

# Random integer
print("Random: "+str(random.random()))
print("Random integer: "+str(random.randint(3, 9)))

# Random Dictionary element
d={"one": 1, "two":2, "three":3, "four":4}
print(random.choice(list(d.values())))


# #### Random Element in array
foo = ['a', 'b', 'c', 'd', 'e']
print(random.choice(foo))
