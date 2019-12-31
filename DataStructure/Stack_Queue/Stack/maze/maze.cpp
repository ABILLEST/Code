#include <iostream>
#include <vector>
using namespace std;
#include <cstring>

class Solution
{
	public:
		bool hasPath(char* matrix, int rows, int cols,
			 int startX,int startY, int endX, int endY,vector<int>& Path);
		

		/*�˺��������ж��ڵ�ǰ·�����������£����ڸ������Ƿ����һ��������������*/
		bool hasPathCore(char* matrix, int rows, int cols, int row, 
			int col, int endX, int endY, bool* visited, vector<int>& Path)
		{
			//ͬʱ���� �����յ�����
			if ((row == endX) && (col == endY)&&(matrix[row*cols+col]=='1')) 
			{
				Path.push_back(endY); //path����� ��һ��vector
				Path.push_back(endX);
				return true;
			}
			bool hasPath = false;
			if (row >= 0 && row < rows&&col >= 0 && col < cols&&matrix[row*cols + col] == '1' 
				&& !visited[row*cols + col]) //visited?  visited��ֹ�߹����ٷ��������if���Σ�
			{
				//++pathLength;
				visited[row*cols + col] = true;
				Path.push_back(col);
				Path.push_back(row);
				/*����������(row,col)�ַ�Ϊ1ʱ��������4�����ڸ�����Ѱ����һ���ַ�Ϊ1�ĸ���*/
				hasPath = hasPathCore(matrix, rows, cols, row, col - 1, endX, endY, visited,Path) || //�����ǵݹ� ��hasPath������
				          hasPathCore(matrix, rows, cols, row - 1, col, endX, endY, visited,Path) ||
				          hasPathCore(matrix, rows, cols, row, col + 1, endX, endY, visited,Path) ||
				          hasPathCore(matrix, rows, cols, row + 1, col, endX, endY, visited,Path);    //��ν���Ѿ��߹��Ĳ��߻�ͷ·�� �����ܻ���һ�����㣿��֮ǰ�����Ǹ���
				if (!hasPath)               //���û�ҵ�����˵����ǰ��n�����Ӷ�λ����ȷ��������һ��λ�����¶�λ
				{
					//   visited[row*cols + col] = false;
					Path.pop_back();
					Path.pop_back();
				}
			}
			return hasPath;   //������� Ϊʲôֵ���޸ģ�
		}
};

bool hasPath(char* matrix, int rows, int cols,
			 int startX,int startY, int endX, int endY,vector<int>& Path)
{
			if (matrix == NULL || rows < 1 || cols < 1 || 
					startX<0||startY<0||endX<0||endY<0||(startX==endX&&startY==endY))
				return false;
				//����һ�����������������·���Ƿ��Ѿ�������ÿ������
			bool* visited = new bool[rows*cols];
			memset(visited, 0, rows*cols);    //����ռ�
			int pathLength = 0;
			if (hasPathCore(matrix, rows, cols, startX, startY, endX, endY, visited, Path))
			{
				return true;
			}
			delete[] visited;
			return false;
		}

class Point
{
public:
	int x;
	int y;
};

int main()
{
	// char* matrix = "abcesfcsadee";
	char matrix[] = "1000000110110001101000010111011110100000010000001";    //�����Թ�
	Point start,end;
	cin >> start.x >> start.y >> end.x >> end.y;                  //������ʼ��������
	Solution s;
	vector<int> Path; //path ��ô��push pop�ȹ�����
	bool re = s.hasPath(matrix, 7, 7, start.x, start.y, end.x, end.y, Path);
	cout << re << endl;
	for (int i = 0; i < Path.size();)
		cout << "(" << Path[i++] << ',' << Path[i++] << ")" << " ";
	cout << endl;
	return 0;
}

