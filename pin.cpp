#include <fstream>
#include <cstring>
using namespace std;
bool prim(int);
int main()
{
	ifstream f("pin.in");
	int k, p;
	f >> k >> p;
	f.close();
	bool uz[10];
	memset(uz, 0, sizeof(uz));
	uz[k] = uz[p] = 1;
	int c;
	for (c = 9; uz[c]; c--);
	int nr = c*1000;
	for (c = 9; uz[c]; c--);
	nr = nr + c*100 + c*10 + c;
	bool ok;
	do
	{
		ok = 0;
		if (prim(nr))
		{
			memset(uz, 0, sizeof(uz));
			int aux = nr;
			while (aux)
			{
				uz[aux%10] = 1;
				aux /= 10;
			}
			if (!uz[k] && !uz[p]) ok = 1;
		}
		if (!ok)
			nr = nr%2 ? nr-2 : nr-1;
	} while (!ok);
	ofstream g("pin.out");
	g << nr;
	g.close();
	return 0;
}
bool prim(int n)
{
	if (n == 1) return 0;
	if (n == 2) return 1;
	if (n%2 == 0) return 0;
	for (int d = 3; d*d <= n; d += 2)
		if (n%d == 0) return 0;
	return 1;
}
