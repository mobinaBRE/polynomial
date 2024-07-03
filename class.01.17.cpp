#include <iostream>
using namespace std;
class polynominal {
	private:
		int num[101];
	public:
		friend bool operator==(polynominal a,polynominal b);
		friend polynominal operator+(polynominal a,polynominal b);
		friend polynominal operator-(polynominal a,polynominal b);
		friend polynominal operator*(polynominal a,polynominal b);
		friend polynominal operator+=(polynominal a,polynominal b);
		friend polynominal operator-=(polynominal a,polynominal b);

		polynominal() {
			for(int i=0; i<101; i++)
				num[i]=0;
		}
		void set(int zarib[],int tavan[],int n) {
			for(int i=0; i<n; i++) {
				num[tavan[i]]=zarib[i];
			}
		}
		void print() {
			int i,min;
			for(i=100; i>=0; i--) {
				if(num[i]!=0)
					min=i;
			}
			for( i=100; i>1; i--) {
				if(num[i]!=0) {
					if(num[i]!=1) {
						if(i!=min)
							cout<<num[i]<<"x^"<<i<<" + ";
						else
							cout<<num[i]<<"x^"<<i;
					} else {
						if(i!=min)
							cout<<"x^"<<i<<" + ";
						else
							cout<<"x^"<<i;
					}
				}
			}
			if(num[1]!=0) {
				if(num[0]!=0)
					cout<<num[i]<<"x + ";
				else
					cout<<num[i]<<"x";
			}

			if(num[0]!=0)
				cout<<num[0];
			cout<<endl;
		}
		polynominal operator=(polynominal b) {
			for(int i=0; i<101; i++) {
				num[i]=b.num[i];
			}
			return *this;
		}
};
polynominal operator+(polynominal a,polynominal b) {
	polynominal c;
	for(int i=0; i<101; i++) {
		c.num[i]=a.num[i]+b.num[i];
	}
	return c;
}
polynominal operator-(polynominal a,polynominal b) {
	polynominal c;
	for(int i=0; i<101; i++) {
		c.num[i]=a.num[i]-b.num[i];
	}
	return c;
}
polynominal operator*(polynominal a,polynominal b) {
	polynominal c;
	for(int i=0; i<101; i++) {
		for(int j=0; j<101; j++) {
			c.num[i+j]+=a.num[i]*b.num[j];
		}
	}
	return c;
}
polynominal operator-=(polynominal a,polynominal b) {
	for(int i=0; i<101; i++) {
		a.num[i]=a.num[i]-b.num[i];
	}
	return a;
}
polynominal operator+=(polynominal a,polynominal b) {
	for(int i=0; i<101; i++) {
		a.num[i]=a.num[i]+b.num[i];
	}
	return a;
}
bool operator==(polynominal a,polynominal b){
	
	for(int i=0;i<101;i++){
		if(a.num[i]!=b.num[i])
			return false;
	}
	return true;
}
int main() {
	int n,i;
	cout<<" n ? ";
	cin>>n;
	int num[n],pow[n];
	for(i=0; i<n; i++) {
		cout<<"zarib : ";
		cin>>num[i];
		cout<<"tavan : ";
		cin>>pow[i];
	}
	polynominal a,b,c;
	a.set(num,pow,n);
	cout<<" n ? ";
	cin>>n;
	for(i=0; i<n; i++) {
		cout<<"zarib : ";
		cin>>num[i];
		cout<<"tavan : ";
		cin>>pow[i];
	}
	b.set(num,pow,n);
menu:
	cout<<"which one ? \n 1)a*b  2)a+b  3)a-b  4)b-a \n";
	cin>>n;
	switch(n) {
		case 1:
			c=a*b;
			c.print();
			break;
		case 2:
			c=a+b;
			c.print();
			break;
		case 3:
			c=a-b;
			c.print();
			break;
		case 4:
			c=b-a;
			c.print();
			break;
	}
	cout<<"1)go to menu  2)exit : ";
	cin>>n;
	if(n==1)
		goto menu;
	else
		return 0;
}
