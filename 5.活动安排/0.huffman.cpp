/*************************************************************************
	> File Name: huffman.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年11月03日 星期日 22时22分56秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;

struct Node {
    Node(char ask, int val) : ask(ask), val(val) {
        l = r = f = NULL;
        cnt = 0;
    }
    bool operator<(const Node &a) const {
        if (val - a.val) return val < a.val;
        if (ask - a.ask) return ask < a.ask;
        return cnt - a.cnt;
    }
    int val;
    char ask;
    int cnt;
    struct Node *l, *r, *f;
};

Node *huffman(set<Node> &s, map<char, int> &m, set<Node*> &v) {
    int cnt = 0;
    for (auto iterator = m.begin(); iterator != m.end(); iterator++) {
        //cout << __LINE__ << endl;
        //cout << ++cnt << endl;
        s.insert(Node(iterator->first, iterator->second));
        //cout << iterator->first << " " << iterator->second << endl;
    }
    //cout << endl;
    //cout << cnt  << endl;
    //cout << __LINE__ << endl;
    while (s.size() > 1) {
        Node p(s.begin()->ask, s.begin()->val);
        //cout << s.begin()->ask << " " << s.begin()->val << endl;
        p.l = s.begin()->l;
        p.r = s.begin()->r;
        if (p.l == NULL) {
            v.insert(&p);
        } else {
            s.begin()->l->f = &p;
            s.begin()->r->f = &p;
        }
        s.erase(s.begin());
        Node q(s.begin()->ask, s.begin()->val);
        //cout << s.begin()->ask << " " << s.begin()->val << endl;
        q.l = s.begin()->l;
        q.r = s.begin()->r;
        if (q.l == NULL){
            v.insert(&q); 
        } else {
            s.begin()->l->f = &q;
            s.begin()->r->f = &q;
        }
        s.erase(s.begin());
        Node fa('0', p.val + q.val);
        fa.cnt = ++cnt;
        fa.l = &p;
        fa.r = &q;
        s.insert(fa);
        //cout << "size" << " " << s.size() << endl;
        //cout << fa.ask << " " << fa.val << endl << endl;
    }
    Node head(s.begin()->ask, s.begin()->val);
    s.begin()->l->f = &head;
    s.begin()->r->f = &head;
    head.l = s.begin()->l;
    head.r = s.begin()->r;
    s.erase(s.begin());
    Node *h = &head;
    return h;
}

void code_init(Node *head, map<char, string> &code, set<Node*> &v) {
    int cnt = 0;
    while (v.size()) {
        Node *p, *q;
        string tmp;
        p = *v.begin();
        v.erase(v.begin());
        cout << endl << "---" << p->ask << "---" << endl;
        code[p->ask] = "";
        int t = 0;
        while (p->f != NULL) {
            printf("%c\n", p->ask);
            cout << p->ask << "高度" << t++ << endl;
            q = p;
            p = p->f;
            if (p->l == q) {
                tmp = "1";
                code[p->ask] = tmp + code[p->ask];
            } else {
                tmp = "0";
                code[p->ask] = tmp + code[p->ask];
            }
            cout << "+" << tmp << endl;
        }
        cout << p->ask << "编码" << code[p->ask] << endl;
    }
    return ;
}

set<Node> s;
map<char, int> m;
set<Node*> v;
map<char, string> code;

int main() {
    char ch;
    cout << endl << "样本读入" << endl;
    int cnt = 0;
    while (scanf("%c", &ch) != EOF) {
        if ((int)ch < 'a' || (int)ch > 'z') continue;
        m[ch] += 1;
        //if (m[ch] == 1) cout << ch << endl;
        cnt++;
    }
    cout << "sum " << cnt << endl;
    cout << endl << "哈夫曼树生成" << endl;
    Node *head = huffman(s, m, v);
    cout << endl << "编码生成" << endl;
    code_init(head, code, v);
    cout << endl << "编码输出" << endl;
    for (auto iterator = code.begin(); iterator != code.end(); iterator++) {
        cout << iterator->first << "::" << iterator->second << endl;
    }
    cout << "over" << endl;
    //file_to_code(ret);
    //code_to_file(ret);
    return 0;
}
