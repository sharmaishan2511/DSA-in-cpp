#include<iostream>

using namespace std;

class bowler{
    private:
        int catchout;
        int lbw;
        int bowled;
    public:
        bowler(){
            cin>>catchout;
            cin>>lbw;
            cin>>bowled;
        }
        friend class allround;
};

class batsman{
    private:
        int fours;
        int sixes;
        int fifties;
        int hundreds;
    public:
        batsman(){
            cin>>fours;
            cin>>sixes;
            cin>>fifties;
            cin>>hundreds;
        }
        friend class allround;
};

class allround:public bowler,public batsman{
    int score;
    public:
        allround(){
            score = (catchout+2*lbw+3*bowled)+(fours+2*sixes+3*fifties+4*hundreds);
            cout<<score;
        }
};

int main(){
    allround a1;
    return 0;
}
