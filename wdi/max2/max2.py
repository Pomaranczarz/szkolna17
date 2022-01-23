from random import randint


nums = []
for i in range(100):
    nums.append(randint(0, 1000))

print(nums)

max1 = -1
max2 = -1
for num in nums:
    if num > max1:
        max1 = num
    elif num > max2 and num < max1:
        max2 = num

print(f'max1: { max1 }\nmax2: { max2 }')