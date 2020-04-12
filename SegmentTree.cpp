#include <iostream>
#define MAX 10000000
int segmentIndex[MAX*10];
using namespace std;

void constructTree(int low, int high, int pos)
{
    if (low==high)
    {
        segmentIndex[pos] = 0
                ;
        return;
    }
    int mid = (low + high) / 2;
    constructTree(low,mid,2*pos+1);
    constructTree(mid+1,high,2*pos+2);
    segmentIndex[pos] = segmentIndex[2*pos+1] + segmentIndex[2*pos+2];
}

int search(int qlow, int qhigh, int low, int high, int pos)
{
    if (qlow > high || qhigh < low) return 0; // No overlap
    if (qlow <= low && qhigh >= high) return segmentIndex[pos];
    int mid = (low + high)/2;
    return search(qlow,qhigh,low,mid,2*pos+1) + search(qlow,qhigh,mid+1,high,2*pos+2);
}

void update(int low, int high, int pos, int index, int val)
{
    if (index>=low && index<=high)segmentIndex[pos]+=val;
    if (low == high)return;
    int mid = (low + high)/2;
    update(low, mid, 2*pos+1, index,val);
    update(mid+1,high,2*pos+2, index, val);
}


int main()
{
    int n;
    cin>>n;
    constructTree(0,MAX,0);

    int j,x;
    for (int i=0;i<n;i++)
    {
        cin>>j;
        if (j == 1)
        {
            cin>>x;
            update(0,MAX,0,x,1);
        }
        else if (j == 2)
        {
            cin>>x;
            cout<<search(0,x,0,MAX,0)<<endl;
        }
    }

    return 0;
}
