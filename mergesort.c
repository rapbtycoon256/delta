#include<stdio.h>
#define N 100
void mergesort(int arr[], int n);
int main()
{
    int n, arr[N];
    printf("Enter Size Of Array:\t");
    scanf("%d",&n);
    printf("Enter The Elements:\n");
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    mergesort(arr, n);
    printf("The Sorted Elements:\n");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    return 0;
}
void mergesort(int arr[], int n)
{
    int mid=n/2;
    if(mid==0)  return;
    int lefp[n], rigp[n];
    for(int i=0; i<mid; i++)
        lefp[i]=arr[i];
    for(int i=0; i<n-mid; i++)
        rigp[i]=arr[mid+i];
    mergesort(lefp,mid);
    mergesort(rigp,n-mid);
    int lefdex=0, rigdex=0;
    for(int i=0; i<n; i++)
    {
        if(lefp[lefdex]<rigp[rigdex])
        {
            arr[i]=lefp[lefdex];
            lefdex++;
            if(lefdex==mid)
            {
                for(int j=i+1; j<n; j++)
                {
                    arr[j]=rigp[rigdex++];
                    if(rigdex==n-mid)   break;
                }
                break;
            }
        }
        else
        {
            arr[i]=rigp[i];
            rigdex++;
            if(rigdex==n-mid)
            {
                for(int j=i+1; j<n; j++)
                {
                    arr[j]=lefp[lefdex++];
                    if(lefdex==n-mid)   break;
                }
                break;
            }
        }
    }
}
