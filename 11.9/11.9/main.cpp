#include <vector>
#include <iostream>
#include <stack>
#include <fstream>
#include <algorithm>

using namespace std;

typedef pair<__int64, __int64> PairInt64;

long double FindLength(const PairInt64 &p1, const PairInt64 &p2);
long double CheckCoords(const PairInt64 &p1, const PairInt64 &p2, const PairInt64 &p3);

struct CompareCoords
{
	PairInt64 p;
	CompareCoords(PairInt64 p)
	{
		this->p = p;
	}

	bool operator()(const PairInt64 &p1, const PairInt64 &p2)
	{
		long double coords = CheckCoords(p, p1, p2);
		if (coords > 0 || (coords == 0 && FindLength(p, p1) < FindLength(p, p2)))
		{
			return true;
		}
		return false;
	}
};

long double CheckCoords(const PairInt64 &p1, const PairInt64 &p2, const PairInt64 &p3)
{
	return ((p2.first - p1.first) * (p3.second - p1.second) * 1.0 - (p2.second - p1.second) * (p3.first - p1.first) * 1.0);
}

long double FindLength(const PairInt64 &p1, const PairInt64 &p2)
{
	return sqrt((p2.first - p1.first) * (p2.first - p1.first) * 1.0 + (p2.second - p1.second) * (p2.second - p1.second) * 1.0);
}

void WriteInFile(vector<PairInt64>  const &convexHull)
{
	ofstream fout("output.txt");
	if (fout.is_open())
	{
		fout << convexHull.size() << endl;
		for (auto &it : convexHull)
		{
			fout << it.first << " " << it.second << endl;
		}
	}
}

void CheckCoord(vector<PairInt64> &convexHull, vector<PairInt64> &coords)
{
	
	convexHull.push_back(coords[0]);
	if (coords.size() > 1)
	{
		convexHull.push_back(coords[1]);
		for (int i = 2; i < coords.size(); i++)
		{
			while (convexHull.size() > 1 && CheckCoords(convexHull[convexHull.size() - 2], convexHull[convexHull.size() - 1], coords[i]) <= 0)
			{
				convexHull.pop_back();
			}
			convexHull.push_back(coords[i]);
		}
	}
}

void GetCoordFromFile(vector<PairInt64> &coords)
{
	ifstream fin("input.txt");
	if (fin.is_open())
	{

		int N;
		fin >> N;
		int f = 0;
		for (int i = 0; i < N; i++)
		{
			__int64 x = 0, y = 0;
			fin >> x >> y;
			PairInt64 p = { x, y };
			coords.push_back(p);
			if (coords[f].second > p.second || (coords[f].second == p.second && coords[f].first > p.first))
			{
				f = i;
			}
		}
		swap(coords[0], coords[f]);
		sort(coords.begin() + 1, coords.end(), CompareCoords(coords[0]));
	}
}

int main()
{
	vector<PairInt64> coords;
	GetCoordFromFile(coords);
	vector<PairInt64> convexHull;
	CheckCoord(convexHull, coords);
	WriteInFile(convexHull);
	return 0;
}