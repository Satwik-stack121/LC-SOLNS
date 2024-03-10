class Solution:
    def isPalindrome(self, x: int) -> bool:
      l1=[]
      l2=[]
      joe=str(x)
      for i in range (0,len(joe)):
          l1.append(joe[i])
      for j in range(-1,-len(joe)-1,-1):
          l2.append(joe[j])

      if x<0:
          return False

      elif l1==l2:
          return True

      else:
          return False

            

