
# Problem link :- https://leetcode.com/problems/flipping-an-image/description/?envType=problem-list-v2&envId=bit-manipulation

from typing import List

def flipAndInvertImage(image: List[List[int]]) -> List[List[int]]:
    # iterate through each row of the matrix
    for row in image:
        # start and end pointers for the row
        left, right = 0, len(row) - 1  
        
        # swap and invert simultaneously
        while left <= right:
            # XOR operation to invert the values
            row[left], row[right] = row[right] ^ 1, row[left] ^ 1
            
            # move pointers towards the center
            left += 1
            right -= 1
    # return the modified image       
    return image  

image = [[1,1,0],[1,0,1],[0,0,0]]
print(flipAndInvertImage(image))