#include <stdio.h>

int* spirallyTraverse(int r, int c, int a[][c])
{   
    int *res = malloc(sizeof(int) * (r * c));
    int temp=0,up=0,left=0,dir=0;
    while(up<r && left<c)
    {
        for(int j=left;j<=c-1;j++)
        {
            res[temp++]=a[up][j];
        }
        up++;
        for(int i=up;i<=r-1;i++)
        {
            res[temp++]=a[i][c-1];
        }
        c--;
        if(up<r)
        {
            for(int j=c-1;j>=left;j--)
            {
                res[temp++]=a[r-1][j];
            }
            r--;
        }
        if(left<c)
        {
            for(int i=r-1;i>=up;i--)
            {
                res[temp++]=a[i][left];
            }
            left++;
        }
    }
    return res;
    
}

// { Driver Code Starts.

int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int r, c;
		scanf("%d", &r);
		scanf("%d", &c);
		int matrix[r][c];
	 
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				scanf("%d", &matrix[i][j]);
			}
		}
		
		int *result = spirallyTraverse(r, c, matrix);
		for(int i = 0; i < r*c; i++)
			printf("%d ", result[i]);
		printf("\n");
	}
	return 0;
} 