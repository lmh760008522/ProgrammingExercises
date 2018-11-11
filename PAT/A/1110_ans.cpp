#include <cstdio>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
struct TREE {
    int left;
    int right;
};
int main() {
    int n, root = 0;
    scanf("%d", &n);
    vector<TREE> tree(n);
    vector<int> book(n);
    for(int i = 0; i < n; i++) {
        char l[3], r[3];
        scanf("%s %s", l, r);
        if(l[0] == '-') {
            tree[i].left = -1;
        } else {
            int temp = l[0] - '0';
            if(strlen(l) == 2) {
                temp = temp * 10 + (l[1] - '0');
            }
            tree[i].left = temp;
        }
        if(r[0] == '-') {
            tree[i].right = -1;
        } else {
            int temp = r[0] - '0';
            if(strlen(r) == 2) {
                temp = temp * 10 + (r[1] - '0');
            }
            tree[i].right = temp;
        }
        if(tree[i].left != -1)
            book[tree[i].left] = 1;
        if(tree[i].right != -1)
            book[tree[i].right] = 1;
    }
    for(int i = 0; i < n; i++) {
        if(book[i] == 0) {
            root = i;
            break;
        }
    }
    queue<int> q;
    q.push(root);
    int cnt = 0;
    int lastnode = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        if(node != -1) {
            lastnode = node;
            cnt++;
        }else {
            if(cnt != n)
                printf("NO %d", root);
            else
                printf("YES %d", lastnode);
            return 0;
        }
        q.push(tree[node].left);
        q.push(tree[node].right);
    }
    return 0;
}
