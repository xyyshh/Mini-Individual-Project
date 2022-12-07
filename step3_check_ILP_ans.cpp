#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

FILE *infile, *outfile;

int a[400000];
int g[620][620];

int main(){
	
	char infilename[16] = {'I','L','P','_','a','n','s','/','0','0','1','.','t','x','t',0};
	char outfilename[15] = {'r','e','s','u','l','t','/','0','0','1','.','t','x','t',0};
	
	for(int file = 1; file <= 200; file++) {
		memset(a, 0, sizeof(a));
		memset(g, 0, sizeof(g));
		infilename[8] = outfilename[7] = '0' + (file / 100);
		infilename[9] = outfilename[8] = '0' + (file % 100 / 10);
		infilename[10] = outfilename[9] = '0' + (file % 10);
		infile = fopen(infilename, "r");
		outfile = fopen(outfilename, "w");
		char c[10];
		int n;
		fscanf(infile, "%s", c);	n = atoi(c);
		for(int i = 1; i <= n*(n-1)/2; i++) {
			fscanf(infile, "%s", c);
			a[i] = atoi(c);
		}
		int tt = 1;
		for(int i = 1; i <= n; i++) {	
			for(int j = i + 1; j <= n; j++)
				g[i][j] = a[tt++];
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= i; j++)
				g[i][j] = g[j][i];
		}
		for(int i = 1; i <= n; i++)
			g[i][i] = 1;
		fprintf(outfile, "%d\n", n);
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++)
				fprintf(outfile, "%d ", g[i][j]);
			fprintf(outfile, "\n");
		}
	}
	return 0;
} 
