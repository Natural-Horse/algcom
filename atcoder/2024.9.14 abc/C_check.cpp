#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;
    
    int MG;
    std::cin >> MG;
    
    std::vector G(N, std::vector(N, 0));
    for (int i = 0; i < MG; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        G[u][v] = 1;
        G[v][u] = 1;
    }
    
    int MH;
    std::cin >> MH;
    
    std::vector H(N, std::vector(N, 0));
    for (int i = 0; i < MH; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        H[a][b] = 1;
        H[b][a] = 1;
    }
    
    std::vector<int> p(N);
    std::iota(p.begin(), p.end(), 0);
    
    std::vector A(N, std::vector(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            std::cin >> A[i][j];
        }
    }
    
    int ans = 1E9;
    do {
        int res = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (H[i][j] != G[p[i]][p[j]]) {
                    res += A[i][j];
                }
            }
        }
        ans = std::min(ans, res);
    } while (std::next_permutation(p.begin(), p.end()));
    
    std::cout << ans << "\n";
    
    return 0;
}