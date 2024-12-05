file = open('./input', 'r')
safes = 0
for line in file:
    nums = line.split(' ')
    incdec = 0
    safe = True
    for index, num in enumerate(nums):
        print(len(nums))
        print(index+1)
        if len(nums) == index+1: break
        diff = abs(int(num) - int(nums[index+1]))
        if 1 <= diff <= 3:
            if incdec == 0: incdec = int(num) - int(nums[index+1])
            elif incdec > 0: # Descending
                if not(int(num) - int(nums[index+1]) > 0):
                    safe = False
                    break
            elif incdec < 0:
                if not(int(num) - int(nums[index + 1]) < 0):
                    safe = False
                    break
        else:
            safe = False
            break
    if safe: safes += 1

print(safes)