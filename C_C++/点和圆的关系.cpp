#include <iostream>
#include <string>
using namespace std;

class Dot
{
private:
	int d_x;
	int d_y;
public:
	void set_x(int x)
	{
		d_x = x;
	} 
	
	int get_x()
	{
		return d_x;
	}
	
	void set_y(int y)
	{
		d_y = y;
	}
	
	int get_y()
	{
		return d_y;
	}
}; 


class Circle
{
private:
	int c_r;
	Dot center;
	
public:
	void set_r(int r)
	{
		c_r = r;
	}
	
	int get_r()
	{
		return c_r;
	}
	
	void set_center(Dot d)
	{
		center = d;
	}
	
	Dot get_center()
	
};


int main()
{
	
	
	return 0;
}
