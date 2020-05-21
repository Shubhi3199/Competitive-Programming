#include <bits/stdc++.h>
using namespace std;
void display(std::vector<int> v);
float square(float num);

void In_Out(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void display(std::vector<int> v){
	cout<<" [";
    for(auto item:v){
        cout<<" "<<item<<" ";
    }
    cout<<"] "<<endl;
}

float square(float num){
	return num*num;
}

float mySqrt(int n, int p){
	std::vector<int> v;
	for(size_t i = 0; i <= n ; i++){
		v.push_back(i);
	}
	// Here we have our vector ranging from 0 to n
	int first, last, mid;
	float inc, ans;
	int j = 1;
	first = 0;
	last = v.size() - 1;

	while(first <= last){
		mid = (first + last)/2;
		if(square(mid) == n){
			ans = mid;
			break;
		}else if(square(mid) > n){
			last = mid - 1;
		}else{
			first = mid + 1;
			ans = mid;
		}
	}

	while(j <= p){
		inc = pow(10, -(j));
		while(square(ans) < n){
			ans += inc;
		}
		ans -= inc;
		j++;
	}

	return ans;
}


int main(){
	In_Out();

	int n, p;
	cin>>n;
	cin>>p;
	cout<<mySqrt(n, p);
}