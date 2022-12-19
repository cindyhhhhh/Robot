#include <stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <stdint.h>
#include <iostream> 
#include <inttypes.h>
#include<string.h>
#include<vector>

using namespace std;

int PairNumber(int n, int k, vector<long long> candy, vector<long long> prefixsum, long long&Pair)
{
	if (n == 1)
	{
		return 0;
	}
	if (n == 2)
	{
		Pair = Pair + 1;
		return 0;
	}

	int mid = n/2;
	vector<long long> Left;
	vector<long long> Right;
	vector<long long> SumLeft;
	vector<long long> SumRight;

	Left.assign(candy.begin(), candy.begin()+mid);
    Right.assign(candy.begin()+mid, candy.end());

    SumLeft.assign(prefixsum.begin(), prefixsum.begin()+mid+1);
    SumRight.assign(prefixsum.begin()+mid, prefixsum.end());

    long long maxl;
    long long minl;

    long long maxr;
    long long minr;

    long long index = 0;
    long long mod = 0;
    int j;

//case1 : max left min left從左右往中間
    vector<int> ModLeft1(k, 0);

	maxl = Left[Left.size()-1];
	minl = Left[Left.size()-1];

	j = 0;

	for(int i = 2; i <= Left.size(); i++)
    {
    	if(Left[Left.size()-i] > maxl)
    	{
    		maxl = Left[Left.size()-i];
    	}
    	if(Left[Left.size()-i] < minl)
    	{
    		minl = Left[Left.size()-i];
    	}
    	mod = (SumLeft[SumLeft.size()-i-1] + maxl + minl)%k;    		

        while(maxl > Right[j] && minl < Right[j] && j < Right.size())
        {
        	index = SumRight[j + 1] % k;
        	ModLeft1[index] = ModLeft1[index] + 1;
        	j++;
        }

        Pair = Pair + ModLeft1[mod];
    }

    //case2: max right min right
    vector<int> ModRight1(k, 0);

	maxr = Right[0];
	minr = Right[0];

    j = 1;

	for(int i = 1; i < Right.size(); i++)
    {
    	if(Right[i] > maxr)
    	{
    		maxr = Right[i];
    	}
    	if(Right[i] < minr)
    	{
    		minr = Right[i];
    	}
    	mod = (SumRight[i + 1] - maxr - minr) % k;

        while(maxr > Left[Left.size()-j] && minr < Left[Left.size()-j] && j <= Left.size())
        {
	    	index = SumLeft[SumLeft.size()-j-1]%k;
        	
        	ModRight1[index] = ModRight1[index] + 1;
        	j++;
        }
        Pair = Pair + ModRight1[mod];
    }

	//case3 : max left min right
    vector<int> ModLeft2(k, 0);
    maxl = Left[Left.size()-1];
    minl = Left[Left.size()-1];

    maxr = Right[0];
    minr = Right[0];

	j = 0;

	for(int i = 1; i <= Left.size(); i++)
    {
    	if(Left[Left.size()-i] > maxl)
    	{
    		maxl = Left[Left.size()-i];
    	}
    	else if(Left[Left.size()-i] < minl)
    	{
    		minl = Left[Left.size()-i];
    	}
    	mod = (SumLeft[SumLeft.size()-i-1] + maxl)%k;    		

        while(maxl > maxr && minr < minl && j < Right.size())
        {
        	index = (SumRight[j + 1] - minr) % k;
        	ModLeft2[index] = ModLeft2[index] + 1;
        	j++;
        	if(Right[j] > maxr)
	    	{
	    		maxr = Right[j];
	    	}
	    	else if(Right[j] < minr)
	    	{
	    		minr = Right[j];
	    	}
        }
        Pair = Pair + ModLeft2[mod];
    }

    //case4 : max right min left
    vector<int> ModRight2(k ,0);
    maxl = Left[Left.size()-1];
    minl = Left[Left.size()-1];

    maxr = Right[0];
    minr = Right[0];


	j = 1;

	for(int i = 0; i < Right.size(); ++i)
    {
    	if(Right[i] > maxr)
    	{
    		maxr = Right[i];
    	}
    	else if(Right[i] < minr)
    	{
    		minr = Right[i];
    	}

    	mod = (SumRight[i + 1] - maxr) % k;

        while(maxr > maxl && minl < minr && j <= Left.size())
        {
	    	index = (SumLeft[SumLeft.size()-j-1] + minl)%k;
        	
        	ModRight2[index] = ModRight2[index] + 1;
        	j++;
        	if(Left[Left.size()-j] > maxl)
	    	{
	    		maxl = Left[Left.size()-j];
	    	}
	    	else if(Left[Left.size()-j] < minl)
	    	{
	    		minl = Left[Left.size()-j];
	    	}
        }
        Pair = Pair + ModRight2[mod];
    }

    PairNumber(Left.size(), k, Left, SumLeft, Pair);
    PairNumber(Right.size(), k, Right, SumRight, Pair);
    return 0;
}



int main()
{
	int N, K;
	cin >> N;
	cin >> K;

	vector<long long> Candy;
	long long temp;
	for(int i = 0; i < N; ++i)
    {
    	cin >> temp;
    	Candy.push_back(temp);
    }

    long long Pair = 0;
    vector<long long> prefixsum(N+1, 0);

	prefixsum[0] = 0;
	for (int i = 1; i < N + 1; ++i)
	{
		prefixsum[i] = prefixsum[i-1] + Candy[i-1];
	}

    PairNumber(N, K, Candy, prefixsum, Pair);
    printf("%lld", Pair);
    return 0;
}