
def arrayPairSum(nums: list[int]) -> int:
    # store maximum sum of minimums in `maxSum`
    max_sum = 0

    # step 1: Sort the array to group similar values together
    nums.sort()

    # iterate of array's number
    # we take elements at even indices (0, 2, 4, ...) because after sorting,
    # these will be the minimum values in each optimal pair
    for i in range(0, len(nums), 2):
        # step 3 - calculate the sum
        max_sum += nums[i]
    
    # step 4 - return maximum sum of minimums in `maxSum`
    return max_sum

# nums = [1,4,3,2]

nums = [6,2,6,5,1,2]
print(arrayPairSum(nums))

