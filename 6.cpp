#include <iostream>
#include <vector>
using namespace std;
void print_route(int n, vector<vector<int>> &via, vector<vector<int>> &dist);
int main()
{
    int n, i, j, k, count;

    cout << "Enter the number of nodes: ";
    cin >> n;
    vector<vector<int>> dmat(n, vector<int>(n)), dist(n, vector<int>(n)), via(n, vector<int>(n));
    cout << "Enter the cost matrix:" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> dmat[i][j];
            if (i == j)
            {
                dmat[i][j] = 0; 
            }
            dist[i][j] = dmat[i][j]; 
                via[i][j] = j; 
        }
    }
    do
    {
        count = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                for (k = 0; k < n; k++)
                {
                    if (dist[i][j] > dmat[i][k] + dist[k][j])
                    {
                        dist[i][j] = dmat[i][k] + dist[k][j];
                        via[i][j] = k;
                        count++;
                    }
                }
            }
        }
    } while (count != 0); 
    print_route(n, via, dist);
    return 0;
}
void print_route(int n, vector<vector<int>> &via,
                 vector<vector<int>> &dist)
{
    for (int i = 0; i < n; i++)
    {
        cout << "State value for router " << i << ":" << endl;
        for (int j = 0; j < n; j++)
        {
            cout << "To " << j << " - Via " << via[i][j] << "Distance is " << dist[i][j] << endl;
        }

    }
}