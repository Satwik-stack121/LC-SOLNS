class Solution:
    def isPowerOfFour(self, n: int) -> bool:

      if n<=0:
          return False
      elif log10(n) / log10(4) == int(log10(n) / log10(4)):
          return True
      else:
          return False       
