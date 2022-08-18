class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        d = dict()
        for x in arr:
            d[x] = d.get(x,0)+1
            
        d = sorted(d.values(),reverse=True)
        sumi = 0
        count = 0
        for y in d:
            sumi = sumi+y
            count += 1
            if sumi >= len(arr)/2:
                return count