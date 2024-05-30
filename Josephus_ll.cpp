#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val=0;
    Node* next=NULL; 
    Node(int user_data)
    {
        val = user_data;
    }
};
int main(){
    int n;
    cout<<"Enter number of people: ";
    cin>>n;
    Node* l = new Node(1);
    Node* head=l;
    for(int i=0;i<n;i++){
        if(i!=n-1){
            Node* l1 = new Node(i+2);
            l->next=l1;
            l=l->next;
        }
        else{
            l->next=head;
        }

    }
    int cnt=n;
    while(cnt!=1){
        cout<<"Person Killed: "<<head->next->val<<endl;
        head->next=head->next->next;
        head=head->next;
        cnt--;
    }
    cout<<"The Last person alive is: "<<head->val<<endl;
    return 0;
}