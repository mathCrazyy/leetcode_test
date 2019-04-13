"""
求解整数x的n次方
"""
class Solution:
    def resolve(self,x:int,n:int)->float:
        """
        calculate the power of base, i.e x**n
        :param x:
        :param n:
        :return:
        """
        pass
        return 4
    def resolve_2(self,x:float,n:int)->float:
        if(int(x)==2):
            return float(1<<n)
        if (n==0):
            return 1
        if(n==1):
            return x
        res = self.resolve_2(x, n // 2)
        if n%2==0:
            return res*res
        else:
            return x*res*res

    def resolve_3(self,x:float,n:int)->float:
        return x*self.resolve_3(x,n//2)*self.resolve_3(x,n//2) if n%2 else self.resolve_3(x,n//2)*self.resolve_3(x,n//2)