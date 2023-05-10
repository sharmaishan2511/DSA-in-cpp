#include<bits/stdc++.h>

using namespace std;

class huffmantreenode{
public:
    char ch;
    int freq;

    huffmantreenode *left;
    huffmantreenode *right;

    huffmantreenode(char c,int f){
        ch = c;
        freq = f;
        left=right = NULL;
    }
};

class Compare {
public:
    bool operator()(huffmantreenode* a, huffmantreenode* b){
        return (a->freq >= b->freq);
    }
};

huffmantreenode *createtree(priority_queue<huffmantreenode *,vector<huffmantreenode*>,Compare> pq){
    while(pq.size() != 1){
        huffmantreenode *left = pq.top();
        pq.pop();

        huffmantreenode *right = pq.top();
        pq.pop();

        huffmantreenode *n = new huffmantreenode('$',left->freq + right->freq);

        n->left = left;
        n->right = right;

        pq.push(n);
    }

    return pq.top();
}

void printcodes(huffmantreenode *root,int arr[],int top){
    if(root->left){
        arr[top] = 0;
        printcodes(root->left,arr,top+1);
    }

    if(root->right){
        arr[top] = 1;
        printcodes(root->right,arr,top+1);
    }

    if(!root->left && !root->right){
        cout<<root->ch<< " ";
        for(int i = 0;i<top;i++){
            cout<<arr[i];
        }
        cout<<endl;
    }
}


void codes(char charr[],int freq[],int siz){
    priority_queue<huffmantreenode *,vector<huffmantreenode *>,Compare> pq;

    for(int i = 0;i<siz;i++){
        huffmantreenode *nn = new huffmantreenode(charr[i],freq[i]);
        pq.push(nn);
    }

    huffmantreenode *root = createtree(pq);

    int arr[100],top = 0;
    printcodes(root,arr,top);
}



int main(){

    char data[] = {'a','e','i','s','t','p','n'};
    int freq[] = {10,15,12,3,4,13,1};
    int n = sizeof(data)/sizeof(data[0]);

    codes(data,freq,n);
    return 0;
}
