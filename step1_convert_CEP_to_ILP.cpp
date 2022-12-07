#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

FILE *infile, *outfile;

int g[630][630];
int edge[630][630];
int a[630][630];
int conflict[1000000][3], con_num;

int main(){
	
	char infilename[18] = {'e','x','a','c','t','/','e','x','a','c','t','0','0','1','.','g','r',0};
	char outfilename[12] = {'I','L','P','/','0','0','1','.','t','x','t',0};
	
	for(int file = 1; file <= 200; file++) {
		memset(g, -1, sizeof(g));
		memset(edge, 0, sizeof(edge));
		memset(a, 0, sizeof(a));
		con_num = 0;
		infilename[11] = outfilename[4] = '0' + (file / 100);
		infilename[12] = outfilename[5] = '0' + (file % 100 / 10);
		infilename[13] = outfilename[6] = '0' + (file % 10);
		infile = fopen(infilename, "r");
		outfile = fopen(outfilename, "w");
		char c[10];
		int n, m;
		fscanf(infile, "%s", c);
		fscanf(infile, "%s", c);
		fscanf(infile, "%s", c);	n = atoi(c);
		fscanf(infile, "%s", c);	m = atoi(c);
		for(int i = 1; i <= m; i++) {
			int u, v;
			fscanf(infile, "%s", c);	u = atoi(c);
			fscanf(infile, "%s", c);	v = atoi(c);
			g[u][v] = 1;
			g[v][u] = 1;
			edge[u][++edge[u][0]] = v;
			edge[v][++edge[v][0]] = u;
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++)
			for(int j = i+1; j <= n; j++)
				a[i][j] = a[j][i] = ++cnt;
		for(int x = 1; x <= n; x++) {
			for(int i = 1; i <= edge[x][0]; i++)
				for(int j = i+1; j <= edge[x][0]; j++) {
					int y = edge[x][i], z = edge[x][j];
					if(g[y][z] == -1) {
						conflict[++con_num][0] = a[x][y];
						conflict[con_num][1] = a[x][z];
						conflict[con_num][2] = a[y][z];
					}
				}
		}
		fprintf(outfile, "%d %d %d\n", n, cnt, con_num);
		for(int i = 1; i <= n; i++)
			for(int j = i+1; j <= n; j++)
				fprintf(outfile, "%d ", -g[i][j]);
		fprintf(outfile, "\n");
		for(int i = 1; i <= con_num; i++)
			fprintf(outfile, "%d %d %d\n", conflict[i][0], conflict[i][1], conflict[i][2]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				fprintf(outfile, "%d ", -g[i][j]);
			fprintf(outfile, "\n");
		}
		fprintf(outfile, "\n");
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++)
				fprintf(outfile, "%d ", a[i][j]);
			fprintf(outfile,"\n");
		}
	}
	return 0;
} 
