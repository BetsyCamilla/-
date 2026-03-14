#include<iostream>
using namespace std;

int main(){
    int d2 = (1<<31)-1;
    int d0 = 10;
    long l2 = ((long)1<<31)-1;
    long l0 = 10;
    long long ll2 = ((long long)1<<63)-1;
    long long ll0 = 10;

    for(int i = 0; i<8; i++) d0*=10;//即10^9
    for(int i = 0; i<8; i++) l0*=10;//即10^9
    for(int i = 0; i<17; i++) ll0*=10;//即10^18    

    cout<< d2 << "  (int的最大值)" <<endl;
    cout<< d0 << "  (对应10^9)" <<endl;
    cout<< l2 << "  (long的最大值)" <<endl;
    cout<< l0 << "  (对应10^9)" <<endl;
    cout<< ll2 << "  (long long的最大值)" <<endl;
    cout<< ll0 << "  (对应10^18)" <<endl;
    return 0;
}
