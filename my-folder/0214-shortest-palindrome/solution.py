class Solution:
    def shortestPalindrome(self, s: str) -> str:
        i=0
        while i<len(s):
            if s[0:len(s)-i] == s[0:len(s)-i][::-1]:
                break
            i+=1
        return s[len(s)-i:len(s)][::-1]+s       
