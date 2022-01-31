#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;
const int INF = 1e9;

int N, M, A, B, K, G;

int adjMatrix[MAX][MAX];
int timeGeorgeEnters[MAX][MAX];
int georgeVisits[MAX];
int dist[MAX];
int visited[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> A >> B >> K >> G;
    A--; B--; // convert to 0-indexed

    // initialize matrices
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            adjMatrix[i][j] = timeGeorgeEnters[i][j] = INF;
        }
    }

    // read in places george visits
    for (int i = 0; i < G; i++) {
        cin >> georgeVisits[i];
        georgeVisits[i]--; // convert to 0-indexed
    }

    // read edges
    for (int i = 0; i < M; i++) {
        int u, v, dist; cin >> u >> v >> dist;
        u--; v--; // convert to 0-indexed
        adjMatrix[u][v] = dist;
        adjMatrix[v][u] = dist;
    }

    // O(1) access to if george visits some street at some point in time
    for (int i = 1, t = 0; i < G; i++) {
        int georgeU = georgeVisits[i-1];
        int georgeV = georgeVisits[i];
        timeGeorgeEnters[georgeU][georgeV] = t;
        timeGeorgeEnters[georgeV][georgeU] = t;
        t += adjMatrix[georgeU][georgeV];
    }

    // initialize stuff for djikstra's
    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[A] = K;

    // djikstra's all nodes only need to be relaxed once
    for (int i = 0; i < N; i++) {
        int m = -1;
        // find the node with the smallest distance
        for (int j = 0; j < N; j++) {
            if (visited[j]) continue;
            if (m == -1 || dist[j] < dist[m]) m = j;
        }
        // cout << "relax " << m << endl;
        visited[m] = 1;

        // relax all outgoing nodes
        for (int j = 0; j < N; j++) {
            if (dist[m] < timeGeorgeEnters[m][j]) {
                // if we enter before george does, just do as per normal
                dist[j] = min(dist[j], dist[m] + adjMatrix[m][j]);
            } else {
                // otherwise, possibly override the distance to m with time george leaves
                int distToM = max(timeGeorgeEnters[m][j] + adjMatrix[m][j], dist[m]);
                dist[j] = min(dist[j], distToM + adjMatrix[m][j]);
            }
        }
    }

    cout << dist[B] - dist[A] << endl;
}