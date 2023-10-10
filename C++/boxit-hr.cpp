#include<bits/stdc++.h>

using namespace std;

class Box{
    int l,b,h;
public:
    Box() : l(0), b(0), h(0) {}
    Box(int l, int b, int h) : l(l), b(b), h(h) {}
    Box(const Box &B) : l(B.l), b(B.b), h(B.h) {};
    
    int getLength(){
        return l;
    }
    
    int getBreadth(){
        return b;
    }
    
    int getHeight() {
        return h;
    }
    
    long long CalculateVolume() {
    return static_cast<long long>(l) * b * h;
}
    
    bool operator<(Box const &obj){
        bool ans = false;
        if (l < obj.l) ans = true;
        if (b < obj.b && l == obj.l) ans = true;
        if  (h < obj.h && b == obj.b && l == obj.l) ans = true; 
        return ans;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Box& box) {
        os << box.l << " " << box.b << " " << box.h;
        return os;}
};



void check2()
{
	int n; //number of commands
	cin>>n;
	Box temp; //initially the valye of temp is 0,0,0
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1) //outputs 0 0 0 for default constructor's l = b = h = 0
		{
			cout<<temp<<endl;
		}
		if(type == 2) 
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h); //outputs inputted l,b,h
			temp=NewBox; //updates the value of temp
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h); //compares the newly created box to the current value of the temp box
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp); //copy constructor
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}