
# Problem link - https://leetcode.com/problems/delete-columns-to-make-sorted/description/?envType=daily-question&envId=2025-12-20

from typing import List

def minDeletionSize(strs: List[str]) -> int:
	# get size of list of string
	n = len(strs)
	
	# get size of each string
	k = len(strs[0])
	
	# step 1 - iterate on each letter of string list
	count = 0
	for i in range(k):
		for j in range(1,n):
			# step 2 - check if current letter is less than previous letter of word
			if strs[j][i] < strs[j-1][i]:
				# increment count and break
				count += 1
				break
	
	# step 3 - return number of columns that you will delete
	return count

# strs = ["cba","daf","ghi"]

# strs = ["a","b"]

strs = ["zyx","wvu","tsr"]
print(minDeletionSize(strs))