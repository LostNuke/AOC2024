file = open('./input', 'r')

def check_line_without_number(nums, remove=None) -> bool:
    if remove is not None: nums.pop(remove)
    incdec = 0
    safe = True
    for index, num in enumerate(nums):
        if len(nums) == index+1: break
        diff = abs(int(num.replace("\n", "")) - int(nums[index+1].replace("\n", "")))
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

    return safe

safes = 0
for line in file:
    nums = line.replace("\n","").split(' ')
    safe = check_line_without_number(nums)
    if safe:
        safes += 1
        continue
    for index, num in enumerate(nums):
        safe =  check_line_without_number(nums.copy(), index)
        if safe:
            safes += 1
            break

print(safes)