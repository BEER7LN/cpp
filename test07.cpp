//
// Created by ASUS on 2019/12/16.
//
#include <iostream>
#include <cstring>
#include <queue> //用队列来保存两种遍历的结果

#define maxn 10000 //定义最大值
#define INF 0x3f3f3f3f
using namespace std;

int n,m; //节点数、边数
int startdata[maxn]; //各结点
bool havaEdge[maxn]; //判断边是否存在
int edge[maxn][maxn]; //二维数组存储边的起始、终点和权重
queue<int> answer;

void addEdge(int starttage,int endtage,int we) { //建立各边、保存权重
    edge[starttage][endtage] = we;
    edge[endtage][starttage] = we;
}

void create() {
    memset(havaEdge,false,sizeof(havaEdge));
    memset(startdata,INF,sizeof(startdata));
}

void DFS(int a) { //深度优先搜索遍历
    queue<int> temp;
    temp.push(a);
    while(!temp.empty()) { //队列非空时
        int start = temp.front();
        temp.pop();
        for(int i = 1; i <= n; i++) {
            if(startdata[start] + edge[start][i] < startdata[i]) {
                startdata[i] = startdata[start] + edge[start][i];
                if(havaEdge[i] == false){
                    temp.push(i);
                    answer.push(i);
                    havaEdge[i] = true;
                }
            }
        }
    }
}

void BFS(int a) { //广度优先搜索遍历
    for(int i = 1; i <= n; i++) {
        if(startdata[a] + edge[a][i] < startdata[i]) {
            startdata[i] = startdata[a] + edge[a][i];
            if(havaEdge[i] == false) {
                answer.push(i);
                havaEdge[i] = true;
            }
            BFS(i);
        }
    }
}

int main() {
    memset(edge,INF,sizeof(edge));
    create();
    cout << "Input" << endl;
    char c; //输入时以c为分隔符
    cin >> n >> c >> m;
    for(int i = 0; i < m; i++) { //读入m条边的相关信息
        int start,end,weight;
        cin >> start >> c >> end >> c >> weight;
        addEdge(start,end,weight);
    }

    cout << "Output" << endl;
    startdata[1] = 0;
    DFS(1);
    cout << "1" <<",";
    while( !answer.empty()) {
        cout << answer.front();
        answer.pop(); //队列出栈
        if( !answer.empty()) {
            cout << ",";
        }
    }
    cout <<'\n';

    create();
    startdata[1] = 0;
    BFS(1);
    cout << "1" <<",";
    while(!answer.empty()) {
        cout << answer.front();
        answer.pop(); //队列出栈
        if( !answer.empty()) {
            cout << ",";
        }
    }
    cout <<'\n';

    if( startdata[n] != INF) { //最短路径长度
        cout << startdata[n];
    }
    else {
        cout << "0";
    }
    cout <<'\n';
    cout << "End";
    return 0;
}

