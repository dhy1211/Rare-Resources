class Solution(object):
    def isValid(self, s):
        st = []
        for c in s :
            if c == "(" or c == "{" or c == "[" :
                st.append(c)
            else :
                if not st :
                    return False 
                if c == ')':
                    if st.pop() != '(': return False
                elif c == '}':
                    if st.pop() != '{': return False
                elif c == ']':
                    if st.pop() != '[': return False
                    
        return len(st) == 0