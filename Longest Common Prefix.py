#tiền tố phổ biến Longest Common Prefix
class Solution(object):
    def longestCommonPrefix(self, strs):
        if not strs:
            return ""
        nums = strs[0]
        for work in strs[1:]:
            while not work.startswith(nums):
                nums = nums[:-1]
                if not nums:
                    return ""
        return nums  
#phương pháp 2
class Solution(object):    
    def longestCommonPrefix(self, strs):
        if not strs:
            return ""
        for i in range(len(strs[0])):
            char = strs[0][i]
            for work in strs[1:]:
                if i == len(work) or work[i] != char:
                    return strs[0][:i]
        return strs[0]