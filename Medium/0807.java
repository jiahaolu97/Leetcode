class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int[] horizon = new int[grid.length];
        int[] vertical = new int[grid.length];
        for(int i=0;i<grid.length;i++){
        	int h = 0;
        	for(int j=0;j<grid.length;j++){
        		if(grid[i][j]>h) h = grid[i][j];
        	}
        	horizon[i] = h;
        }
        for(int i=0;i<grid.length;i++){
        	int v = 0;
        	for(int j=0;j<grid.length;j++){
        		if(grid[j][i]>v) v = grid[j][i];
        	}
        	vertical[i] = v;
        }
        int cnt = 0;
        for(int i=0;i<grid.length;i++){
        	for(int j=0;j<grid.length;j++){
        		int max = Math.min(vertical[j],horizon[i]);
        		cnt += max-grid[i][j];
        	}
        }
        return cnt;
    }
}
