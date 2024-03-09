class Solution:
    def romanToInt(self, s: str) -> int:
        output=0
        for i in range(len(s)):
            if s[i] == "I":
                output+=1
            elif s[i] == "V":
                if i-1 == -1:
                    output+=5
                elif s[i-1] == "I":
                    output+=3
                else:
                    output+=5
            elif s[i] == "X":
                if i-1 == -1:
                    output+=10
                elif s[i-1] == "I":
                    output+=8
                else:
                    output+=10
            elif s[i] == "L":
                if i-1 == -1:
                    output+=50
                elif s[i-1] == "X":
                    output+=30
                else:
                    output+=50
            elif s[i] == "C":
                if i-1 == -1:
                    output+=100
                elif s[i-1] == "X":
                    output+=80
                else: 
                    output+=100

            elif s[i] == "D":
                if i-1==-1:
                    output+=500
                elif s[i-1] == "C":
                    output+=300
                else:
                    output+=500
            elif s[i] == "M":
                if i-1 == -1:
                    output+=1000
                elif s[i-1] == "C":
                    output+=800
                else:
                    output+=1000
  
        return output
