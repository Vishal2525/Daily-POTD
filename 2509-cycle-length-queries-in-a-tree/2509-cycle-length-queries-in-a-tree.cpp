class Solution {
public:

    // depth of node in complete binary tree
    int getDepth(int node) {
        return 31 - __builtin_clz(node);
    }


    // 2^j-th ancestor of node
    int getKthParent(int node, int j) {

        int jump = (1 << j);

        return node >> jump;
    }


    int LCA(int u, int v, int n) {

        int depthU = getDepth(u);
        int depthV = getDepth(v);

        int col = log2(n) + 1;


        // make u the deeper node
        if (depthU < depthV) {

            swap(u, v);
            swap(depthU, depthV);
        }


        // depth difference
        int k = depthU - depthV;


        // bring u at same depth as v
        for (int j = 0; j < col; j++) {

            if (k & (1 << j)) {

                u = getKthParent(u, j);
            }
        }


        // v was ancestor of u
        if (u == v)
            return u;


        // move u and v upward together
        for (int j = col - 1; j >= 0; j--) {

            int parentU = getKthParent(u, j);
            int parentV = getKthParent(v, j);


            if (parentU == 0 || parentV == 0)
                continue;


            if (parentU != parentV) {

                u = parentU;
                v = parentV;
            }
        }


        // direct parent is LCA
        return u / 2;
    }


    vector<int> cycleLengthQueries(
        int n,
        vector<vector<int>>& queries
    ) {

        vector<int> ans;


        for (auto &q : queries) {

            int u = q[0];
            int v = q[1];


            // find LCA
            int lca = LCA(u, v, n);


            // distance between u and v
            int d =
                getDepth(u)
                + getDepth(v)
                - 2 * getDepth(lca);


            // +1 for newly added edge
            ans.push_back(d + 1);
        }


        return ans;
    }
};