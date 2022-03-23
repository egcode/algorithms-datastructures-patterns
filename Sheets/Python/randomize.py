import random

# Random integer
print("Random: "+str(random.random())) # Random: 0.6473964248353792
print("Random integer: "+str(random.randint(3, 9))) # Random integer: 7

# Random Dictionary element
d={"one": 1, "two":2, "three":3, "four":4}
print(random.choice(list(d.values()))) # 2


# #### Random Element in array
foo = ['a', 'b', 'c', 'd', 'e']
print(random.choice(foo)) # d
