#include <string>
#include <vector>

using namespace std;

int visited[501][501] = {0, };

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int max = 0;

    visited[0][0] = triangle[0][0];

    for (int i=0; i<triangle.size()-1; i++)
    {
        for (int j=0; j<i+1; j++)
        {
            if (visited[i][j]+triangle[i+1][j]>visited[i+1][j])
                visited[i+1][j] = visited[i][j]+triangle[i+1][j];
            if (visited[i][j]+triangle[i+1][j+1]>visited[i+1][j+1])
                visited[i+1][j+1] = visited[i][j]+triangle[i+1][j+1];
        }
    }

    for (int i=0; i<triangle.size(); i++)
    {
        if (max<visited[triangle.size()-1][i])
            max = visited[triangle.size()-1][i];
    }

    return max;
}