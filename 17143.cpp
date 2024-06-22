#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Shark
{
public:
	static map<int, Shark*> sizeShark_map;
	pair<int, int> pos;
	int speed;
	int direction;
	int size;
	Shark(int y, int x, int s, int d, int z) :pos({ y,x }), speed(s), direction(d), size(z) { sizeShark_map[z] = this; }
	void update(vector<vector<int>>& board_vec, int r, int c)
	{
		//이전 발판 초기화
		if (board_vec[pos.first][pos.second] == size)
			board_vec[pos.first][pos.second] = -1;
		for (int i = 0; i < speed; ++i)
		{	//방향에 따른 이동
			switch (direction)
			{
			case 1:
				if (pos.first == 0) { direction = 2; i--; }
				else pos.first -= 1;
				break;
			case 2:
				if (pos.first == r - 1) { direction = 1; i--; }
				else pos.first += 1;
				break;
			case 3:
				if (pos.second == c - 1) { direction = 4;  i--; }
				else pos.second += 1;
				break;
			case 4:
				if (pos.second == 0) { direction = 3;  i--; }
				else pos.second -= 1;
				break;
			}
		}
		//도착한 발판에 있는 작은 상어 제거
		int target = board_vec[pos.first][pos.second];
		if (target != -1 && target < size) sizeShark_map.erase(target);
		board_vec[pos.first][pos.second] = size;
	}
};
map<int, Shark*> Shark::sizeShark_map;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int r, c, m; cin >> r >> c >> m;
	vector<vector<int>> board_vec(r, vector<int>(c, -1));
	for (int i = 0; i < m; ++i)
	{
		int y, x, s, d, z; cin >> y >> x >> s >> d >> z;
		y--; x--;
		if (d == 3 || d == 4) s %= (2 * c - 2);
		else s %= (2 * r - 2);
		new Shark(y, x, s, d, z);
		board_vec[y][x] = z;
	}
	int cnt = -1;
	int answer = 0;
	while (cnt++ < c-1)
	{
		for (int i = 0; i < r; ++i)
		{
			if (board_vec[i][cnt] == -1) continue;
			int size = board_vec[i][cnt];
			answer += size;
			Shark::sizeShark_map.erase(size);
			board_vec[i][cnt] = -1;
			break;
		}

		for (auto& sharkData : Shark::sizeShark_map)
			sharkData.second->update(board_vec, r, c);

	}
	cout << answer;
}