#include <iostream>
using namespace std;
int main()
{
    int testCases;
    cin>>testCases;

    while(testCases--)
    {
        int n;
        cin>>n;
        int arr[n];

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        int maximum = 0;
        int secondMaximum = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>maximum)
            {
                secondMaximum = maximum;
                maximum = arr[i];
            }
            else if(arr[i]>secondMaximum)
            {
                secondMaximum = arr[i];
            }
        }

        for(int i = 0;i<n;i++)
        {
            if(arr[i]==maximum)
            {
                cout<<arr[i]-secondMaximum<<" ";
            }
            else
            {
                cout<<arr[i]-maximum<<" ";
            }
        }
        cout<<endl;
    }
}
