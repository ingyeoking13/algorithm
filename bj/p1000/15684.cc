#include <stdio.h>

bool edge[11][31];
bool newEdge[11][31];

bool go(int mycol, int mxrow, int mxcol)
{
	int col = mycol, row = 1;
	while (row <= mxrow)
	{
		if (edge[col][row]) col++, row++;
		else if (newEdge[col][row]) col++, row++;
		else if (col != 1 && (edge[col - 1][row] || newEdge[col - 1][row])) col--, row++;
		else row++;
	}
	return mycol == col;
}

bool chk_valid(int mxcol, int mxrow)
{
	for (int i = 1; i <= mxcol; i++)
	{
		if (go(i, mxrow, mxcol));
		else return false;
	}
	return true;
}

bool build_i_and_chk_valid(int newEdgeNum, int mxcol, int mxrow, int col, int row)
{
	if (newEdgeNum ==0 || row > mxrow)
	{
		return chk_valid(mxcol, mxrow);
	}
	if (col > mxcol)
	{
		return build_i_and_chk_valid(newEdgeNum, mxcol, mxrow, 1, row+1);
	}

	if (
		newEdgeNum > 0 &&
		(col == 1 || edge[col - 1][row] == 0) &&
		(col == mxcol || edge[col + 1][row] == 0) &&
		edge[col][row] == 0 &&
		(col == 1 || newEdge[col - 1][row] == 0) &&
		(col == mxcol || newEdge[col + 1][row] == 0) &&
		newEdge[col][row] == 0
		)
	{
		newEdge[col][row] = 1;
		if (build_i_and_chk_valid(newEdgeNum - 1, mxcol, mxrow, col+1, row)) return 1;
		newEdge[col][row] = 0;
	}
	if (build_i_and_chk_valid(newEdgeNum, mxcol, mxrow, col+1, row)) return 1;

	return 0;
}

bool go_with_i_added(int newEdgeNum, int mxcol, int mxdepth)
{
	return build_i_and_chk_valid(newEdgeNum, mxcol, mxdepth, 1, 1);
}

int answer(int mxcol, int mxdepth)
{
	for (int i = 0; i <= 3; i++)
	{
		if (go_with_i_added(i, mxcol, mxdepth)) return i;
	}
	return -1;
}

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	for (int i = 0; i < m; i++)
	{
		int row, col;
		scanf("%d%d", &row, &col);
		edge[col][row] = 1;
	}
	printf("%d\n", answer(n, k));
}