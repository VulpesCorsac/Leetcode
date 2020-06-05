class Solution:
  def checkIfExist(self, arr: List[int]) -> bool:
    s = collections.Counter(arr)
    
    if(s[0] > 1): 
        return True
    
    for num in arr:
      if num and s[2*num]:
        return True
        
    return False