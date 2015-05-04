#include <iostream>
#include <fstream>
using namespace std;
int n,N,C;
void func(){

}
int main()
{
	fstream in("data.txt");
	in>>n;
	for(int i=0;i!=n;++i){
		in>>N>>C;
		func();
	}
	return 0;
}

