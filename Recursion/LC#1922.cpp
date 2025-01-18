class Solution {
    const int mod = 1e9+7;
public:
    long long solve(long long x,long long n){
        if(n==0)
        return 1;
        if(n%2==0){
            return solve((x*x)%mod,n/2);
        }
        else{
            return x*solve(x,n-1)%mod;
        }
    }
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = (n/2) + (n%2);
        long long first = solve(5,even);
        long long second = solve(4,odd);
        return (first*second)%mod;
    }
};

/*
Intuition - Even possibilities - 5 {0,2,4,6,8}
            Prime possibilities - 4 {2,3,5,7}
            
        Odd places - prime - n/2
        Even places - Even - n/2 + n%2
        
        
        Eg: n = 5
        
        5 4 5 4 5 => 5^even * 4^odd
        
        Implemented power calculation gives the optimal approach because of long long and int overflow.
        If n is even, the implemented solution is given as follows:
        
        x^n = x^n/2 * x^n/2 when n is even => (x*x)^n/2
        
        For odd n, above trick does not work, so x*solve(x,n-1) which will make n even, making it to implement above technique.
        
        mod is done at most places for avoiding overflow...
