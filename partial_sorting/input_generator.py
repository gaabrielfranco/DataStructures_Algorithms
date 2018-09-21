import random

file_10k = open("input/10K.txt", "w")
file_100k = open("input/100K.txt", "w")
file_1m = open("input/1M.txt", "w")

print("0 to 10K")
for i in range(0, 10000):
    number = random.randint(0, 2147483647)
    file_10k.write(str(number) + " ")
    file_100k.write(str(number) + " ")
    file_1m.write(str(number) + " ")

print("10K to 100K")
for i in range(10000, 100000):
    number = random.randint(0, 2147483647)
    file_100k.write(str(number) + " ")
    file_1m.write(str(number) + " ")

print("100K to 1M")
for i in range(100000, 1000000):
    number = random.randint(0, 2147483647)
    file_1m.write(str(number) + " ")

file_10k.close()
file_100k.close()
file_1m.close()
