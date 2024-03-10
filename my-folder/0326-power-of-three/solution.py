class Solution:
    def isPowerOfThree(self, n: int) -> bool:
      if n<=0:
          return False
      elif log10(n) / log10(3) == int(log10(n) / log10(3)):
          return True
      else:
          return False
