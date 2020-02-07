

0 (sqrt n )

    vector<int> factorize(int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        res.push_back(n);
    }
    return res;
}




o(logn) //spf method

int minPrime[n + 1];

for (int i = 2; i * i <= n; ++i) {
    if (minPrime[i] == 0) {         //If i is prime
        for (int j = i * i; j <= n; j += i) {
            if (minPrime[j] == 0) {
                minPrime[j] = i;
            }
        }
    }
}
for (int i = 2; i <= n; ++i) {
    if (minPrime[i] == 0) {
        minPrime[i] = i;
    }
}




vector<int> factorize(int n) {
    vector<int> res;
    while (n != 1) {
        res.push_back(minPrime[n]);
        n /= minPrime[n];
    }
    return res;
}




Regarding the number of divisors, a useful thing for programming contests is to search OEIS for "1344 maximal divisors", or just memorize the sequence numbers for the maximal number of divisors and also the smallest and largest n-digit integers that have the appropriate number of divisors. The two latter sequences are sometimes useful in test cases.

The number is 1344 for integers up to 109 and 103 680 for integers up to 1018.
vector<int> divisors(int n) 
{ 
    vector<int> v;
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i) 
                v.push_back(i);
            else 
                v.push_back(i),v.push_back(n/i); 
        } 
    } 
    return v;
} 











    


/// now to get all the possible divisiors

vector<int> pfa = factorise(k);

sort(pfa.begin(),pfa.end());

vector<int> factors;
vector<int> exponents ;


for(int i = 0 ;i<pfa.size() ;i++)
{   
    //cout<<"pa"<<pfa[i]<<endl;
    if(!factors.empty() && factors.back() == pfa[i])
       exponents.back() = exponents.back()+1;
    else{

    factors.push_back(pfa[i]);
    exponents.push_back(1);
    }
      //  cout<<factors.back()<<"as"<<endl;

}

//cout<<exponents[0]<<endl;

int r = factors.size();
vector<int> ans; 
int factors_count = 1;
for (int i = 0; i < r; ++i)
{
    factors_count *= 1+exponents[i];
}

ans.resize(factors_count);
ans[0] = 1;
int count = 1;
for (int stack_level = 0; stack_level < r; ++stack_level)
{
    const int count_so_far = count;
    const int prime = factors[stack_level];
    const int exponent = exponents[stack_level];
    int multiplier = 1;
    for (int j = 0; j < exponent; ++j)
    {
        multiplier *= prime;
        for (int i = 0; i < count_so_far; ++i)
        {
            ans[count++] = ans[i] * multiplier;
        }
    }
}

