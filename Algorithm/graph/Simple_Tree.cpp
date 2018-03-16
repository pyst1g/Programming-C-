struct Simple_Tree {
    vector<int> node;
    vector<int> parent;
    vector<int> height;

    Simple_Tree(int n) : node(n), parent(n), height(n) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    // 高さの更新 O(N)
    void update_height() {
        height = vi(height.size(), 0); //この0は再帰の部分で生きるので変えてはいけない
        for (int i = 0; i < height.size(); i++) update_height_memo(i);
    }

    int update_height_memo(int i) {
        if (height[i] != 0) return height[i];
        if (i == parent[i]) {
            height[i] = 0;
            return height[i];
        }
        height[i] = update_height_memo(parent[i]) + 1;
    }


    void make_edge(int a, int b) {
        parent[b] = a;
    }
};
