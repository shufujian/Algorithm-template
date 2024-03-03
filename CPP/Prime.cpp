/*
    埃氏筛 Eratosthenes
    在 O(n lglgn)内计算范围内的所有素数
*/

vector<int> prime;
vector<bool> is_prime(n+1, true);

void Eratosthenes(int n){
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            prime.push_back(i);
            for(int j=i*i;j<= n;j+=i){ // 2~i-1都筛选过了，1*i、2*i...、(i-1)*i都有i以前的数的因数，因此均判断过了
                is_prime[j]=false;
            }
        }
    }
}

/*
    欧拉筛 Euler
    在 O(n) 内计算范围内的所有素数
*/
vector<int> prime;
vector<bool> is_prime(n+1, true);

void Euler(int n){
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++){
        if(is_prime[i]) prime.push_back(i);
        for(int j=0;j<prime.size();j++){
            if(i*prime[j]>n) break;
            is_prime[i*prime[j]]=false;
            if(i%prime[j]==0) break; // i 是被 prime[j]筛掉的，则i的倍数一定会被 prime[j]的倍数筛掉，无需再进行重复的筛除
        }
    }
}