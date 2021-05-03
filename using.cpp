/*
You are provided an array of numbers. You need to arrange them in a way that yields the largest value.

Input Format
First line contains integer t which is number of test case.
For each test case, you are given a single integer n in the first line which is the size of array A[] and next line contains n space separated integers denoting the elements 
of the array A .

Constraints
1<=t<=100

1<=m<=100

1<=A[i]<=10^5

Output Format
Print the largest value.

Sample Input
1
4
54 546 548 60

Sample Output
6054854654

Explanation
Upon rearranging the elements of the array , 6054854654 is the largest possible number that can be generated.
*/
#include<iostream>
#include<cmath>
using namespace std;

int countDigits(int no)
{
    int count = 0;
    while (no != 0)
    {
        count ++;
        no = no/10;
    }
    return count;
}

int main()
{
    int t;
    int arr[100] = {0};
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        
        // like bubble sort
        for (int i = 0; i <= n-2 ; i++)
        {
            for (int j = 0; j <= n-2; j++)
            {
                int a = arr[j];
                int b = arr[j+1];
                int digit_count_a = countDigits(a);
                int digit_count_b = countDigits(b);

                long long int no1 = a*pow(10, digit_count_b) + b; //check karne ke liye ki kaun sa combination jyada bada number banayega
                long long int no2 = b*pow(10, digit_count_a) + a;
                if (no1 > no2)
                {
                    swap(arr[j], arr[j+1]); //jo bada number banata hoga vo peeche jaata jaayega aur array ko peeche se print karna shuru karenge
                }
            }   
        }
        // printing number
        for (int i = n-1; i >= 0; i--)
        {
            cout<<arr[i];
        } 
		cout<<endl;
    }
    return 0;
}
