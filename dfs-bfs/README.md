# 깊이 우선 탐색, 너비 우선 탐색

두 탐색은 모든 정점을 한번만 방문한다는 같은 목표를 가지고 있지만, 그 과정에서 탐색하는 방식의 차이가 있다.

<br>


### **DFS**

DFS의 기본 작동 방식은 stack을 이용해서 갈 수 있는 만큼 최대한 깊이 가고, 더 이상 갈 곳이 없다면 이전 정점으로 돌아간다는 것이다.

stack과 recursive function을 이용하여 구현한다.

<br>

### **BFS**

BFS의 기본 작동 방식은 queue를 이용하여 지금 위치에서 갈 수 있는 것들을 모두 큐에 넣는 방식이다. 이때, queue에 넣을 시점에 해당 노드를 방문했다고 체크해야 한다. (DFS는 일단 들어가서 체크함)

BFS는 queue와 while loop을 이용하여 구현한다.