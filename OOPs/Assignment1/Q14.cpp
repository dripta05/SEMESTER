#include <iostream>
#include <vector>
using namespace std;
void disp_vec(vector<int> v)
{
    cout<<"The elements of the vector = ";
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
}
void disp_vec_matrix(vector<vector<int>> v)
{
    cout<<"The elements of the matrix = ";
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[0].size();j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    int n;
    vector<int> v;
    cout<<"Enter the no of elements = ";
    cin>>n;
    cout<<"Enter the elements of the vector = ";
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    disp_vec(v);
    int row,column;
    cout<<endl<<"Enter the row and column = ";
    cin>>row>>column;
    vector<vector<int>> matrix(row,vector<int> (column));
    cout<<"Enter the elements of the matrix = ";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++){
            cin>> matrix[i][j];
        }
    }
    disp_vec_matrix(matrix);
}
