import random

file_1m = open("1M.txt", "w")
file_10m = open("10M.txt", "w")
file_100m = open("100M.txt", "w")
print("0 to 1M")
for i in range(0, 1000000):
    number = random.randint(0, 2147483647)
    file_1m.write(str(number) + " ")
    file_10m.write(str(number) + " ")
    file_100m.write(str(number) + " ")

print("1M to 10M")
for i in range(1000000, 10000000):
    number = random.randint(0, 2147483647)
    file_10m.write(str(number) + " ")
    file_100m.write(str(number) + " ")

print("10M to 100M")
for i in range(10000000, 100000000):
    number = random.randint(0, 2147483647)
    file_100m.write(str(number) + " ")

file_1m.close()
file_10m.close()
file_100m.close()
