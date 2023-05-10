#include<bits/stdc++.h>

using namespace std;

double dist(pair<int,int> p1,pair<int,int> p2){
    int x1,x2,y1,y2;
    x1=p1.first;
    x2=p2.first;
    y1=p1.second;
    y2=p2.second;

    double d = pow((x2-x1),2) + pow((y2-y1),2);

    return pow(d,0.5);
}
//closest points
double closest(pair<int,int> p[],int left,int right){
    if(left==right)
        return INT_MAX;

    int center = (left+right)/2;
    double leftdist = closest(p,left,center);
    double rightdist = closest(p,center+1,right);

    //now cross dist
    pair<int,int> leftcord = p[center];
    for(int i = center;i>=left;i--){
        if(p[center].first == p[center-i].first && p[center].second > p[center-i].second){
            leftcord = p[center-i];
        }
    }

    pair<int,int> rightcord = p[center+1];
    for(int i = center+1;i<=right;i++){
        if(p[center+1].first == p[center+1+i].first && p[center+1].second > p[center+1+i].second){
            rightcord = p[center+1+i];
        }
    }

    double a = min(leftdist,rightdist);
    return min(a,dist(leftcord,rightcord));
}

int main(){

    pair<int,int> p[] = {{0,0},{2,1},{4,3},{10,9},{12,10},{14,9}};

    cout<<closest(p,0,5);
    return 0;
}
