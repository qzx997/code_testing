#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e4 + 7;
const ll mod = 1e9 + 7;
#define pi atan(1.0)*4


/********************************����ĳ��ĳ��ĳ�������ڼ�*******************************************/  
int whatday(int y,int m,int d)
{
	int w;
	if(m<=2)
	{
		m+=12;
		y--;
	}
	w = (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;   //w Ϊ��ʽ��w+1 Ϊ���ڵ����� 
	return w;
}

/*******************************�������е�ȫ����****************************************/  
void permutation(int *a, int len)
{
	do{
        for(int i = 0; i < len; i ++) {
            printf("%d%c",a[i],(i==len-1)?'\n':' '); 
        }
    }while(next_permutation(a,a+len));	//ȫ���е����ú��� 
}


/****************************��̬�滮���������******************************************/ 
ll f[maxn][maxn];
void init()
{
	for(int i=1;i<maxn;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if( j == 1)
			{
				f[i][j] = 1;
			}
			else 
			{
				f[i][j] = f[i-1][j-1] + f[i-1][j];
			}
		}
	}
} 


/**********************************���鼯******************************************/ 
int fa[maxn];
void init()
{
	for(int i=1;i<=n;i++) fa[i] = i,sum[i] = 1;
}

int get(int x)
{
	if(x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}

void merge(int x,int y)
{
	x = get(x), y = get(y);
	if(x != y)
	{
		fa[y] = x;
		sum[x] += sum[y];
	}
}


/*********************************���ٳ��������*********************************************/
//a^b
ll ksm(ll a,ll b)
{
	ll ans = 1,base = a;
	while(b!=0)
	{
		if(b & 1 != 0)
		{
			ans = (ans * base) % mod;
		}
		base = (base * base) % mod;
		b >>= 1;
	}
	return ans;
}

//a*b
ll ksc(ll a,ll b)
{
	ll ans = 0;
	while(b != 0)
	{
		if(b & 1 != 0 )
		{
			ans = (ans + a) % mod;
		}
		a = (a + a) % mod;
		b >>= 1;
	}
	return ans;
}



/****************************************����ȡģ*******************************************************/ 
ll mod_fractional(ll m, ll n)
{
	return (ksm(n,m)-1) * ksm(ksm(n,m),mod-2) % mod;
}


/****************************************����ת��********************************************************/
ll change1(int r,string s) // r -> 10
{
	ll len = 0,ans = 0;
	while(s.length() != len)
	{
		ans = ans * r;
		if(s[len] >= 'A' && s[len] <= 'Z') ans += s[len] - 'A' + 10;
		else ans += s[len] - '0';
		len ++;
	}
	return ans;
}

void change2(int r,ll x) // x -> r
{
	stack<int> p;
	if(x == 0) p.push(x);
	while(x)
	{
		p.push(x%r);
		x /= r;
	}
	while(!p.empty())
	{
		switch(p.top())
		{
			case 10:cout << 'A' ; break;//��vector ����ÿ�δ�ֵ������ٴ�� 
			case 11:cout << 'B' ; break;
			case 12:cout << 'C' ; break;
			case 13:cout << 'D' ; break;
			case 14:cout << 'E' ; break;
			case 15:cout << 'F' ; break;
			default:cout << p.top() ; break;
		}
		p.pop();
	}
	cout << endl;
}

void change3(int r,string s,int k) //s :  r -> k
{
	ll temp = change1(r,s);
	change2(k,temp);
}


/*********************************************շת����������Լ��*********************************/ 
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b); //շת��� 
}

ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}


/***********************************������д*********************************/ 
//�������� 
inline int read() 
{
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') 
	{
		if(c == '-') f = -1; 
		c = getchar();
	}
    while(c >= '0' && c <= '9') 
		x = x * 10 + c - '0', c = getchar();
		
    return x * f;
}

//������� 
template <class T>
void write(T x)
{
    if(x < 0)
        x = -x, putchar('-');
    if(x >= 10)
        write(x / 10);
    putchar('0' + x % 10);
}


/*********************************쳲��������п��ٵ��Ʒ�**************************************/ 
ll fibonacci(ll n)
{
	ll a=1, b=1, t=0;
	for(i=3;i<n;i++)
	{
		t = a;
		a = a + b;
		b = t;
	}
	return a;
}




