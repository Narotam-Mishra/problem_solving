
# Problem link - https://leetcode.com/problems/apple-redistribution-into-boxes/?envType=daily-question&envId=2025-12-24

from typing import List

def minimumBoxes(apple: List[int], capacity: List[int]) -> int:
    # step 1 - sort capacity in descending order
    capacity.sort(reverse=True)

    # step 2 - find sum of all apples
    apples_sum = 0
    for a in apple:
        apples_sum += a

    # step 3 - start distributing apples starting from largest box
    # and maintain box count 
    box_count = 0
    curr_apples = 0
    for cap in capacity:
        curr_apples += cap
        box_count += 1
        if curr_apples >= apples_sum:
            return box_count
    return box_count
    
# apple = [1,3,2]
# capacity = [4,3,1,5,2]

apple = [5,5,5]
capacity = [2,4,2,7]
print(minimumBoxes(apple, capacity))