class Solution(object):
    def isPalindrome(self, x):
        if x < 0 or ( x%10==0 and x!=0 ):
            return False 
        
        reversed_S = 0 
        dic = x
        while x > 0 :
            nums = x % 10 
            reversed_S = reversed_S * 10 + nums
            x = x // 10 
        
        return dic == reversed_S 
