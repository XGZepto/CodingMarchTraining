#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

long long fac[2001],inv[2001],fac_inv[2001];

int permutation(int n,int m,int p){
	return 1ll * fac[n] * fac_inv[m] % p;
}

int main(){
	int p,q;
	cin >> q >> p;
	fac[0] = 1;
	fac[1] = 1;
	for (int i=2;i<=2000;i++){
		fac[i] = 1ll * fac[i-1] * i % p;
	}
	inv[0] = 1;
	inv[1] = 1;
	for (int i=2;i<=2000;i++){
		inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
	}
	fac_inv[0] = 1;
	fac_inv[1] = 1;
	for (int i=2;i<=2000;i++){
		fac_inv[i] = 1ll * fac_inv[i-1] * inv[i] % p;
	}
	//cout << fac[10] << " " << fac_inv[3];
	for (int i=0;i<q;i++){
		int n,m;
		cin >> n >> m;
		cout << permutation(n,m,p) << endl;
	}
}