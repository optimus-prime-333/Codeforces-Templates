vector<ll>fact(200005),ifact(200005);
 
void precompute(){
    fact[0] = 1;
    ifact[0] = 1;
 
    for(int i = 1 ; i < 200000 ; i++){
        fact[i] = mod_mul(i , fact[i-1] , MOD);
    }
 
    for(int i = 1 ; i < 200000 ; i++){
        ifact[i] = expo(fact[i] , MOD-2 , MOD);
    }
    
}
int comb(int n , int r){
 
    if(r > n){
        return 0;
    }
 
    if(r==0 || r== n){
        return 1;
    }
 
    int ans = mod_mul(fact[n] , ifact[r] , MOD);
    ans = mod_mul(ans , ifact[n-r] , MOD);
 
    return ans;
}
